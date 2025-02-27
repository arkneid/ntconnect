# Vars
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = 
RM = rm -rf
DFOLDER = dest
NAME = ntconnect
INSTALL_FOLDER = /usr/local

# Source files
SRC_FILES = main.c args_actions.c string_lib.c history.c list_networks.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# make options
all: build

$(OBJ_FILES): $(SRC_FILES)

build: $(OBJ_FILES)
	mkdir -p dest/
	mkdir -p ${HOME}/.local/share/$(NAME)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(DFOLDER)/$(NAME)

install: all
	mkdir -p $(INSTALL_FOLDER)/bin
	cp -f $(DFOLDER)/$(NAME) $(INSTALL_FOLDER)/bin

uninstall: 
	$(RM) $(INSTALL_FOLDER)/bin/$(NAME)
	$(RM) ${HOME}/.local/share/$(NAME)

clean:
	$(RM) $(OBJ_FILES) $(DFOLDER)

.PHONY: all build install clean uninstall
