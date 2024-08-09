### Vim
1. movement: `hjkl`
`num` + `hjkl`
0: move to the front
$: move to the back
w: move forward a word
e: move to the end of the word
gg: first line
GG: move to the final line
num + g
A: append at the back of the end of the line
O: add new line above
o: add new line
d: delete
dd: delete a line
c: change
cc: change a line
di+(/{/[: delete inside braces
dw: delete a word
v: visual mode for paste and change
y: copy, yank
p: paste
/: search
/ keyword + n: go to the next object
shift + n: move upward
:%s/keyWord/replaceOne




**insert mode**
`i`
`A`行末插入文本
`a`append sth after a word
`o`add new line down
`O`add new line above



`:wq` save and quit



- remove:相当于剪切，删除的内容会放在剪贴板，用p还可以paste

`num+dd`

`dw`

`d$`

`d+num+motion`

- motion

**words**

`w` `b  ` `e`

**sentence**

`0` `$`

**file**

`gg`: go to the first line

`GG`: go to the last line

`num+G`: go to the specific line

`v+gg+y`: copy all

`ctrl+G`:look for line information 



**undo redo**: `u` + `ctrl+r`

**replacement**

`r`: replace single character

`R`: replace multiple characters



**change**

`c`: enter into insert mode

`c+e`: change to the end of the word

`c+$`: change to 

`c+num+motion`



**logic**: 

`change/replace/delete + number + motion`: operation > num > motion

**search**
`/keyword`
search and replace:
replace a single word: `:s/old/new` 
replace all words in the line: `:s/old/new/g`
replace all words in the whole files: `:%s/old/new`

Search in selected lines: `:lineNum1,lineNum2s/old/new`

**stop highlighting of matchings** - `:nohlsearch`

**braces matching**
move cursor to `(` `[` `{` then press `%`, the cursor goes to the matching baraces.

change/delete/ the content inside the braces: `operator + i + (`
`ci(`
`di(`
(foo)
[add]
{foo}

**command line in vim**: `:!command`

**multiple files control**
open: `:e(dit) fileName`
check buffers: `:buffers`
switch bewtween buffers: `b1`



**plugins**

`s` stands for motion surround

`ys+motion+quote` surround sth

`ds + "`

`cs + '`



`grw`: replace a word

`gr`: group replace



Comment

`gcc` line

`gc5j/down` num:relative row number



tree

`space + t`

Newfile`a`

Newdir `a name/` use `/` sign

search

` space fs `find string

`space ff` find file



**lsp**

`K` look for type

`gl` look for warning

`gd` go to the def

`gI` go to the implementation

`ctrl+o` go back after checking def. 



**compile**

```shell
 c++ --std=gnu++17 {filename}.cpp
```







