all: main.o queue.o queueList.o zmqHelper.o
	g++ -o main main.o queue.o queueList.o zmqHelper.o -lzmq -ljson_linux-gcc-4.8_libmt
main.o : main.cpp
	g++ -c -o main.o main.cpp
queue.o : queue.cpp
	g++ -c -o queue.o queue.cpp
queueList.o : queueList.cpp
	g++ -c -o queueList.o queueList.cpp 
zmqHelper.o: zmqHelper.cpp
	g++ -c -o zmqHelper.o zmqHelper.cpp
clean: 
	rm *.o
	rm main
