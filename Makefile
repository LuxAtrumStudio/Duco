export COMPILER = clang++
export COMPILER_FLAGS = -MMD -std=c++11 -w -c
CPP_FILES = $(wildcard *.cpp)
TOP_DIR = $(notdir $(CPP_FILES:.cpp=.o))
OBJ_FILES += $(wildcard */*.o)
OBJ_FILES += $(wildcard */*/*.o)
OBJ_FILES += $(wildcard */*/*/*.o)
OBJ_FILES += $(wildcard */*/*/*/*.o)
LINKER_FLAGS =
PROGRAM_NAME = Duco

all: subsystem top_obj $(PROGRAM_NAME)
	@echo Compleated compiling $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ_FILES)
	$(COMPILER) $(TOP_DIR) $(OBJ_FILES) -o $(PROGRAM_NAME) $(LINKER_FLAGS)

.PHONY : top_obj
top_obj:$(TOP_DIR)

%.o: %.cpp
	clang++ -MMD -std=c++11 -w -c -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	cd duco_files && $(MAKE)

.PHONY : clean
clean:
		rm -f *.o
		rm -f *.d
		rm -f */*.o
		rm -f */*.d
		rm -f */*/*.o
		rm -f */*/*.d
		rm -f */*/*/*.o
		rm -f */*/*/*.d
		rm -f */*/*/*/*.o
		rm -f */*/*/*/*.d
		rm -f */*/*/*/*/*.o
		rm -f */*/*/*/*/*.d

.PHONY : new
new: clean all

.PHONY : help
help:
	@echo make
	@echo make clean
	@echo make new
	@echo make help
