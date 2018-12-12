control: control.o
	@gcc -o telephone control.o

main.o: main.c
	@gcc -c main.c

control.o: control.c
	@gcc -c control.c

clean:
	@rm *.o
	@rm telephone
