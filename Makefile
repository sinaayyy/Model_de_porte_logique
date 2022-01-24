CPP=g++ --std=c++11
CFLAGS= -Wall

all : main

main : main.o Gate.o oneInputGate.o twoInputGate.o InputGate.o OutputGate.o NegateGate.o AndGate.o NAndGate.o OrGate.o NOrGate.o XorGate.o XNorGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

oneInputGate.o : oneInputGate.cpp oneInputGate.hpp
	$(CPP) $(CFLAGS) -c $<

twoInputGate.o : twoInputGate.cpp twoInputGate.hpp
	$(CPP) $(CFLAGS) -c $<

InputGate.o : InputGate.cpp InputGate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : OutputGate.cpp OutputGate.hpp
	$(CPP) $(CFLAGS) -c $<

NegateGate.o : oneInputGates/NegateGate.cpp oneInputGates/NegateGate.hpp
	$(CPP) $(CFLAGS) -c $<

AndGate.o : twoInputGates/AndGate.cpp twoInputGates/AndGate.hpp
	$(CPP) $(CFLAGS) -c $<

NAndGate.o : twoInputGates/NAndGate.cpp twoInputGates/NAndGate.hpp
	$(CPP) $(CFLAGS) -c $<

OrGate.o : twoInputGates/OrGate.cpp twoInputGates/OrGate.hpp
	$(CPP) $(CFLAGS) -c $<

NOrGate.o : twoInputGates/NOrGate.cpp twoInputGates/NOrGate.hpp
	$(CPP) $(CFLAGS) -c $<

XorGate.o : twoInputGates/XorGate.cpp twoInputGates/XorGate.hpp
	$(CPP) $(CFLAGS) -c $<

XNorGate.o : twoInputGates/XNorGate.cpp twoInputGates/XNorGate.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	./main