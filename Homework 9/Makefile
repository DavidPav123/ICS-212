libhomework9.so: libhomework9.o
	 gcc -shared -fPIC -o libhomework9.so libhomework9.o -lc

libhomework9.o: homework9.c homework9.h
	 gcc -c -fPIC -I /usr/java/jdk1.8.0_131/include -I /usr/java/jdk1.8.0_131/include/linux homework9.c -o libhomework9.o

homework9.h: homework9.class
	javah -verbose homework9

 homework9.class: homework9.java
	javac homework9.java

run :
	 java -cp . -Djava.library.path=. homework9