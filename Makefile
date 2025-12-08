CXX = g++
CXXFLAGS = -std=c++17
# SRC = src/pagerank.cpp
SRC = src/main.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC)

clean:
	rm -f a.out