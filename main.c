#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
  char message[] = "This is a One-Time Pad Encryption/ Decryption Script";
  int length = strlen(message)*8+1;
  char pad[length], msg_binary[length], encrypted[length], decrypted[length], msg_decrypted[length];
  char temp[8];
  int i = 0, j = 0, k = 0;

  //Generate random pad
  srand(time(0));
  for(i = 0; i < length; i++){
    pad[i] = ((int)rand() % 2)+'0';
  }
  pad[i] = '\0';

  //Convert message to binary
  for(i = 0; i < strlen(message); i++){
    for(j=7;j>=0;j--){
      if((message[i]>>j&1)==1)
        msg_binary[k] = '1';
      else
        msg_binary[k] = '0';
      k++;
      }
  }
  msg_binary[k] = '\0';

  //Encrypt message by XOR with pad
  for(i = 0; i < length-1; i++){
    encrypted[i] = (msg_binary[i] ^ pad[i])+'0';
  }
  encrypted[i] = '\0';

  //Decrypt message by XOR with pad
  for(i = 0; i < length-1; i++){
    decrypted[i] = (encrypted[i] ^ pad[i])+'0';
  }
  decrypted[i] = '\0';

  //Convert decrypted message to ascii
  for(i = 0; i < strlen(message); i++){
    for(j = 0; j < 8; j++){
      temp[j] = decrypted[(i*8)+j];
    }
    msg_decrypted[i] = strtol(temp, 0, 2);
  }
  msg_decrypted[i] = '\0';

  printf("Message:\n%s\n\n", message);
  printf("Pad:\n%s\n\n", pad);
  printf("Message binary:\n%s\n\n", msg_binary);
  printf("Encrypted:\n%s\n\n", encrypted);
  printf("Decrypted:\n%s\n\n", decrypted);
  printf("Decrypted ASCII:\n%s\n", msg_decrypted);

  return 0;
}