#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct answer {
  char answer_name[100];
  int answer_num;
};
int main(){
  char name[100];
  int number;
  int is_matched = 0;
  struct answer a1;
  FILE *fp;
  printf("What is your name?\n" );
  scanf("%s",name);
  printf("What is the magic number,%s?\n", name);
   scanf("%d",&number);

  fp = fopen("answers.txt", "r");
   if (fp == NULL)   {
      perror("Error while opening the file.\n");
      return -1;
   }
 for (int j = 0; j < 4; j++){
  fscanf (fp, "%s %d", a1.answer_name, &a1.answer_num);
  if(strcmp(a1.answer_name,name)==0){
    is_matched = 1;
    if (number == a1.answer_num)  printf("SUCCESS\n") ;
     else if(number > a1.answer_num) printf("TOO HIGH\n");
    else if(number < a1.answer_num) printf("TOO LOW\n") ;
  }
}
if(is_matched==0){
  if(number > 12345) {printf("TOO HIGH\n");}
   else if(number < 12345) {printf("TOO LOW\n");}
   else printf("SUCCESS\n");
 }

 fclose(fp);
     return 0;
}
