(command)[echo "hbtn_cmd" | ./hsh]
[GOT]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_cmd: Permission denied
](Length: 43)
(status)[126]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_cmd: No such file or directory
](Length: 51)
(status)[127]

(command)[echo "ls" | ./hsh]
[GOT]:
(stdout)[](Length: 0)
(stderr)[](Length: 0)
(status)[139]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: 1: ls: not found
](Length: 24)
(status)[127]

(command)[echo "ls" | ./hsh]
[GOT]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: ls: Permission denied
](Length: 37)
(status)[126]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: ls: No such file or directory
](Length: 45)
(status)[127]

(command) echo "hbtn_ls /var" | ./hsh
[GOT]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_ls: Is a directory
](Length: 39)
(status)[126]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_ls: command not found
](Length: 42)
(status)[127]

(command)[echo "hbtn_ls" | ./hsh]
[GOT]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_ls: Is a directory
](Length: 39)
(status)[126]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn_ls: command not found
](Length: 42)
(status)[127]

echo "hbtn" | ./hsh
[GOT]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn: Permission denied
](Length: 39)
(status)[126]
[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: line 1: hbtn: command not found
](Length: 39)
(status)[127]



(command)[echo "ls


 /bin/ls


     ls
ls
 ls     " | ./hsh]
[GOT]:
(stdout)[](Length: 409)
(stderr)[](Length: 0)
(status)[0]
[EXPECTED]:
(stdout)[](Length: 2045)
(stderr)[](Length: 0)
(status)[0]

