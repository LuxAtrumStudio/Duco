CPP_FILES = $(wildcard *.cpp)
DIR_OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: $(DIR_OBJ_FILES) subsystem

%.o: %.cpp %.hpp
	$(COMPILER) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	@setterm -fore blue
	@printf "CLASSES/"
	@setterm -fore blue
	@printf "MATRIX\n"
	@setterm -fore white
	@cd matrix && $(MAKE)
	@setterm -fore blue
	@printf "CLASSES/"
	@setterm -fore green
	@printf "VECTOR\n"
	@setterm -fore white
	@cd vector && $(MAKE)
	@setterm -fore blue
	@printf "CLASSES/"
	@setterm -fore cyan
	@printf "EQUATION\n"
	@setterm -fore white
	@cd equation && $(MAKE)
