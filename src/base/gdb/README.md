# gdb-notes

> 本文写给主要工作在Windows操作系统下而又需要开发一些跨平台软件的程序员朋友，以及程序爱好者。GDB是一个由GNU开源组织发布的、UNIX/LINUX操作系统下的、基于命令行的、功能强大的程序调试工具。GDB中的命令固然很多，但我们只需掌握其中十个左右的命令，就大致可以完成日常的基本的程序调试工作。

## 编译

> 开始调试之前，必须用程序中的调试信息编译要调试的程序。这样，gdb 才能够调试所使用的变量、代码行和函数。如果要进行编译，请在 gcc（或 g++）下使用额外的 '-g' 选项来编译程序：

```
gcc as.c -o as -g
```
## 常用命令的解释

命令 | 解释 | 示例
| -- | -- | -- |
file <文件名> | 加载被调试的可执行程序文件,因为一般都在被调试程序所在目录下执行GDB，因而文本名不需要带路径 | `(gdb) file as`
r | Run的简写，运行被调试的程序,如果此前没有下过断点，则执行完整个程序；如果有断点，则程序暂停在第一个可用断点处. | `(gdb) r`
c | Continue的简写，继续执行被调试程序，直至下一个断点或程序结束. | `(gdb) c`

- b: Breakpoint的简写，设置断点。两可以使用“行号”“函数名称”“执行地址”等方式指定断点位置。
其中在函数名称前面加“*”符号表示将断点设置在“由编译器生成的prolog代码处”。如果不了解汇编，可以不予理会此用法。

`b` | options | sample
| -- | -- | -- |
b | <行号> | `(gdb) b 8`
b | <函数名称> | `(gdb) b main`
b | *<函数名称> | `(gdb) b *main`
b | *<代码地址> | `(gdb) b *0x804835c`

- d: Delete breakpoint的简写，删除指定编号的某个断点，或删除所有断点。断点编号从1开始递增。

`d` | options | sample
| -- | -- | -- |
d | [编号] | `(gdb) d`


命令 | 解释 | 示例
| -- | -- | -- |
s | 执行一行源程序代码，如果此行代码中有函数调用，则进入该函数 | `(gdb) s`
n | 执行一行源程序代码，此行代码中的函数调用也一并执行 | `(gdb) n`

> s 相当于其它调试器中的`Step Into`(`单步跟踪进入`)

> n 相当于其它调试器中的`Step Over` (`单步跟踪`)

**这两个命令必须在有源代码调试信息的情况下才可以使用(GCC编译时使用“-g”参数)**

命令 | 解释 | 示例
| -- | -- | -- |
si | 执行一行汇编指令，如果此行代码中有函数调用，则进入该函数 | `(gdb) si`
ni | 执行一行汇编指令，此行代码中的函数调用也一并执行 | `(gdb) ni`
p <变量名称> | Print的简写,显示指定变量(临时变量或全局变量)的值	| `(gdb) p i`
display | 设置程序中断后欲显示的数据及其格式 | `(gdb) display /i $pc`
undispaly | 取消先前的display设置，编号从1开始递增 | `(gdb) undisplay 1`

> 如果希望每次程序中断后可以看到即将被执行的下一条汇编指令，可以使用此命令

- 其中 `$pc` 代表当前汇编指令
- `/i` 表示以十六进行显示.

当需要关心汇编代码时,此命令相当有用.


命令 | 解释 | 示例
| -- | -- | -- |
i | Info的简写,用于显示各类信息,详情请查阅`help i` | `(gdb) i r`

