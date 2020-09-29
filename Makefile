all:*.c
	gcc -Wall -o encfil *.c 
install:encfil
	cp ./encfil /usr/bin
uninstall:
	rm /usr/bin/encfil
