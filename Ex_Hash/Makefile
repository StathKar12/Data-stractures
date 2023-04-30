run: HashTable
	./HashTable
HashTable:HashTable_main.o HashTable.o
	gcc HashTable_main.o HashTable.o -o HashTable
HashTable.o : HashTable.c HashTable.h HashTable_Types.h
	gcc -c HashTable.c
HashTable_main.o: HashTable_main.c HashTable.h HashTable_Types.h
	gcc -c HashTable_main.c
clean:
	rm -f HashTable HashTable_main.o HashTable.o
