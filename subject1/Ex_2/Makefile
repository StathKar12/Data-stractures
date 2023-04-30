run: Ex_2
	./Ex_2
Ex_2:Ex_2_main.o Ex_2.o
	gcc Ex_2_main.o Ex_2.o -o Ex_2
Ex_2.o:Ex_2.c Ex_2.h Ex_2_Types.h
	gcc -c Ex_2.c
Ex_2_main.o: Ex_2_main.c Ex_2.h Ex_2_Types.h
	gcc -c Ex_2_main.c
clean:
	rm Ex_2 Ex_2_main.o Ex_2.o
