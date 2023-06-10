## Missing Semester



1. White spaces separate argument: 命令 + whitespace + argument1 + whitespace + argument2

含空格的单个参数：`""`打包

2. root: 根目录starts with `/`
3. Absolute path and relative path
4. `.`current directory
5. `..`parent directory 连续返回`cd ../../`
6. `cd ~`back home
7. `cd -`go to the dir you were previously in
8. `mv` change name or move to other directory
9. `cp` copy single file
10. `cp -R` copy directory
11. `Rm` remove file
12. `rm -r` 删文件目录
13. `rm ./-t`:删除特殊名字的文件（eg -t,-a）要加目录
14. `rmdir`删空目录，防误触
15. `mkdir`
16. `man command` ask for help for certain command; press `q` to quit
17. `ctrl+l` clean up the shell
18. `command+l` clean a line
19. `tail -n1` the last line
20. `left | right` pipe line: extract left as input for the right function
21. `cat` look file
22. `sudo` super user: `/sys` play with hardware
23. ` stat` look at a file's information:`st_atime, st_mtime, st_ctime, st_birthtime`
24. `ls-l`: 1 + 3*3: 3 different permissions with 3 different types of users: owner, same group of people, others.

This gives us a bunch more information about each file or directory present. First, the `d` at the beginning of the line tells us that `missing` is a directory. Then follow three groups of three characters (`rwx`). These indicate what permissions the owner of the file (`missing`), the owning group (`users`), and everyone else respectively have on the relevant item. 

22. `mkdir -p`: make directories with sub-directories `mkdir -p foo/foo2`
23. `chmod`: change change file modes or Access Control Lists

`chmod +rwx` `chmod +r`: add more permissions for the owner of the file

`chmod g+rwx`: add more permissions for the users in the same groups

`chmod o+rwx`:  add more permissions for other users

`chmod -rwx` `-`remove permissions.

24. `cat` concatenate and print files
25. `touch`:change file access and modification times

`touch -a` `touch -m`: update access and modification time to the present date

`touch -t 201201182009.48`: change modification time(by defalut) to `2012-01-18 20:09 48s`

Note: the format of time must be fulfilled. 格式必须完整

`touch -a -t 201201182009.48 `:  change access time(by defalut) to `2012-01-18 20:09 48s`

26. `>` and `>>` 区别：前者把文件内通全改了；后者是在原文件后面append新内容 `cat last_modified.txt > last_line` `cat last_line.txt >> last_modified.txt`

27. Read the **nth** line of a file: `head` and `tail` and pipeline `|`: `./semester | head - n 4 | tail -n 1 > filename.txt`: read the 4th line. Use `head` to get the first 4 lines than use the first 4 lines as input of `tail ` and get the last line. We get the 4th line.

    

    

    ### Shell Scripting

    

    1. Write a script

    `touch file_name.sh`

    `open file_name.sh`

    Use Xcode/vscode edit

    Import script

    `source file_name.sh`

    use

    2. About `$` 和函数的argument相关，`function_name argu1 argu2...` ->`$1 $2...`用`$`表示是第几个argument; `$`还可以看作取出函数值`echo "we r in $(pwd)"`

    - `$0` - Name of the script
    - `$1` to `$9` - Arguments to the script. `$1` is the first argument and so on.
    - `$@` - All the arguments
    - `$#` - Number of arguments
    - `$?` - Return code of the previous command
    - `$$` - Process identification number (PID) for the current script
    - `!!` - Entire last command, including arguments. A common pattern is to execute a command only for it to fail due to missing permissions; you can quickly re-execute the command with sudo by doing `sudo !!`
    - `$_` - Last argument from the last command. If you are in an interactive shell, you can also quickly get this value by typing `Esc` followed by `.` or `Alt+.`

    3. Wildcards matching: `?` and `*` can be regarded as placeholder.

    `*`全匹配，代表一个串，空串也算

    `?`只代表一个非空字符

    `rm foo*`含有`foo`的全部删掉

    `ls -l *.sh`列处`.sh`结尾的文件

    

    4. Curly braces `{}` - Whenever you have a common substring in a series of commands, you can use curly braces for bash to expand this automatically. This comes in very handy when moving or converting files. 非常适合少些代码

    批量创建文件：

    `touch foo{,1,2,3}`

    `touch {foo,bar}/try{a..c}.sh` 用`..`省略中间部分

    `mkdir -p foo{1..3}/test`批量创建目录

    图片格式转化

    `convert pic.{jpeg,png}`



	 5. 关于python script

```py
#!/usr/bin/env python
import sys

for arg in reversed(sys.argv[1:]):
    print(arg)
#foobar
```

第1行用`env`关键词确定python interpreter的目录

第2行用`import sys`导入系统库

最后用`./name.py`执行

Some differences between shell functions and scripts that you should keep in mind are:

- Functions have to be in the same language as the shell, while scripts can be written in any language. This is why including a shebang for scripts is important.
- Functions are loaded once when their definition is read. Scripts are loaded every time they are executed. This makes functions slightly faster to load, but whenever you change them you will have to reload their definition.
- Functions are executed in the current shell environment whereas scripts execute in their own process. Thus, functions can modify environment variables, e.g. change your current directory, whereas scripts can’t. Scripts will be passed by value environment variables that have been exported using [`export`](https://www.man7.org/linux/man-pages/man1/export.1p.html)
- As with any programming language, functions are a powerful construct to achieve modularity, code reuse, and clarity of shell code. Often shell scripts will include their own function definitions.



6. `find`

```shell
# Find all directories named src
find . -name src -type d
# Find all python files that have a folder named test in their path
find . -path '*/test/*.py' -type f
# Find all files modified in the last day
find . -mtime -1
# Find all zip files with size in range 500k to 10M
find . -size +500k -size -10M -name '*.tar.gz'

找到之后execute
# Delete all files with .tmp extension
find . -name '*.tmp' -exec rm {} \;
# Find all PNG files and convert them to JPG
find . -name '*.png' -exec convert {} {}.jpg \;
```

 

7. `grep`  The **grep** utility searches any given input files, selecting lines that match

      one or more patterns. 在代码里面找关键词

   In this article, we will discuss the following options that can be used with `grep`:

   - `-i`, `--ignore-case`: Ignores case distinctions in patterns and input data.
   - `-v`, `--invert-match`: Selects the non-matching lines of the provided input pattern.
   - `-n`, `--line-number`: Prefix each line of the matching output with the line number in the input file.
   - `-w`: Find the exact matching word from the input file or string. 
   - `-c`: Count the number of occurrences of the provided pattern.
   - `-R`: search recursively, search a directory:`grep -R fruit .`

8. 指令历史记录

`history 1 | grep keywords `



**alfred**

`space + search for file` + `comd+enter`:go to the location

`comd + del` delete file

`->` go to certain actions

**chrome**
switch between tabs: `command + option + arrow`
go to specific tab: `command + number`
move forward and backward in a single web tab: `command + arrow`



### Git

Basic models and data structure

Folder-tree

File-blog

Version control:take **snapshot** of each version

Node in the picture: **commit**

Reference: pointer pointing to some node: `map<string, string>` map a address string to a name string

![截屏2023-04-26 15.22.12](/Users/bryant/Programming/missing semester/gitModel.png)





![截屏2023-04-26 15.22.24](/Users/bryant/Programming/missing semester/git_reference.png)



