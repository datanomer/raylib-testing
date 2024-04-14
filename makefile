main: main.c
	gcc -I libs/raylib-5.0_linux_amd64/include -o main main.c -L ./libs/raylib-5.0_linux_amd64/lib -lm -l:libraylib.a

clean:
	rm -f main
