## Common Shell Commands


### Ask for Help
- `man` - manual for a command, e.g. `man ls` gives the manual for `ls` command, e.g. `man -k "pattern"` gives the manual for all commands that contain `pattern`, `man ls` gives the manual for `ls` command. 
- `-k` - search for a **keyword** in the manual, not the command itself (a more general search)

### Inspect Files
- `ls` - list files in a directory
- `cat` - print file contents
- `head` - print first few lines of file
    - `-n` - print first `n` lines of file
- `tail` - print last few lines of file

### Serach Files

- Regular expressions - define a **pattern** to search for in a file
    - `.` - any character, e.g. `a.` matches `ab`, `ac`, etc.
    - `*` - zero or more of the preceding character, e.g. `a*` matches `a`, `aa`, `aaa`, etc. The idea is that after typing `a`, we expect zero or more `a`'s to follow and therefore use `*` to represent the pattern.
    - `^` - start of line, e.g. `^a` matches `ab`, `ac`, etc. but not `ba`, `ca`, etc.
    - `$` - end of line, e.g. `a$` matches `ba`, `ca`, etc. but not `ab`, `ac`, etc.
    - `.*`- match any character zero or more times, e.g. `a.*` matches `a`, `ab`, `ac`, `abc`, etc. This is different from `.` and `*` because `.*` matches **any number of arbitratry** characters, whereas `.` matches exactly **one** arbitratry character and `*` matches **zero or more** of the **preceding** character (not arbitratry).
    - `[]` - match any character in the brackets
    - `[^]` - match any character not in the brackets
    - `()` - group characters
    - `|` - or
    - `\` - escape character

- Wildcard character - Save your time for typing
    - In software, a wildcard character is a kind of **placeholder** represented by a single character, such as an asterisk (*), which can be interpreted as **a number of literal characters or an empty string**. It is often used in file searches so the full name need **not** be typed.[1]
    
    - `*` for Linux Shell, e.g. `mv * target_dir` (move all files under the current directory to the target directory), `rm */*` (remove all files under all of directories under the current path, but keep the folder)



- `rg` - search for a **pattern** in a file using regular expression (faster version of `grep`)
    - e.g. `rg -i -n -v "pattern" file/directory`
    - `rg` can also search for a pattern in **all** files using regular expression
    - `-i` - ignore case
    - `-n` - print line numbers
    - `-v` - invert match
    - `-l` - list files with matches, not the matches themselves (names only)

- `find` - search for files in a directory
    - e.g. `find start_dir -name "pattern"`
    - `-name` - search by name
    - `-type` - search by type (e.g. `f` for file, `d` for directory), e.g. `find start_dir -type d -name "pattern"`, if use `-regx`, then `find start_dir -type d -regex "pattern"`, the `pattern` will match the **absolute** path of the directory. E.g. `find . -type d -regex '.*fun.*'` works, but `find . -type d -regex 'fun.*'` does not work because the absolute path of `fun` is `/files/.../fun`, not `fun`. It also has prefix `/files/.../` which is not matched by `fun.*`.
    - `xtype` - search by **executable** type, e.g. `find start_dir -xtype f -name "pattern"`, `find start_dir -xtype d -name "pattern"`. This is useful when we want to find broken links. Find and deltete broken links: `find start_dir -xtype l -delete`. We cannot use `-type` because `-type` treats good and broken links the same way, regarding them as links. While `-xtype` treats good and broken links differently, regarding good links as files and broken links as links because broken links are not executable. (i.e. the place to which the link points is not executable (does not exits anymore), so the link itself is not executable.)
    - `-regex` - search by regular expression
    - `-exec` - execute a command on the found files, e.g. `find start_dir -name "pattern" -exec ls -l {} \;`. Note we need to add `;` combined with escape `\` (i.e. `\;`) at the end of the command to tell `find` that the command ends here.
    - `delete` - delete the found files, e.g. `find start_dir -name "pattern" -delete`

### Moving to the Previous Directory
- `cd -` - move to the previous directory
- `pushd` - push the **current (original)** directory to the directory stack and move to the new directory, e.g. `pushd /target/directory`, then `pushd` will move to `/target/directory` and the original directory (i.e. `pwd`) will be pushed to the directory stack. Then we can use `popd` to move back to the original directory.
- `popd` - pop the directory from the directory stack and move to the directory
- `dirs` - list the directory stack. Might get a little confusing, but the head of the stack is the directory that you're currently in. When you `popd`, you're moving to the directory one place **after** the head of the stack and removing it from the stack.
- Note that in Ubuntu, when excecuting `cd`, it will automatically push the current directory to the directory stack, which is the **same** as `pushd`. Therefore, we can use `cd -` to move to the previous directory.

### Compare Files
- `diff` - compare two files line by line
    - e.g. `diff file1 file2`
    - How to read the output of `diff`: You can read it as "what changes do I need to make to go from `file1` to `file2`?"
        - `>` - lines in file1 but not in file2
        - `<` - lines in file2 but not in file1
        - `---` - lines in both files but different
        - example:
        ```bash
        diff hello.c hello3.c
        3a4
        > // a comment
        5c6
        <     printf("Hello, World!\n");
        ---
        >     printf("HellO, World!\n");
        4d3
        < // a comment
        ```
        1. `3a4` - **add** a line after line 3 in `hello.c` to get `hello3.c`
        2. `5c6` - **change** line 5 in `hello.c` to line 6 in `hello3.c`
        3. `4d3` - **delete** line 4 in `hello.c` to get `hello3.c`
    - `-y` - side by side comparison
        - The output shows the differences between the two files. Lines with `|` in the middle are different between the two files, lines with `<` only exist in the first file (`file1`), and lines with `>` only exist in the second file (`file2`).
    - `-u` - unified comparison

### Symbolic Links
A symlink (also called a symbolic link) is a **type of file** in Linux that points to another file or a folder on your computer. Symlinks are similar to shortcuts in Windows.
- `ln -s` - create a symbolic link (a shortcut to a file)
    - e.g. `ln -s /path/to/original_file /path/to/symlink`
    - `-s` - create a symbolic link
    - remove a symbolic link: `rm /path/to/symlink`
    - inspect file type: `ls -l`, if the file is a symbolic link, the first character of the output will be `l` (e.g. `lrwxrwxrwx`), which means the file is a symbolic link. The `->` in the output indicates the file to which the symbolic link points.
    - find and remove all broken links: `find start_dir -xtype l -delete`


### Linux File Permissions
- [Classic SysAdmin: Understanding Linux File Permissions](https://www.linuxfoundation.org/blog/blog/classic-sysadmin-understanding-linux-file-permissions)
- `ls -l` - list files with permissions
    - The permission in the command line is displayed as: ***_rwxrwxrwx 1 owner:group***
    1. User rights/Permissions
        1. The first character that I marked with an underscore is the special permission flag that can vary.
        2. The following set of three characters (rwx) is for the **owner** permissions.
        3. The second set of three characters (rwx) is for the **Group**permissions.
        4. The third set of three characters (rwx) is for the **All Users** permissions.
    2. Following that grouping since the integer/number displays the number of hardlinks to the file.
    3. The last piece is the Owner and Group assignment formatted as Owner:Group.
- `chmod` - change file permissions
    The Permission Groups used are:

    - **u** – Owner
    - **g** – Group
    - **o** – Others
    - **a** – All users

    The potential Assignment Operators are + (plus) and – (minus); these are used to tell the system whether to add or remove the specific permissions.

    The Permission Types that are used are:

    - **r** – Read
    - **w** – Write
    - **x** – Execute

    So for example, let’s say I have a file named file1 that currently has the permissions set to _rw_rw_rw, which means that the owner, group, and all users have read and write permission. Now we want to remove the read and write permissions from the all users group.

    To make this modification you would invoke the command: `chmod a+rw file1` 
    To add the permissions above you would invoke the command: `chmod g-x file1`

    As you can see, if you want to grant those permissions you would change the minus character to a plus to add those permissions.

- `ls -alt` - list all files with permissions and time, combing the `-a` `-l` and `-t` options

### Redirection
- `>` redirects standard output of a command to a file, **overwriting** previous content.
- `>>` redirects standard output of a command to a file, appending new content to old content.
- `<` redirects standard input to a command.
- `|` redirects standard output of a command to another command.

### Customize Environment


- The *environment* refers to the preferences and settings of the current user.
- **.bash_profile** is where environment settings are stored. You can edit this file with nano.
- Save aliases, shell settings, and functions you commonly use in `~/.bashrc`, and [arrange for login shells to source it](http://superuser.com/a/183980/7106). This will make your setup available in all your shell sessions.
- *Environment variables* are variables that can be used across commands and programs and hold information about the environment.
  - `export VARIABLE="Value"` sets and exports an environment variable.
  - `USER` is the name of the current user.
  - `PS1` is the command prompt, e.g. `PS1=$` then `$ enter_command` in the command line.
  - `HOME` is the home directory, refering to the `~` directory. It is usually not customized.
  - `PATH` returns a colon `:` separated list of file paths where **command line programs** are stored It is customized in advanced cases.
  - `env` returns a list of [environment variables](https://www.codecademy.com/resources/docs/command-line/environment-variables). You can redirect the output, using `grep` to select the variable you want to see, e.g. `env | grep PATH`


###  Linux Filesystem Hierarchy Standard

| Directory           | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| / (root filesystem) | The root filesystem is the top-level directory of the filesystem. It must contain all of the files required to boot the Linux system before other filesystems are mounted. It must include all of the required executables and libraries required to boot the remaining filesystems. After the system is booted, all other filesystems are mounted on standard, well-defined mount points as subdirectories of the root filesystem. |
| /bin                | The /bin directory contains user executable files. Applications used by the system (essential)          |
| /boot               | Contains the static bootloader and kernel executable and configuration files required to boot a Linux computer. |
| /dev                | This directory contains the device files for every hardware device attached to the system. These are not device drivers, rather they are files that represent each device on the computer and facilitate access to those devices. |
| /etc                | Contains the local system configuration files for the host computer. |
| /home               | Home directory storage for user files. Each user has a subdirectory in /home. **Store personal files here!**|
| /lib                | Contains shared library files that are required to boot the system. |
| /media              | A place to mount external removable media devices such as USB thumb drives that may be connected to the host. |
| /mnt                | A temporary mountpoint for regular filesystems (as in not removable media) that can be used while the administrator is repairing or working on a filesystem. |
| /opt                | Optional files such as vendor supplied application programs should be located here. |
| /root               | This is not the root (/) filesystem. It is the home directory for the root user. |
| /sbin               | System binary files. These are executables used for system administration. |
| /tmp                | Temporary directory. Used by the operating system and many programs to store temporary files. Users may also store files here temporarily. Note that files stored here may be deleted at any time without prior notice. |
| /usr                | These are shareable, read-only files, including executable binaries and libraries, man files, and other types of documentation. Applications used by users are stored here. (e.g. program built from source) Compare it with /bin|
| /var                | Variable data files are stored here. This can include things like log files, MySQL, and other database files, web server data files, email inboxes, and much more. |