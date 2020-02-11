all: main.o QueueT.o
	g++ main.o QueueT.o -std=c++11 -o QueueT
	./a.out
	valgrind --leak-check=full ./QueueT

main.o: main.cpp
	g++ -c main.cpp -std=c++11

QueueT.o: QueueT.cpp
	g++ -c QueueT.cpp -std=c++11

clean:
	rm -f *.o 
	# QueueT
