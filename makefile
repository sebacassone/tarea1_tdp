all: State.o Stack.o Puzzle.o Heap.o testState testStack testPuzzle testHeap main 

State.o: State.cpp State.h
	g++ -g -c State.cpp

Stack.o: Stack.cpp Stack.h
	g++ -g -c Stack.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	g++ -g -c Puzzle.cpp

Heap.o: Heap.cpp Heap.h
	g++ -g -c Heap.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	g++ -g -c AVLTree.cpp

AVLTreeNode.o: AVLTreeNode.cpp AVLTreeNode.h
	g++ -g -c AVLTreeNode.cpp

testState: testState.cpp State.o
	g++ -g State.o testState.cpp -o testState

testStack: testStack.cpp Stack.o State.o
	g++ -g State.o Stack.o testStack.cpp -o testStack

testPuzzle: testPuzzle.cpp Puzzle.o State.o Stack.o
	g++ -g State.o Stack.o Puzzle.o testPuzzle.cpp -o testPuzzle

testHeap: testHeap.cpp Heap.o
	g++ -g Heap.o testHeap.cpp -o testHeap

testAvl: testAvl.cpp AVLTree.o AVLTreeNode.o
	g++ -g AVLTree.o AVLTreeNode.o testAvl.cpp -o testAvl

main: Puzzle.o State.o Stack.o main.cpp
	g++ -g State.o Stack.o Puzzle.o main.cpp -o main

clean:
	rm -f *.o testState testStack testPuzzle testHeap testAvl main
