run: Ex_3
	./Ex_3
Ex_3:Ex_3_main.o Ex_3.o
	gcc Ex_3_main.o Ex_3.o -o Ex_3
Ex_3.o:Ex_3.c Ex_3.h Ex_3_Types.h
	gcc -c Ex_3.c
Ex_3_main.o: Ex_3_main.c Ex_3.h Ex_3_Types.h
	gcc -c Ex_3_main.c
clean:
	rm Ex_3 Ex_3_main.o Ex_3.o
