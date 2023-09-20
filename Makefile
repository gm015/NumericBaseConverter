TARGET:=main
SRC:= dec_to_bin.c
OBJ:= dec_to_bin.o
CFLAGS:= -Wall -Werror -Wextra -g -D DEBUG=1

all: $(TARGET)

$(TARGET): $(OBJ)
	cc $(CFLAGS) $< -o $@

%.o:%.c
	cc $(CFLAGS) -c $< $^

c:
	rm $(TARGET) $(OBJ)
