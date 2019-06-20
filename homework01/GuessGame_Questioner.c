#include<stdio.h>
#include<string.h>
 struct answer {
  char answer_name[23];
  int answer_num;
};
int main(){
  char name[23],buffer[100];
  int number=12345;
  struct answer a1;
  FILE *fp;
  printf("what is your name? \n " );
  scanf("%s",name);
  printf("what is the magic number,%s?\n", name);
  scanf("%d",&number);
  fp = fopen("answers.txt", "r");
   if (fp == NULL)   {
      perror("Error while opening the file.\n");
      return -1;
   }
  for(int i=0;i<5;i++){
   fscanf (fp, "%s %d", a1.answer_name, &a1.answer_num);
  if(strcmp(a1.answer_name,name)==0){
     if(number > a1.answer_num) {printf("Too High\n");}
    else if(number < a1.answer_num) {printf("Too Low\n");}
    else{printf("Success\n");}
  }
  return 0;
}
 if(number == 12345){    printf("Success\n");  }
 fclose(fp);
     return 0;
}
