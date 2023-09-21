.PHONY: all clean debug

TARGET:=main
INC:=./inc
HEADER:=$(INC)/header.h
OBJ_DIR:=build
SRC_DIR:=src

SRC:= main.c utils.c tests.c
OBJ:= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
CFLAGS:= -Wall -Werror -Wextra -g
DEBUG=0

all: $(OBJ_DIR) $(TARGET)

debug: clean
	@$(MAKE) DEBUG=1 all

$(TARGET): $(OBJ)
	cc $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HEADER) 
	cc $(CFLAGS) -I $(INC) -D DEBUG=$(DEBUG) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET) $(OBJ_DIR)

