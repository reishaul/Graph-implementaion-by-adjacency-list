#reishaul1@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IAlgorithms -IGraph -I"Data Structure"


SRC_DIRS = Graph Algorithms "Data Structure"


OBJ = Graph/Graph.o Graph/Edge.o \
      Algorithms/Algorithms.o \
      Data\ Structure/Queue.o Data\ Structure/Stack.o Data\ Structure/MinHeap.o Data\ Structure/UnionFind.o

EXEC = main


$(EXEC): $(OBJ) main.o  
	$(CXX) $(CXXFLAGS) $(OBJ) main.o -o $(EXEC)

#compilation form .cpp to .o files
Graph/Graph.o: Graph/Graph.cpp Graph/Graph.hpp  
	$(CXX) $(CXXFLAGS) -c Graph/Graph.cpp -o Graph/Graph.o


Graph/Edge.o: Graph/Edge.cpp Graph/Edge.hpp  
	$(CXX) $(CXXFLAGS) -c Graph/Edge.cpp -o Graph/Edge.o

Algorithms/Algorithms.o: Algorithms/Algorithms.cpp Algorithms/Algorithms.hpp Graph/Graph.hpp Data\ Structure/Queue.hpp Data\ Structure/Stack.hpp Data\ Structure/MinHeap.hpp Data\ Structure/UnionFind.hpp Graph/Edge.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms/Algorithms.cpp -o Algorithms/Algorithms.o

#for the queue
Data\ Structure/Queue.o: Data\ Structure/Queue.cpp Data\ Structure/Queue.hpp  
	$(CXX) $(CXXFLAGS) -c Data\ Structure/Queue.cpp -o Data\ Structure/Queue.o

#for the stack
Data\ Structure/Stack.o: Data\ Structure/Stack.cpp Data\ Structure/Stack.hpp  
	$(CXX) $(CXXFLAGS) -c Data\ Structure/Stack.cpp -o Data\ Structure/Stack.o

#for the minheap
Data\ Structure/MinHeap.o: Data\ Structure/MinHeap.cpp Data\ Structure/MinHeap.hpp  
	$(CXX) $(CXXFLAGS) -c Data\ Structure/MinHeap.cpp -o Data\ Structure/MinHeap.o

#for unionfind
Data\ Structure/UnionFind.o: Data\ Structure/UnionFind.cpp Data\ Structure/UnionFind.hpp  
	$(CXX) $(CXXFLAGS) -c Data\ Structure/UnionFind.cpp -o Data\ Structure/UnionFind.o

main.o: main.cpp Graph/Graph.hpp Algorithms/Algorithms.hpp  
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# for make Main
Main: $(EXEC)
	./$(EXEC)

#for the testing section
TEST_SRC = TestAlgorithms.cpp  
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_runner

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(OBJ) 
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) $(OBJ) -o $(TEST_EXEC)

$(TEST_OBJ): $(TEST_SRC) Graph/Graph.hpp Algorithms/Algorithms.hpp Data\ Structure/Queue.hpp Data\ Structure/Stack.hpp Data\ Structure/MinHeap.hpp Data\ Structure/UnionFind.hpp Graph/Edge.hpp
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

# cleaning the o files
clean:  
	rm -f $(OBJ) main.o $(EXEC) $(TEST_OBJ) $(TEST_EXEC)

#for make valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)
