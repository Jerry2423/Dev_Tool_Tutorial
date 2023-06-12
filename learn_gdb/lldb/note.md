### Run
`r <args>`

### Breakpoints
Add Breakpoints:
`br s -f [name] -l # / -n [func name]`
`b #/name`

Check Breakpoints:
`br l`

Delete Breakpoints:
`br del`

Step Around:
next/step over: `n`
step into: `s`
continue: `c` (a sequence of next's until the next stop points)

### Print Vars
print: `p [var]`
print frame vars: `fr v` **frame** is a container which records all the information under a scope
go back to current line: `fr s`

### Backtrace and Frame
backtrace: `bt` (list all the frames in the call stack, `*` denote the current frame)
switch frames:
`f [frame #]`

### Watchpoints
Concept: due to the mechanism of debugger, Watchpoints can only be added after the programming running
set watchpoint: `w s v [name] (-w read/write(defalut)/read_write)`

### Kill and Quit
kill process: `kill`
quit: `q`
### Working with Xcode
use cmake to generate xcode project: `cmake -G Xcode [path]`
then adding breakpoint in xcode.
