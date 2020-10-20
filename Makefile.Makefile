CC=g++
SOS:
	$(CC) SOS.cpp setup.o -o SOS

setup.o: setup.h
	$(CC) setup.cpp -o setup.o

clean:
	del *.o SOS.exe