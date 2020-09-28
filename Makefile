all:*.c
	gcc -Wall -o encfil *.c -O2
install:encfil
	cp encfil /usr/bin
uninstall:
	rm /usr/bin
