#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(int argc, char const *argv[])
{
    int v = 0x87654321;
    float fv = (float) v;
    int *pv = &v;
    show_int(v);
    show_float(fv);
    show_pointer(pv);
    byte_pointer vp = (byte_pointer)&v;
    show_bytes(vp, 1);
    show_bytes(vp, 2);
    show_bytes(vp, 3);
    show_bytes(vp, 4);
    show_bytes(vp, 5);
    return 0;
}

/*
$gcc show-cast.c -o show-cast
$./show-cast

 21 43 65 87
 7a 35 f1 ce
 20 b4 db ca ff 7f 00 00
 21
 21 43
 21 43 65
 21 43 65 87
 21 43 65 87 7a
*/

/*
(gdb) disas/s
Dump of assembler code for function main:
show-cast.c:
27      {
   0x00000000080007b1 <+0>:     push   %rbp
   0x00000000080007b2 <+1>:     mov    %rsp,%rbp
   0x00000000080007b5 <+4>:     sub    $0x30,%rsp
   0x00000000080007b9 <+8>:     mov    %edi,-0x24(%rbp)
=> 0x00000000080007bc <+11>:    mov    %rsi,-0x30(%rbp)
   0x00000000080007c0 <+15>:    mov    %fs:0x28,%rax
   0x00000000080007c9 <+24>:    mov    %rax,-0x8(%rbp)
   0x00000000080007cd <+28>:    xor    %eax,%eax

28          int v = 0x87654321;
   0x00000000080007cf <+30>:    movl   $0x87654321,-0x20(%rbp)

29          float fv = (float) v;
   0x00000000080007d6 <+37>:    mov    -0x20(%rbp),%eax
   0x00000000080007d9 <+40>:    cvtsi2ss %eax,%xmm0
   0x00000000080007dd <+44>:    movss  %xmm0,-0x1c(%rbp)

30          int *pv = &v;
   0x00000000080007e2 <+49>:    lea    -0x20(%rbp),%rax
   0x00000000080007e6 <+53>:    mov    %rax,-0x18(%rbp)

31          show_int(v);
   0x00000000080007ea <+57>:    mov    -0x20(%rbp),%eax
   0x00000000080007ed <+60>:    mov    %eax,%edi
   0x00000000080007ef <+62>:    callq  0x8000751 <show_int>

32          show_float(fv);
   0x00000000080007f4 <+67>:    mov    -0x1c(%rbp),%eax
   0x00000000080007f7 <+70>:    mov    %eax,-0x28(%rbp)
   0x00000000080007fa <+73>:    movss  -0x28(%rbp),%xmm0
   0x00000000080007ff <+78>:    callq  0x8000770 <show_float>

33          show_pointer(pv);
   0x0000000008000804 <+83>:    mov    -0x18(%rbp),%rax
   0x0000000008000808 <+87>:    mov    %rax,%rdi
   0x000000000800080b <+90>:    callq  0x8000791 <show_pointer>

34          byte_pointer vp = (byte_pointer)&v;
   0x0000000008000810 <+95>:    lea    -0x20(%rbp),%rax
   0x0000000008000814 <+99>:    mov    %rax,-0x10(%rbp)

35          show_bytes(vp, 1);
   0x0000000008000818 <+103>:   mov    -0x10(%rbp),%rax
   0x000000000800081c <+107>:   mov    $0x1,%esi
   0x0000000008000821 <+112>:   mov    %rax,%rdi
   0x0000000008000824 <+115>:   callq  0x80006fa <show_bytes>

36          show_bytes(vp, 2);
   0x0000000008000829 <+120>:   mov    -0x10(%rbp),%rax
   0x000000000800082d <+124>:   mov    $0x2,%esi
   0x0000000008000832 <+129>:   mov    %rax,%rdi
   0x0000000008000835 <+132>:   callq  0x80006fa <show_bytes>

37          show_bytes(vp, 3);
   0x000000000800083a <+137>:   mov    -0x10(%rbp),%rax
   0x000000000800083e <+141>:   mov    $0x3,%esi
   0x0000000008000843 <+146>:   mov    %rax,%rdi
   0x0000000008000846 <+149>:   callq  0x80006fa <show_bytes>

38          show_bytes(vp, 4);
   0x000000000800084b <+154>:   mov    -0x10(%rbp),%rax
   0x000000000800084f <+158>:   mov    $0x4,%esi
   0x0000000008000854 <+163>:   mov    %rax,%rdi
   0x0000000008000857 <+166>:   callq  0x80006fa <show_bytes>

39          show_bytes(vp, 5);
   0x000000000800085c <+171>:   mov    -0x10(%rbp),%rax
   0x0000000008000860 <+175>:   mov    $0x5,%esi
   0x0000000008000865 <+180>:   mov    %rax,%rdi
   0x0000000008000868 <+183>:   callq  0x80006fa <show_bytes>

40          return 0;
   0x000000000800086d <+188>:   mov    $0x0,%eax

41      }
   0x0000000008000872 <+193>:   mov    -0x8(%rbp),%rdx
   0x0000000008000876 <+197>:   xor    %fs:0x28,%rdx
   0x000000000800087f <+206>:   je     0x8000886 <main+213>
   0x0000000008000881 <+208>:   callq  0x80005c0 <__stack_chk_fail@plt>
   0x0000000008000886 <+213>:   leaveq
   0x0000000008000887 <+214>:   retq
End of assembler dump.
*/

/*
(gdb) i r
rax            0x80007b1        134219697
rbx            0x0      0
rcx            0x8000890        134219920
rdx            0x7ffffffee228   140737488282152
rsi            0x7ffffffee218   140737488282136
rdi            0x1      1
rbp            0x7ffffffee130   0x7ffffffee130
rsp            0x7ffffffee100   0x7ffffffee100
r8             0x7fffff3ecd80   140737475693952
r9             0x7fffff3ecd80   140737475693952
r10            0x2      2
r11            0x3      3
r12            0x80005f0        134219248
r13            0x7ffffffee210   140737488282128
r14            0x0      0
r15            0x0      0
rip            0x80007bc        0x80007bc <main+11>
eflags         0x206    [ PF IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
*/