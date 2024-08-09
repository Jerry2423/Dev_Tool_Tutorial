## GDB Tutorial

## Table of Contents
- [Getting Started](#getting-started)
- [Basic Commands](#basic-commands)
- [TUI Mode](#tui-mode)
- [Tricks](#tricks)
- [Debug Strategies](#debug-strategies)
    - [Stackframe Navigation](#stackframe-navigation)
    - [Program Crash](#program-crash)
    - [Infinite Loop](#infinite-loop)
    - [Inconsistent Behabiour](#inconsistent-behabiour)

### Getting Started
- Compile Command - `gcc -Wpedantic -Wall -Wextra -Wvla -std=c11 -ggdb -o [EXE_NAME].out [FILE_NAME].c `
- Start GDB - `gdb [EXE_NAME].out`

### Basic Commands
[gdb Reference Card](https://web.stanford.edu/class/cs107/resources/gdb_refcard.pdf)

Here is a full list of the commands you'll want to be familiar with. For even more, check out the reference card at the top of this page.

| Command             | Abbreviation     | Description                                                  |
| :------------------ | :--------------- | :----------------------------------------------------------- |
| `help [command]` (ask for help)   | `h [command]`    | Provides help (information) about a particular command or keyword. |
| `apropos [command]` | `appr [command]` | Same as `help`                                               |
| `info [cmd]` (view global picture)       | `i [cmd]`        | Provides information about your program, such as the breakpoints (`info breakpoints`, local variables (`info locals`), parameters (`info args`), breakpoint numbers (`info break`), etc. |
| `run [args]`        | `r [args]`       | The `run` command runs your program. You can enter command line arguments after the command, if your program requires them. If you are already running your program and you want to re-run it, you should answer `y` to the prompt that says, "The program being debugged has been started already. // Start it from the beginning? (y or n)" |
| `list`              | `l`              | The `list` command lists your program code either from the beginning, or with a range around where you are currently stopped. |
| `next`              | `n`              | The `next` command steps to the next program line and *completely runs functions*. This is important: if you have a function (even one you didn't write) and you use `next`, the function will run to completion, and will stop at the next line after the function (unless there is a breakpoint inside the function). |
| `step`              | `s`              | The `step` command is similar to `next`, but it will step into functions. This means that it will attempt to go to the first line in a function if there is a function called on the current line. Importantly, it will also take you into functions you didn't write (such as `printf`), which can be annoying (you should use `next` instead). If you do accidentally step into a function, you can use the `finish` command to finish the function immediately and go back to the next line after the function. |
| `continue` (go to multiple lines)         | `c`              | This will continue running the program until the next breakpoint or until the program ends. |
| `print [x]`         | `p [x]`          | This very important command lets you see the value of a variable [x] when you are stopped in a program. If you see the error "No symbol xxxx in current context", or the error, "optimized out", you probably aren't in a place in the program where you can read the variable. |
| `break [x]`         | `b [x]`          | This will put a breakpoint in the program at a specified function name or a particular line number. If you have multiple files, you should use `file:lineNum` when specifying the line number (e.g. `source.c:57`). |
| `clear [x]`         |                  | Removes the breakpoint at a specified line number or at the start of the specified function. |
| `delete [x]`        |                  | Removes the breakpoint with the given number. If the number is omitted, deletes all breakpoints after confirming. |
| `backtrace`         | `bt`             | This will print a stack trace to let you know where in the program you are currently stopped. This is a useful command if your program has a segmentation fault: the `backtrace` command will tell you the last place in your program that had the problem (sometimes you need to look at the entire stack trace to go back to the last line your program tried to execute). |
| `where`            | `w`              | Same as `backtrace`                                           |
| `up` and `down`     |                  | These commands allow you to go up and down the stack trace. For instance, if you are inside a function and want to see the status of variables from the calling function, you can use `up` to place the program into the calling function, and then use `p variable` to look at the state of the program in that function. You would then use `down` to go back to the function that was called. |
| `finish`            |                  | Runs a function until it completes, which is helpful if you accidentally step into a function. |
| `disassemble` (check assembly code)      | `disas`          | Disassembles your program into assembly language. We will be discussing this in depth in cs107. |
| `ctrl-x, ctrl-a`    |                  | Go into or leave ["TUI"](https://sourceware.org/gdb/onlinedocs/gdb/TUI.html#TUI) mode: `gdb` has a mode that shows you source code, or assembly output in a manner that allows you to scroll up and down. It is useful but sometimes can be a bit buggy. You will want to use the `ctrl-l` command to refresh the display. |
| `quit`              | `q`              | Quit `gdb`                                                   |

### TUI Mode
- Open TUI Mode - `ctrl-x, ctrl-a` / `tui enable`, `tui disable`
- Switch layout - `ctrl-x, ctrl-x` / `layout next (n)`, `layout prev`
- Refresh - `ctrl-l` (screen somtimes gets messed up, use it to refresh)
- Switch focus (where arrow can be controlled) - `focus cmd`, `focus src`, `focus asm`, `focus regs` / `focus next`, `focus prev`
- `nexti` / `ni` - next instruction (in assembly)


### gdb `x` command
- `x` command is used to examine memory
- `x/[format] [address]` - examine memory at `address` with `format`
- `[format]` consist of `nuf`:
    - `n` - number of units to display
    - `u` - unit size (b, h, w, g for byte, halfword (2 bytes), word (4 bytes), giantword (8 bytes))
    - `f` - display format (x for hex, d for decimal, u for unsigned decimal, o for octal, t for binary, a for address, i for instruction)
- Example: For an array `int a[5]`, examine the first 3 elements in hex format: `(gdb) x/3wd a`
    - `3` - number of units
    - `w` - unit size because `int` is 4 bytes
    - `d` - display format in decimal because we want to see the value of the array elements and the type of the value is `int`

### Tricks 
- keyboard shortcuts
    | Command             | Description                                                  |
    | :------------------ | :----------------------------------------------------------- |
    | `ctrl-x, ctrl-a`    | Go into or leave TUI mode                                    |
    | `enter`             | Repeat the last command                                      |
- print array
    - `p *array@size` - print the first `size` elements of `array`
- accidentally step over a line of code: 
    1. set the breakpoint at the line `n` you want to step into 
    2. `run` again
    3. now you can `step` into the function 

### Debug Strategies
Referenced from [CS107 Debugging Guide](https://web.stanford.edu/class/cs107/resources/debugging)

1. **Observe the bug.** *"What makes me think there is a problem?"*

2. **Create a reproducible input.** *"How can I reliably reproduce this problem?"* You want the *smallest, simplest* test case possible that reproduces the bug. The smaller it is, the quicker you will be able to debug it.

3. Narrow the search space.

   "How can I narrow down to the code that could cause this problem?"

   Tracing through the whole program is not feasible. Instead, consider:

   - Using your **intuition** as a starting point. Did you change a function recently? Are there any likely culprits?
   - Using **"binary search"**. Set a breakpoint halfway through your program. If the state is already incorrect, investigate the code before that line. Otherwise, focus your attention on the code that follows. Repeat to further narrow down.
   - Investigating memory errors. Run under Valgrind; does it point out any issues?
   - Investigating crashes. Run under GDB to let the program crash, and use commands like `backtrace` and `print` to gather information.

4. **Analyze.** *"What information can I gather from this identified code?"* Now trace through its execution with GDB. Inspect the values of variables and flow of control, and draw pictures.

5. **Devise and run experiments.** *"How can I check my hypotheses about the issue?"* Make inferences about the root cause and run experiments to validate your hypothesis. Iterate until you identify the root cause.

6. **Modify code to squash the bug**. *"How can I fix the issue, and confirm that the fix works?"* The fix should be validated by your experiments and passing the original failed test case. You should be able explain the series of facts, tests, and deductions which match the observed symptom to the root cause and the corrected code.

**Do not change your code haphazardly - change small -> test -> change small ->...** As a scientist, you should change only one variable at a time while experimenting. This ensures you can fully understand the program behavior and causes at every step.

**Good style means easier debugging.** Anything that helps you navigate and understand your code is key to efficient debugging.

**Thorough testing helps uncover bugs.** You can never reach step 1 if you are unaware of lurking issues!

#### Stackframe Navigation
- `bt` - backtrace
- `where` - same as `bt`
- `up` - move up the stack
- `down` - move down the stack
- `finish` - run until the current function returns (used when you accidentally step into a function)

#### Program Crash
- `run` the program without breakpoints
- `bt` to see the stack trace

#### Infinite Loop
- `run` the program without breakpoints
- `ctrl-c` to stop the program after a while
- `bt` to see the stack trace

#### Inconsistent Behabiour
My program has varying behavior (e.g. randomly inconsistent, different in- vs. out-side of sanitycheck, or in- vs. out-side of GDB) or prints weird output.
- Inconsistent behavior usually indicates a memory error.
- Use `valgrind` to check for memory errors.





### Multithreading

`info threads`

`thread #` switch to different thread

`watch var condition`: `watch counter >= 450`

`b func_name/line thread#`: set breakpoint for a single thread

`thread apply all command`: apply `command` to all threads