
SRC_DIR := .
OBJ_DIR := .
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

CPPFLAGS += -std=c++11
CXXFLAGS += -MMD

main.out: $(OBJ_FILES)
	g++ -o $@ $^

run :
	@./main.out 
clean : 
	@rm -f *.o
	@rm -f *.out
	@rm -f output.txt
	@rm -f *.d