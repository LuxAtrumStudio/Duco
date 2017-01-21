CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))
COMPILER_FLAGS = -MMD -std=c++11 -w -c
all:subsystem main
main:$(OBJ_FILES)
%.o: %.cpp %.hpp
	$(CC) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp
.PHONY : subsystem
subsystem:
	export CC
	cd vector && $(MAKE)
	cd manipulation && $(MAKE)
	cd notation && $(MAKE)
	cd matrix && $(MAKE)
	cd trigonometry && $(MAKE)
	cd exponential && $(MAKE)
