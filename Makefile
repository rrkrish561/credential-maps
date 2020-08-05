output: main.o Tree.o BST.o SplayTree.o CredentialsHandler.o hl_md5.o hl_wrapperfactory.o hl_md5wrapper.o
	g++ main.o Tree.o BST.o SplayTree.o CredentialsHandler.o hl_md5.o hl_wrapperfactory.o hl_md5wrapper.o -o credentials_mapper.exe

main.o: main.cpp
	g++ -c main.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

SplayTree.o: SplayTree.cpp SplayTree.h
	g++ -c SplayTree.cpp

CredentialsHandler.o: CredentialsHandler.cpp CredentialsHandler.h
	g++ -c CredentialsHandler.cpp

hl_md5.o: hl_md5.cpp hl_md5.h
	g++ -c hl_md5.cpp

hl_md5wrapper.o: hl_md5wrapper.cpp hl_md5wrapper.h
	g++ -c hl_md5wrapper.cpp

hl_wrapperfactory.o: hl_wrapperfactory.cpp hl_wrapperfactory.h hashlibpp.h hl_hashwrapper.h
	g++ -c hl_wrapperfactory.cpp

clean: 
	rm *.o credentials_mapper.exe