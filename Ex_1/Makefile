run: Ex_1
	./Ex_1
Ex_1:Ex_1_main.o Ex_1.o
	gcc Ex_1_main.o Ex_1.o -o Ex_1
Ex_1.o:Ex_1.c Ex_1.h Ex_1_Types.h
	gcc -c Ex_1.c
Ex_1_main.o: Ex_1_main.c Ex_1.h Ex_1_Types.h
	gcc -c Ex_1_main.c
clean:
	rm Ex_1 Ex_1_main.o Ex_1.o
