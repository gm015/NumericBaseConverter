TARGET:=main
SRC:= dec_to_bin.c
OBJ:= dec_to_bin.o

all: $(TARGET)

$(TARGET): $(OBJ)
	cc -g $< -o $@

%.o:%.c
	cc -g -c $< $^

c:
	rm $(TARGET) $(OBJ)
