run: Ex_5
	./Ex_5
Ex_5:Ex_5_main.o Ex_5.o
	gcc Ex_5_main.o Ex_5.o -o Ex_5
Ex_5.o:Ex_5.c Ex_5.h Ex_5_Types.h
	gcc -c Ex_5.c
Ex_5_main.o: Ex_5_main.c Ex_5.h Ex_5_Types.h
	gcc -c Ex_5_main.c
clean:
	rm Ex_5 Ex_5_main.o Ex_5.o
