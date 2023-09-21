.PHONY: all c debug

TARGET:=main
DEBUG=0
SRC:= dec_to_bin.c
OBJ:= dec_to_bin.o
CFLAGS:= -Wall -Werror -Wextra -g 

all: $(TARGET)

debug: c
	@$(MAKE) DEBUG=1 all

$(TARGET): $(OBJ)
	cc $(CFLAGS) $< -o $@

%.o:%.c
	cc $(CFLAGS) -D DEBUG=$(DEBUG) -c $< $^

c:
	rm $(TARGET) $(OBJ)

