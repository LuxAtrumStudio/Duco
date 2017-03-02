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
	@printf "ARITHMETIC\n"
	@setterm -fore white
	@cd arithmetic && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore green
	@printf "TRIGONOMETRY\n"
	@setterm -fore white
	@cd trigonometry && $(MAKE)
	@setterm -fore green
	@printf "OPERATIONS/"
	@setterm -fore cyan
	@printf "METHOD\n"
	@setterm -fore white
	@cd method && $(MAKE)
