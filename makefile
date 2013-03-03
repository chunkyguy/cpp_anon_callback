calldemo_demo: main.o Server.o Client.o
	clang++ main.o Server.o Client.o -o callback_demo
main.o: main.cpp
	clang++ -c main.cpp -o main.o
Server.o: Server.cpp
	clang++ -c Server.cpp -o Server.o
Client.o: Client.cpp
	clang++ -c Client.cpp -o Client.o
clean:
	rm *.o