`i`(`info`) | options | sample
| -- | -- | -- |
info | address | Describe where symbol SYM is stored
info | all-registers | List of all registers and their contents
info | args | Argument variables of current stack frame
info | auto-load | Print current status of auto-loaded files
info | auxv | Display the inferior's auxiliary vector
info | bookmarks | Status of user-settable bookmarks
info | breakpoints | Status of specified breakpoints (all user-settable breakpoints if no argument)
info | checkpoints | IDs of currently known checkpoints
info | classes | All Objective-C classes
info | common | Print out the values contained in a Fortran COMMON block
info | copying | Conditions for redistributing copies of GDB
info | dcache | Print information on the dcache performance
info | display | Expressions to display when program stops
info | exceptions | List all Ada exception names
info | extensions | All filename extensions associated with a source language
info | files | Names of targets and files being debugged
info | float | Print the status of the floating point unit
info | frame | All about selected stack frame
info | frame-filter | List all registered Python frame-filters
info | functions | All function names
info | guile | Prefix command for Guile info displays
info | handle | What debugger does when program gets various signals
info | inferiors | IDs of specified inferiors (all inferiors if no argument)
info | line | Core addresses of the code for a source line
info | locals | Local variables of current stack frame
info | macro | Show the definition of MACRO
info | macros | Show the definitions of all macros at LINESPEC
info | mem | Memory region attributes
info | os | Show OS data ARG
info | pretty-printer | GDB command to list all registered pretty-printers
info | probes | Show available static probes
info | proc | Show /proc process information about any running process
info | program | Execution status of the program
info | record | Info record options
info | registers | List of integer registers and their contents
info | scope | List the variables local to a scope
info | selectors | All Objective-C selectors
info | set | Show all GDB settings
info | sharedlibrary | Status of loaded shared object libraries
info | signals | What debugger does when program gets various signals
info | skip | Display the status of skips
info | source | Information about the current source file
info | sources | Source files in the program
info | stack | Backtrace of the stack
info | static-tracepoint-markers | List target static tracepoints markers
info | symbol | Describe what symbol is at location ADDR
info | target | Names of targets and files being debugged
info | tasks | Provide information about all known Ada tasks
info | terminal | Print inferior's saved terminal status
info | threads | Display currently known threads
info | tracepoints | Status of specified tracepoints (all tracepoints if no argument)
info | tvariables | Status of trace state variables and their values
info | type-printers | GDB command to list all registered type-printers
info | types | All type names
info | unwinder | GDB command to list unwinders
info | variables | All global and static variable names
info | vector | Print the status of the vector unit
info | vtbl | Show the virtual function table for a C++ object
info | warranty | Various kinds of warranty you do not have
info | watchpoints | Status of specified watchpoints (all watchpoints if no argument)
info | win | List of all displayed windows
info | xmethod | GDB command to list registered xmethod matchers


命令 | 解释 | 示例
| -- | -- | -- |
q | Quit的简写,退出GDB调试环境 | `(gdb) q`
help [命令名称]	| GDB帮助命令，提供对GDB名种命令的解释说明 | `(gdb) help display`

- 如果指定了`命令名称`参数,则显示该命令的详细说明

- 如果没有指定参数,则分类显示所有GDB命令,供用户进一步浏览和查询	


　
### 简单上手

```python
└─[$] <git:(dev*)> gdb
GNU gdb (Ubuntu 8.1-0ubuntu3) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".


(gdb) file as
Reading symbols from as...done.
```

- 下面使用`r`命令执行(`Run`)被调试文件，因为尚未设置任何断点，将直接执行到程序结束：

```python
(gdb) r
Starting program: /gdb/as
n = 1, gvar = 88
temp is called, a = 1, b = 2
n = 3
[Inferior 1 (process 523) exited normally]
```

- 下面使用`b`命令在 main 函数开头设置一个断点(`Breakpoint`)

```python
(gdb) b main
Breakpoint 1 at 0x8000683: file as.c, line 14.
```
> 上面最后一行提示已经成功设置断点，并给出了该断点信息：
>> 在源文件 as.c 第19行处设置断点；这是本程序的第一个断点(序号为1);断点处的代码地址为 0x8000683(此值可能仅在本次调试过程中有效).

> 回过头去看源代码，第14行中的代码为`n = 1`,恰好是 main 函数中的第一个可执行语句(前面的`int n;`为变量定义语句，并非可执行语句)

- 再次使用`r`命令执行（`Run`）被调试程序：

```python
(gdb) r
Starting program: /gdb/as

Breakpoint 1, main () at as.c:14
14          n = 1;
```

- 程序中断在as.c第14行处，即main函数是第一个可执行语句处。

> 上面最后一行信息为：下一条将要执行的源代码为“n = 1;”，它是源代码文件as.c中的第14行。

