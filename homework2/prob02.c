#include <stdio.h>

#ifndef MAGICNUM
#define MAGICNUM 0x1234
#endif

int get_guess() {
  int guess = 0;
  printf("What is the magic number?  ");
  scanf("%d", &guess);
  return guess;
}

int check_guess(int guess) {
  int magic = MAGICNUM;
  return guess == magic;
}

int main(int argc, char* argv[])
{
  int g = -1;

  g = get_guess();

  if(check_guess(g)){
    printf("You win!\n");
    system("/bin/sh");
  }
  else {
    printf("Sorry, try again.\n");
  }

  return 0;
}
