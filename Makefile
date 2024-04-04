all: test

%.o: %.cpp
	c++ $< -o $@ -c -std=c++11

test: DesFunc.o DiffDistribution.o LookUpTables.o Search.o Test.o
	c++ $^ -o $@ -std=c++11