- 下面使用`s`命令(Step)`执行下一行代码` (即第19行`n = 1;`)：

```python
(gdb) s
15          n++;
```

上面的信息表示已经执行完`n = 1;`，并显示下一条要执行的代码为第20行的`n++;`。

既然已经执行了`n = 1;`，即给变量 n 赋值为 1，那我们用`p`命令(`Print`)看一下变量 n 的值是不是 1.

```python
(gdb) p n
$1 = 1
```

> 果然是 1。($1大致是表示这是第一次使用“p”命令——再次执行“p n”将显示“$2 = 1”——此信息应该没有什么用处)


> 下面我们分别在第26行、temp 函数开头各设置一个断点（分别使用命令 `b 21` `b temp`):
```python
(gdb) b 21
Breakpoint 3 at 0x80006b0: file as.c, line 21.
(gdb) b temp
Breakpoint 4 at 0x8000658: file as.c, line 7.
```
> 使用“c”命令继续（Continue）执行被调试程序，程序将中断在第二个断点（26行），此时全局变量 nGlobalVar 的值应该是 88;

> 再一次执行“c”命令，程序将中断于第三个断点（12行，temp 函数开头处），此时temp 函数的两个参数 a、b 的值应分别是 1 和 2：

```python
(gdb) c
Continuing.

Breakpoint 3, main () at as.c:21
21          printf("n = %d, gvar = %d\n", n, gvar);
(gdb) p gvar
$2 = 88
(gdb) c
Continuing.
n = 1, gvar = 88

Breakpoint 2, main () at as.c:23
23          n = temp(1, 2);
(gdb) p a
No symbol "a" in current context.
(gdb) c
Continuing.

Breakpoint 4, temp (a=1, b=2) at as.c:7
7           printf("temp is called, a = %d, b = %d\n", a, b);
(gdb) p a
$3 = 1
(gdb) p b
$4 = 2
```

上面反馈的信息一切都在我们预料之中.

> 再一次执行“c”命令（Continue），因为后面再也没有其它断点，程序将一直执行到结束：

```python
(gdb) c
Continuing.
temp is called, a = 1, b = 2
n = 3
[Inferior 1 (process 527) exited normally]
```

> 有时候需要看到编译器生成的汇编代码，以进行汇编级的调试或跟踪，又该如何操作呢？

- 这就要用到display命令`display /i $pc`了(此命令前面已有详细解释)

```python
(gdb) display /i $pc
1: x/i $pc
<error: No registers.>
```

> 此后程序再中断时，就可以显示出汇编代码了：
```python
(gdb) r
Starting program: /gdb/as

Breakpoint 1, main () at as.c:14
14          n = 1;
1: x/i $pc
=> 0x8000683 <main+8>:  movl   $0x1,-0x4(%rbp)
```

> 看到了汇编代码，“n = 1;”对应的汇编代码是“movl $0x1,0xfffffffc(%ebp)”。

> 并且以后程序每次中断都将显示下一条汇编指定(`si`命令用于执行一条汇编代码——区别于`s`执行一行C代码)

```python
(gdb) si
15          n++;
1: x/i $pc
=> 0x800068a <main+15>: addl   $0x1,-0x4(%rbp)
(gdb) si
16          n--;
1: x/i $pc
=> 0x800068e <main+19>: subl   $0x1,-0x4(%rbp)
(gdb) si
18          gvar += 100;
1: x/i $pc
=> 0x8000692 <main+23>: mov    0x20097c(%rip),%eax        # 0x8201014 <gvar>
(gdb) d
Delete all breakpoints? (y or n) y
(gdb) b *main
Breakpoint 5 at 0x800067b: file as.c, line 12.
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /gdb/as

Breakpoint 5, main () at as.c:12
12      {
1: x/i $pc
=> 0x800067b <main>:    push   %rbp
(gdb) si
0x000000000800067c      12      {
1: x/i $pc
=> 0x800067c <main+1>:  mov    %rsp,%rbp
(gdb) si
0x000000000800067f      12      {
1: x/i $pc
=> 0x800067f <main+4>:  sub    $0x10,%rsp
(gdb) si
14          n = 1;
1: x/i $pc
=> 0x8000683 <main+8>:  movl   $0x1,-0x4(%rbp)
(gdb) si
15          n++;
1: x/i $pc
=> 0x800068a <main+15>: addl   $0x1,-0x4(%rbp)
```

