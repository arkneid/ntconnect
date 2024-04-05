# Vars
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = 
RM = rm -rf
DFOLDER = dest
NAME = nconnect
INSTALL_FOLDER = /usr/local

# Source files
SRC_FILES = main.c args_actions.c string_lib.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# make options
all: build

$(OBJ_FILES): $(SRC_FILES)

build: $(OBJ_FILES)
	mkdir -p dest/
	mkdir -p ${HOME}/.local/share/nconnect
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(DFOLDER)/$(NAME)

install: all
	mkdir -p $(INSTALL_FOLDERS)/bin
	cp -f $(DFOLDER)/$(NAME) $(INSTALL_FOLDERS)/bin

uninstall: 
	$(RM) $(INSTALL_FOLDER)/bin/$(NAME)
	$(RM) ${HOME}/.local/share/nconnect

clean:
	$(RM) $(OBJ_FILES) $(DFOLDER)

.PHONY: all build install clean uninstall
