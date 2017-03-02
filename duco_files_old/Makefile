CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))

all: $(OBJ_FILES) subsystem

%.o: %.cpp %.hpp
	$(COMPILER) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	@setterm -fore blue
	@printf "CLASSES\n"
	@setterm -fore white
	@cd classes && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS\n"
	@setterm -fore white
	@cd operations && $(MAKE)