> 此时可以使用`i r`命令显示寄存器中的当前值

- `i r`即`Infomation Register`：

```python
(gdb) i r
rax            0x800067b        134219387
rbx            0x0      0
rcx            0x8000700        134219520
rdx            0x7ffffffee1b8   140737488282040
rsi            0x7ffffffee1a8   140737488282024
rdi            0x1      1
rbp            0x7ffffffee0c0   0x7ffffffee0c0
rsp            0x7ffffffee0b0   0x7ffffffee0b0
r8             0x7fffff3ecd80   140737475693952
r9             0x7fffff3ecd80   140737475693952
r10            0x2      2
r11            0x3      3
r12            0x8000540        134219072
r13            0x7ffffffee1a0   140737488282016
r14            0x0      0
r15            0x0      0
rip            0x800068a        0x800068a <main+15>
eflags         0x202    [ IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
```

> 当然也可以显示任意一个指定的寄存器值：
```python
(gdb) i r rax
rax            0x800067b        134219387
```

> 反汇编：
```python
(gdb) disas/s
```

> 最后一个要介绍的命令是“q”，退出（Quit）GDB调试环境：

```python
(gdb) q
A debugging session is active.

        Inferior 1 [process 529] will be killed.

Quit anyway? (y or n) y
```

## 附录(gdb的帮助信息)

```bash
$ gdb --help
This is the GNU debugger.  Usage:

    gdb [options] [executable-file [core-file or process-id]]
    gdb [options] --args executable-file [inferior-arguments ...]

Selection of debuggee and its files:

  --args             Arguments after executable-file are passed to inferior
  --core=COREFILE    Analyze the core dump COREFILE.
  --exec=EXECFILE    Use EXECFILE as the executable.
  --pid=PID          Attach to running process PID.
  --directory=DIR    Search for source files in DIR.
  --se=FILE          Use FILE as symbol file and executable file.
  --symbols=SYMFILE  Read symbols from SYMFILE.
  --readnow          Fully read symbol files on first access.
  --readnever        Do not read symbol files.
  --write            Set writing into executable and core files.

Initial commands and command files:

  --command=FILE, -x Execute GDB commands from FILE.
  --init-command=FILE, -ix
                     Like -x but execute commands before loading inferior.
  --eval-command=COMMAND, -ex
                     Execute a single GDB command.
                     May be used multiple times and in conjunction
                     with --command.
  --init-eval-command=COMMAND, -iex
                     Like -ex but before loading inferior.
  --nh               Do not read ~/.gdbinit.
  --nx               Do not read any .gdbinit files in any directory.

Output and user interface control:

  --fullname         Output information used by emacs-GDB interface.
  --interpreter=INTERP
                     Select a specific interpreter / user interface
  --tty=TTY          Use TTY for input/output by the program being debugged.
  -w                 Use the GUI interface.
  --nw               Do not use the GUI interface.
  --tui              Use a terminal user interface.
  --dbx              DBX compatibility mode.
  -q, --quiet, --silent
                     Do not print version number on startup.

Operating modes:

  --batch            Exit after processing options.
  --batch-silent     Like --batch, but suppress all gdb stdout output.
  --return-child-result
                     GDB exit code will be the child's exit code.
  --configuration    Print details about GDB configuration and then exit.
  --help             Print this message and then exit.
  --version          Print version information and then exit.

Remote debugging options:

  -b BAUDRATE        Set serial port baud rate used for remote debugging.
  -l TIMEOUT         Set timeout in seconds for remote debugging.

Other options:

  --cd=DIR           Change current directory to DIR.
  --data-directory=DIR, -D
                     Set GDB's data-directory to DIR.

At startup, GDB reads the following init files and executes their commands:
   * system-wide init file: /etc/gdb/gdbinit

For more information, type "help" from within GDB, or consult the
GDB manual (available as on-line info or a printed manual).
Report bugs to "<http://www.gnu.org/software/gdb/bugs/>".
```