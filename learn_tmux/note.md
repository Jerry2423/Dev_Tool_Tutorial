## Tmux Self-Tutorial

#### Configuration
config file at `~/.tmux.conf`
**reload configuration**: delete the `.tmux.conf` file and **`tmux kill-server`**(important)
**refresh config**: `prefix + r`

#### Homebrew Issue
`brew no such file/directory`
[Solution](https://stackoverflow.com/questions/54543697/not-able-to-install-anything-because-of-brew-no-such-file-or-directory-error)

#### Plugins Management
[TPM Plugins](https://github.com/tmux-plugins/tpm)
Bug:`alt`+`u` failed: [Duplicate Key](https://github.com/tmux-plugins/tpm/issues/72)


#### Copy in Tmux
When using mouse to select: enter into the `Copy Mode` automatically
Exit `ctrl+c` (diff from `prefix + ctrl+c`:new window)


#### Windows Planes Sessions
**Sessions**
- new session `tmux`
- list all sessions `tmux ls` / `prefix + s`: s stands for session
- leave a session, the session is still running in the back end `tmux detach`

- go to a session `tmux attach (-t [to the target session])`

- delete a session `exit`

**Plane**
- vertical plane `prefix + |`
- horizontal plane `prefix + -`
- set the size `prefix + hjkl`
- set the max size `prefix + m`
- directory of a plane is the same as where the session is opened
- use: one program + new horizontal plane at the bottom as the test counsel: max the upper one when coding, go back(`prefix + m` again) when testing

**Windows**
- new window `prefix + c`
- go to the window `prefix n(next) / p(previous) / num(index) / name`
- rename a window `prefix: + rename-window [name]`
- check all window `prefix + w`
- kill window `prefix + &`


#### Other
- check time / lock `prefix + t`
