#include <stdio.h>

#ifndef MAGICNUM
#define MAGICNUM 0x41424344
#endif

void vuln() {
  int x = 0;
  int y = 1;
  char buf[16];

  printf("This is vuln() \tx = %08x \ty = %08x\n", x, y);
  puts("Enter your input: ");
  gets(buf);
  printf("Now x = %08x and y = %08x\n", x, y);

  if(x==MAGICNUM) {
    puts("Success!  Now you can use this shell to retrieve your flag.");
    puts("The flag is in /home/flags/hw02/flag04.txt");
    system("/bin/sh");
  }
  else {
    puts("Sorry, try again.");
  }

  return;
}

int main(int argc, char* argv[])
{
  vuln();
  return 0;
}
