CC=gcc
CFLAGS :=-Wall -Werror -g

SRC := linked_list.c 
OBJ := ${SRC:c=o}
TARGET := linked_list

$(TARGET): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(TARGET) *.o a.out *~

