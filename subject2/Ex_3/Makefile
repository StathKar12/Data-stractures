BHeap: CL_BHeap Ex_5
	./Ex_3
CompleteBTP: CL_CompleteBTP Ex_4
	./Ex_3
BTPointer: CL_BTPointer Ex_1
	./Ex_3
BTArray: CL_BTArray Ex_2
	./Ex_3
Ex_5:Ex_5_main.o Ex_5.o
	gcc Ex_5_main.o Ex_5.o -o Ex_3
Ex_5.o:Ex_5.c Ex_5.h Ex_5_Types.h
	gcc -c Ex_5.c
Ex_5_main.o: Ex_5_main.c Ex_5.h Ex_5_Types.h
	gcc -c Ex_5_main.c
Ex_1:Ex_1_main.o Ex_1.o
	gcc Ex_1_main.o Ex_1.o -o Ex_3
Ex_1.o:Ex_1.c Ex_1.h Ex_1_Types.h
	gcc -c Ex_1.c
Ex_1_main.o: Ex_1_main.c Ex_1.h Ex_1_Types.h
	gcc -c Ex_1_main.c
Ex_2:Ex_2_main.o Ex_2.o
	gcc Ex_2_main.o Ex_2.o -o Ex_3
Ex_2.o:../Ex_3/Ex_2.c Ex_2.h Ex_2_Types.h
	gcc -c Ex_2.c
Ex_2_main.o: Ex_2_main.c Ex_2.h Ex_2_Types.h
	gcc -c Ex_2_main.c
Ex_4:Ex_4_main.o Ex_4.o
	gcc Ex_4_main.o Ex_4.o -o Ex_3
Ex_4.o:Ex_4.c Ex_4.h Ex_4_Types.h
	gcc -c Ex_4.c
Ex_4_main.o: Ex_4_main.c Ex_4.h Ex_4_Types.h
	gcc -c Ex_4_main.c
clean:
	rm -f Ex_3 Ex_5.o Ex_5_main.o Ex_4.o Ex_4_main.o Ex_1.o Ex_1_main.o Ex_2.o Ex_2_main.o
CL_BHeap:
	rm -f Ex_3 Ex_5.o Ex_5_main.o
CL_BTArray:
	rm -f Ex_3 Ex_2.o Ex_2_main.o
CL_BTPointer:
	rm -f Ex_3 Ex_1.o Ex_1_main.o
CL_CompleteBTP:
	rm -f Ex_3 Ex_4.o Ex_4_main.o
