CXX = g++
CXXFLAGS = -Wall -g

mytest: matrix.o driver.cpp
	$(CXX) $(CXXFLAGS) matrix.o matrixOpp.o driver.cpp -o mytest

matrix.o: matrix.cpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

matrixOpp.o: matrixOpp.cpp
	$(CXX) $(CXXFLAGS) -c matrixOpp.cpp

run:
	./mytest

val:
	valgrind ./mytest

