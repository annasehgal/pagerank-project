CXX = g++
CXXFLAGS = -std=c++17
# SRC = src/pagerank.cpp
SRC = src/main.cpp \
      src/graph.cpp \
      src/Node.cpp \
      src/pagerank.cpp \
      src/util.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC)

clean:
	rm -f a.out