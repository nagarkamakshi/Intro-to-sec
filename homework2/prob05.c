#include <stdio.h>
#include <stdlib.h>

void happy() {
  printf("Congratulations!  Here's your shell\n");
  system("/bin/sh");
  exit(0);
}

void sad() {
  puts("No joy.  Exiting.");
  exit(1);
}

void vuln() {
  void (*func_ptr)(void);
  char buf[16];

  func_ptr = sad;

  printf("This is vuln() \tfunc_ptr = %p \thappy = %p \tsad = %p\n", func_ptr, happy, sad);
  puts("Enter your input: ");
  gets(buf);
  printf("Now func_ptr = %p\n", func_ptr);

  func_ptr();

  return;
}

int main(int argc, char* argv[])
{
  vuln();
  return 0;
}
