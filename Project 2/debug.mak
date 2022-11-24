project_debug: user_interface_debug.o llist_debug.o
	g++ -o project_debug user_interface_debug.o llist_debug.o

user_interface_debug.o: user_interface.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -D DEBUG -c user_interface.cpp -o user_interface_debug.o

llist_debug.o: llist.cpp record.h
	g++ -ansi -pedantic-errors -Wall -D DEBUG -c llist.cpp -o llist_debug.o