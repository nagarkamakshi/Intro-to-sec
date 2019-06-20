#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

void print_hex(unsigned char *buf, int len)
{
  int i;

  for(i=0;i<len;i++){
    printf("%02x",buf[i]);
  }
}

int main(int argc, char* argv[])
{
  /* Your code goes here */
  printf("success\n");
  FILE *fPointer1=fopen("salted.txt", "r");
  FILE *fPointer2= fopen("words04.txt", "r");
  FILE *fPointer3 = fopen("flag04.txt", "w");

  unsigned char hashedtxt[SHA_DIGEST_LENGTH];
  unsigned char hashedwords[SHA_DIGEST_LENGTH];
  char userName[50];
  char salt[50];
  SHA_CTX ctx;
	SHA1_Init(&ctx);

  while(!feof(fPointer1)){
     fscanf(fPointer1, "%s %s %s", userName, salt, hashedtxt);
     char *words = malloc(sizeof(char)*1024);

         while(!feof(fPointer2)){
                fscanf(fPointer2, "%s", words);

				// Object to hold the current state of the hash
				// Hash each piece of data as it comes in:
				SHA1_Update(&ctx, words, sizeof(words));
				SHA1_Update(&ctx, salt, sizeof(salt));
				// When you're done with the data, finalize it:
				SHA1_Final(hashedwords, &ctx);

        //print_hex(hashedwords,40);
        //printf("\n");
      //  print_hex(hashedtxt,40);
      //  printf("\n");

				//SHA1(words, sizeof(words), hashedwords);
                char output[60];
                char *ptr = &output[0];

                //Convert SHA1 byte into hex
                for (int i = 0; i < 20; i++){
                        ptr += sprintf (ptr, "%02X", hashedwords[i]);
                }
                //Convert into lowercase
                for(int i = 0; i< 40; i++){
                        output[i] = tolower(output[i]);
                }
              //  print_hex(output,40);
              //  printf("\n");
                if(strncmp(hashedtxt, output,10) == 0){
                    printf(fPointer3,"%s\t %s\n", userName, words);

                }
              }
      fclose(fPointer2);
      fclose(fPointer3);

  }
  return 0;
}
