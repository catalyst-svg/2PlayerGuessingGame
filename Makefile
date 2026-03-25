CXX = g++
CXXFLAGS = -Wall -std=c++17

2PlayerGuessingGame: main.o
	$(CXX) $(CXXFLAGS) -o 2PlayerGuessingGame main.o
main.o: main.cpp guessingGame.h
	$(CXX) $(CXXFLAGS) -c main.cpp
clean:
	rm -f *.o 2PlayerGuessingGame
