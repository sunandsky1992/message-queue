all: main.o queue.o queueList.o
	gcc -o main main.o queue.o queueList.o -lzmq -ljson_linux-gcc-4.6_libmt
main.o : main.cpp
	gcc -c -o main.o main.cpp
queue.o : queue.cpp
	gcc -c -o queue.o queue.cpp
queueList.o : queueList.cpp
	gcc -c -o queueList.o queueList.cpp 
clean: 
	rm *.o
	rm main
