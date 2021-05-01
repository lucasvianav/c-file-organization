all:
	gcc -Wall -g -std=c99 main.c -o main
mem:
	gcc -g3 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -Werror -Wall -std=c99 main.c -o main
run:
	./main