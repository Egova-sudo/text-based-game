CXX = g++ -std=c++17
CXXFLAGS = -s -Wall -O2 

main: main.o game.o player.o
	$(CXX) -o main main.o game.o player.o $(CXXFLAGS)

main.o: main.cpp game.h
	$(CXX) -c -o main.o main.cpp $(CXXFLAGS)
	
game.o: game.cpp player.h data_management.h
	$(CXX) -c -o game.o game.cpp $(CXXFLAGS)
	
player.o: player.cpp
	$(CXX) -c -o player.o player.cpp $(CXXFLAGS)

clean:
	rm *.o main