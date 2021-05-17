CC = g++
CCFLAGS=-std=c++11

database: driver.o database.o #making an executable file that can be run
	$(CC) $(CCFLAGS) -o database driver.o database.o 

driver.o: driver.cpp database.o
	$(CC) $(CCFLAGS) -c -o driver.o driver.cpp 

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) -c -o database.o database.cpp 

run: 
	./database
clean:
	@rm -f *.o
	@rm database #removing the binary file produced when executing