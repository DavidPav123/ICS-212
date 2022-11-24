project_debug: user_interface_debug.o llist.o
	g++ -o project_debug user_interface.o llist.o

user_interface_debug.o: user_interface.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp -D DEBUG user_interface.cpp

llist_debug.o: llist.cpp record.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp -D DEBUG llist.cpp