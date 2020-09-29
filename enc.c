#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *buf;
    buf = malloc(1);
    if(argc != 2 && argc != 3){
        fprintf(stderr, "only one argument! (optional -v) \n");
	exit(1);
    }
    int readed = 0;
    int i = 0;
    while(!feof(stdin)){
        readed = fread(buf, sizeof(char), sizeof(char), stdin);
        if(feof(stdin)) {
            break;
        }
	if(argc == 3){
	    if(!strcmp(argv[2], "-v")){
	        fprintf(stderr,"read=%d\n", readed);
	    }
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

