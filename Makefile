SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*/*.cpp) $(wildcard */*/*/*/*.cpp) $(wildcard */*/*/*/*/*.cpp)
FOLDERS = $(wildcard */) $(wildcard */*/) $(wildcard */*/*/) $(wildcard */*/*/*/) $(wildcard */*/*/*/*/) $(wildcard */*/*/*/*/*/)
INT_FOLDERS = $(addprefix ./Intermediate/, $(FOLDERS))
OBJECTS = $(addprefix ./Intermediate/, $(SOURCES:.cpp=.o))

LDFLAGS = -I./Include -lGL -lGLEW -lglfw

EXEC_NAME = CMUTestApp

prepare :
	mkdir ./Intermediate
	$(foreach folder, $(INT_FOLDERS), mkdir $(folder);)

compile : prepare
	$(foreach src, $(SOURCES), g++ $(LDFLAGS) -c -o $(addprefix ./Intermediate/, $(src:.cpp=.o)) $(src);)

build : compile
	g++ -g $(OBJECTS) $(LDFLAGS) -o $(EXEC_NAME)
	make clean

.PHONY: clean
clean :
	rm -f $(OBJECTS)
	rm -rf ./Intermediate/*
	rm -rf ./Intermediate

run :
	./$(EXEC_NAME)

all : build run