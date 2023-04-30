run: UndirectedGraph
	./UndirectedGraph
UndirectedGraph:UndirectedGraph_main.o UndirectedGraph.o HashTable.o
	gcc UndirectedGraph_main.o UndirectedGraph.o  HashTable.o -o UndirectedGraph
HashTable.o : HashTable.c HashTable.h HashTable_Types.h
	gcc -c HashTable.c
UndirectedGraph_main.o: UndirectedGraph_main.c UndirectedGraph.h UndirectedGraph_Types.h
	gcc -c UndirectedGraph_main.c
UndirectedGraph.o: UndirectedGraph.c UndirectedGraph.h UndirectedGraph_Types.h
	gcc -c UndirectedGraph.c
clean:
	rm -f UndirectedGraph UndirectedGraph_main.o HashTable.o UndirectedGraph.o
