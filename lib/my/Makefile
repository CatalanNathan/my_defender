##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

AR = ar src

TARGET = libmy.a

CFLAGS = -W -Werror -Wextra -Wall

CPPFLAGS = -I../../include

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@$(AR) -o $(TARGET) $(OBJ)
	@mv $(TARGET) ../

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)

re : fclean all
