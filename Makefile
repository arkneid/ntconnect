# Vars
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
DFOLDER = dest

# Source files
SRC_FILES = main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# make options
all: clean build

$(OBJ_FILES): $(SRC_FILES)

build: $(OBJ_FILES)
	mkdir -p dest/
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(DFOLDER)/nconnect

clean:
	$(RM) $(OBJ_FILES) $(DFOLDER)
