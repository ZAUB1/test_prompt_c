uct: main.c
ifeq ($(OS),Windows_NT)
	gcc main.c calc.c actions.c -o shell -Dwin #Need to change it for MinGW
else
	gcc main.c calc.c actions.c -o shell
endif
