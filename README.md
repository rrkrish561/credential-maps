# credential-maps
An application to store and validate credentials. 
Uses a BST and SplayTree as backend data structures.

To compile on Linux with g++, use the included makefile called "Makefile".

Then, run the newly generated credentials_mapper.exe.

You will be greeted with a command line interface. 
Options 1 and 2 allow for user control of the specific credentials that are inserted.

Otherwise, option 3 will run simulated logins based on the dataset, which is not provided here.
The specific dataset files are determined by setting the variables insertCredTextFile and loginSimulatorFile on lines 22 and 23 in main.cpp, which should exist in the same directory that credentials_mapper.exe is in.
