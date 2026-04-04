CXX = g++
CXXFLAGS = -Wall -std=c++11

all: corrector

corrector: main.cpp dictionary.cpp edit_distance.cpp
	$(CXX) $(CXXFLAGS) -o corrector main.cpp dictionary.cpp edit_distance.cpp

clean:
	rm -f corrector corrector.exe
