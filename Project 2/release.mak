project: user_interface.o llist.o
	gcc -o homework3 user_interface.o llist.o

user_interface.o: user_interface.cpp llist.h
	gcc -ansi -pedantic-errors -Wall -c user_interface.cpp 

llist.o: llist.cpp record.h
	gcc -ansi -pedantic-errors -Wall -c llist.cpp