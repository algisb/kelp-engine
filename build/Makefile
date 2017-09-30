#compilation
CC = clang -std=gnu++11


#-------------------------------------------------------------

main.o : ../main.cpp
	$(CC) -c ../main.cpp -I ../ -I ../SDL2/include
	

#linking
all: main.o 
	$(CC) -o ../bin/kelp-engine.out main.o ../SDL2/libs/libSDL2.so


clean:
	rm -f *.o
