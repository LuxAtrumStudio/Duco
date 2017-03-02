CPP_FILES = $(wildcard *.cpp)
DIR_OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: $(DIR_OBJ_FILES) subsystem

%.o: %.cpp %.hpp
	$(COMPILER) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore blue
	@printf "MATRIX\n"
	@setterm -fore white
	@cd matrix && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore green
	@printf "VECTOR\n"
	@setterm -fore white
	@cd vector && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore cyan
	@printf "TRIGONOMETRIC\n"
	@setterm -fore white
	@cd trigonometric && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore red
	@printf "ARITHMETIC\n"
	@setterm -fore white
	@cd arithmetic && $(MAKE)
