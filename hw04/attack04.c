#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

void print_hex(unsigned char *buf, int len)
{
  for(int i=0;i<len;i++){
    printf("%02x",buf[i]);
  }
}

int main(int argc, char* argv[])
{
  //File related variables
  FILE *fPointer1 = fopen("pbkdf2.txt", "r");
  FILE *fPointer2 = fopen("words.txt", "r");
  FILE *fPointer3 = fopen("flag04.txt", "a");

  unsigned char salted_password[SHA_DIGEST_LENGTH];
  unsigned char calculated_hashed_password[SHA_DIGEST_LENGTH];
  unsigned char salt[100];
  char userName[100];
  char dictionary_password[50];
  unsigned char salt_byte[8];
  //Convert PBKDF2 bytes into hex format
  char calculated_sha_hex[60];
  char *sha_ptr = &calculated_sha_hex[0];

//start reading pbkdf2 file
  while(fscanf(fPointer1, "%s %s %s", userName, salt, salted_password) != EOF){

      //convert salt hex into salt bytes format
      for(int k = 0; k < 8; k++) {
        sscanf(salt+2*k, "%2hhx", &salt_byte[k]);
      }
     //open the words.txt file before entering the next loop
     fPointer2 = fopen("words.txt", "r");
     while(fscanf(fPointer2, "%s", dictionary_password) != EOF){

        //Variables to call the function
        size_t passlen = strlen(dictionary_password);
        int iter = 10000;
        //function signature for reference
        //int PKCS5_PBKDF2_HMAC(const char *pass, int passlen,
        //             const unsigned char *salt, int saltlen, int iter,
        //               const EVP_MD *digest,
        //               int keylen, unsigned char *out);

        //Call PBKDF2 to calculate the hash
        PKCS5_PBKDF2_HMAC_SHA1(dictionary_password,passlen, salt_byte, 8,iter, 20,
                        calculated_hashed_password);
        for (int i = 0; i < 20; i++){
            sha_ptr += sprintf (sha_ptr, "%02X", calculated_hashed_password[i]);
        }
        //Convert into lowercase
        for(int i = 0; i< 40; i++){
             calculated_sha_hex[i] = tolower(calculated_sha_hex[i]);
         }
        //compare if any sha hex matches with the salted password hex from salted.txt
         if(strncmp(salted_password, calculated_sha_hex,19) == 0){
             fprintf(fPointer3,"%s\t%s\n", userName,dictionary_password);
             break;
          }
     }
     fclose(fPointer2);
  }
  fclose(fPointer1);
  fclose(fPointer3);
  return 0;
}
