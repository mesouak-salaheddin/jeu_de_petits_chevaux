cc=clang -Wall -g

all: projet_1

projet_1.o: projet_1.c creation.h choix.h
			$(cc) -c projet_1.c
creation.o: creation.c creation.h
			$(cc) -c creation.c
choix.o: choix.c choix.h
			$(cc) -c choix.c


projet_1: projet_1.o creation.o  choix.o
		$(cc) projet_1.o creation.o choix.o -o projet_1 
clean:
		rm -f projet_1 *.o