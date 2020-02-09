all: main.o QueueT.o
	g++ main.o QueueT.o
	./a.out

main.o: main.cpp
	g++ -c main.cpp

QueueT.o: QueueT.cpp
	g++ -c QueueT.cpp

clean:
	rm -f *.o
