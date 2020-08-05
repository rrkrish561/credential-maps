output: main.o Tree.o BST.o SplayTree.o
	g++ main.o Tree.o BST.o SplayTree.o -o credentials_mapper.exe

main.o: main.cpp
	g++ -c main.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

SplayTree.o: SplayTree.cpp SplayTree.h
	g++ -c SplayTree.cpp

clean: 
	rm *.o credentials_mapper.exe