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

hl_md5.o: lib/hl_md5.cpp lib/hl_md5.h
	g++ -c lib/hl_md5.cpp

hl_md5wrapper.o: lib/hl_md5wrapper.cpp lib/hl_md5wrapper.h
	g++ -c lib/hl_md5wrapper.cpp

hl_wrapperfactory.o: lib/hl_wrapperfactory.cpp lib/hl_wrapperfactory.h lib/hashlibpp.h lib/hl_hashwrapper.h
	g++ -c lib/hl_wrapperfactory.cpp

clean: 
	rm -r *.o credentials_mapper.exe