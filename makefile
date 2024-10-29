main: dgemm.c dgemm_opt.c \
	main.c makefile
	del /f main.exe
	gcc main.c -O3 -o main