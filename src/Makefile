###################
# Matrix Calculator
#

OBJ_DIR = ../obj
BIN_DIR = ../bin

DIRS = $(OBJ_DIR) $(BIN_DIR)
OBJS = $(OBJ_DIR)/Matrix_Driver.o $(OBJ_DIR)/Matrix_Calculator.o $(OBJ_DIR)/Matrix.o
EXE = $(BIN_DIR)/Matrix_Driver

CC = clang++
CFLAGS = -Wall

.PHONY: all
all: $(DIRS) $(EXE)

.PHONY: run	
run: $(DIRS) $(BIN_DIR)/Matrix_Driver
	@$(BIN_DIR)/Matrix_Driver

# make needed directories
$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(BIN_DIR)/Matrix_Driver: $(OBJS)
	$(CC) $^ -o $@

$(OBJ_DIR)/Matrix_Driver.o: matrix_driver.cpp matrix_calculator.hpp matrix.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Matrix Calculator Object
$(OBJ_DIR)/Matrix_Calculator.o: matrix_calculator.cpp matrix_calculator.hpp matrix.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Matrix Object
$(OBJ_DIR)/Matrix.o: matrix.cpp matrix.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# clean
.PHONY: clean
clean: cleanobjects
	rm -f $(EXE)

.PHONY: cleanobjects
cleanobjects:
	rm -f $(DIRS) $(OBJS)

