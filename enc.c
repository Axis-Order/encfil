#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
     char *buf;
     buf = malloc(1);



    int i = 0;
     while(!feof(stdin)){
         fread(buf, sizeof(char), sizeof(char), stdin);
         if(feof(stdin)) {
             break;
         }
         buf[0] = buf[0] ^ argv[1][i];
         fwrite(buf, sizeof(char), sizeof(char), stdout);
         i++;
         if(argv[1][i] == '\0'){
             i = 0;
         }
     }
     free(buf);
     return 0;
}

