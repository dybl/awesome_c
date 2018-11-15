gcc address.c -o address
# 
# Result:
# address of a: 0x7ffff9dee41c
# address stored in p: 0x7ffff9dee41c
# value of *p: 20
# 
gcc null.c -o null
# 
# # address of p: (nil)
# 
gcc ptr++.c -o ptr++
# /*
# ptr++.c: In function ‘main’:
# ptr++.c:10:35: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument
# 3 has type ‘int *’ [-Wformat=]
#          printf("address: a[%d] = %x\n", i, p);
#                                   ~# 
#                                   %ls
# 
# address: a[0] = e542306c
# value: a[0] = 10
# address: a[1] = e5423070
# value: a[1] = 100
# address: a[2] = e5423074
# value: a[2] = 200
# 
# 
gcc ptr--.c -o ptr--
# 
# 
# ptr--.c: In function ‘main’:
# ptr--.c:10:35: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument
# 3 has type ‘int *’ [-Wformat=]
#          printf("address: a[%d] = %x\n", i, p);
#                                   ~# 
#                                   %ls
# 
# address: a[3] = dcc9eab4
# value: a[3] = 200
# address: a[2] = dcc9eab0
# value: a[2] = 100
# address: a[1] = dcc9eaac
# value: a[1] = 10
# 