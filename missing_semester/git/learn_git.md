`git status`
`git add`
`git add .`
`git add --all`
`git rm --cached name` : use "git rm --cached <file>..." to unstage
`git restore --staged filename` : same as above
`git init`
`git commit -a -m`
`git commit --amend -m "message"` :amend the most recent commit without building a new commit
`git commit --amend --no-edit` : add new files to the current commit;The --no-edit flag will allow you to make the amendment to your commit without changing its commit message. 
question about --amend : working together with reference? mit missing semester
`git add -p name`: --patch: interactivly deciding whether stage a change in the file; ususally `s` first after the add then `y/n`

**about merge and branch**
- before merging and branching operations, we need to go back to the original commit `git checkout master`
- if merge conflicts appear, mannually change the file and **re-add** to the stage area first: `git add <filename>` then `git merge --continue`

`git merge xx`: merge in to the **current** branch



`git diff <from a> <to b> filename`
`git checkout <filename>`: update the file in the working directory to the version stored in the snapshot to which HEAD points. Might be dangerous cause it can destroy the change you made in the file
`git switch <branch name>`
difference between `switch` and `checkout`: switch can only switch to the `branch` reference; but checkout can switch to `filename`, `commit` and `branch`

`git remote add origin <url>`
`git push <remote> <local branch>:<remote branch>`
`git push origin master:main`
`git clone <url> <locall folder name>`
`git clone --shallow <url> <folder name>`
concept
- working area: files -> staging(holding pen)-> commit
- staging area: tell git what to keep track of 

phylosophy
- `--` follow a word without abbreviation; `-` follow a letter abbreviation



- Ignore specified files: [Link](https://stackoverflow.com/questions/8981472/ignore-all-files-with-the-same-name-in-git)

> - An asterisk "`*`" matches anything except a slash. The character "`?`" matches any one character except "`/`". The range notation, e.g. `[a-zA-Z]`, can be used to match one of the characters in a range. See fnmatch(3) and the FNM_PATHNAME flag for a more detailed description.
> - A leading "`**`" followed by a slash means match in all directories. For example, "`**/foo`" matches file or directory "`foo`" anywhere, the same as pattern "`foo`". "`**/foo/bar`" matches file or directory "`bar`" anywhere that is directly under directory "`foo`".
> - A trailing "`/**`" matches everything inside. For example, "`abc/**`" matches all files inside directory "`abc`", relative to the location of the `.gitignore` file, with infinite depth.

