CPP_FILES = $(wildcard *.cpp)
DIR_OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: subsystem $(DIR_OBJ_FILES)

%.o: %.cpp %.hpp
	$(COMPILER) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
