MAINPROG=Auto_Test_Grader

SOURCES:=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(MAINPROG)

$(MAINPROG): $(OBJECTS)
	g++ $(OBJECTS) -o $@

.cpp.o:
	g++ -c $< -o $@

clean:
	rm *.o $(MAINPROG)
