prog:perso.o background.o main.o stage1.o stat.o
	gcc perso.o background.o main.o stage1.o stat.o -o prog -lSDL -lSDL_image -lSDL_ttf
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
main.o:main.c
	gcc -c main.c -g
stage1.o:stage1.c
	gcc -c stage1.c -g
stat.o:stat.c
	gcc -c stat.c -g
