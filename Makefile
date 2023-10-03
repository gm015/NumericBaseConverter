.PHONY: all clean debug

TARGET	:=main
INC		:=./inc
HEADER	:=$(INC)/header.h
OBJ_DIR	:=build
SRC_DIR	:=src

SRC		:= main.c utils.c binary.c hex.c octal.c #tests.c
OBJ		:= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
CFLAGS	:= -Wall -Werror -Wextra -Wno-implicit-fallthrough -g #-Wno-unused-parameter
DEBUG_VAL	=0
DEBUG_PARS	=0
DEBUG		= -D DEBUG_VAL=$(DEBUG_VAL) -D DEBUG_PARS=$(DEBUG_PARS)

all: $(OBJ_DIR) $(TARGET)

debug-pars: clean
	@$(MAKE) DEBUG_PARS=1 all

debug-val: clean
	@$(MAKE) DEBUG_VAL=1 all

$(TARGET): $(OBJ)
	cc $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HEADER) 
	cc $(CFLAGS) -I $(INC) $(DEBUG) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJ_DIR)

