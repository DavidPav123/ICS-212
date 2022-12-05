homework10: main.o Pokemon.o Squirtle.o Charmander.o Bulbasaur.o
	g++ -o homework10 main.o Pokemon.o Squirtle.o Bulbasaur.o Charmander.o

main.o: main.cpp Pokemon.h Bulbasaur.h Charmander.h Squirtle.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp

Bulbasaur.o: Bulbasaur.cpp Bulbasaur.h Pokemon.h
	g++ -ansi -pedantic-errors -Wall -c Bulbasaur.cpp

Charmander.o: Charmander.cpp Charmander.h Pokemon.h
	g++ -ansi -pedantic-errors -Wall -c Charmander.cpp

Squirtle.o: Squirtle.cpp Squirtle.h Pokemon.h
	g++ -ansi -pedantic-errors -Wall -c Squirtle.cpp