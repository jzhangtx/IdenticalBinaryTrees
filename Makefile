IdenticalBinTrees: IdenticalBinTrees.o
	g++ -g -o IdenticalBinTrees.exe IdenticalBinTrees.o -pthread    

IdenticalBinTrees.o: IdenticalBinTrees/IdenticalBinTrees.cpp
	g++ -g  -c -pthread IdenticalBinTrees/IdenticalBinTrees.cpp
