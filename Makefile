##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

TARGET = my_defender

CFLAGS = -g3 -Wno-unused -Werror -Wextra -Wall

LDFLAGS = -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

CPPFLAGS = -I./include -I./csfml_engine/include

SRC = $(wildcard csfml_engine/lib/*.c) \
		csfml_engine/src/update.c \
		csfml_engine/src/create.c \
		csfml_engine/src/mconstruct.c \
		csfml_engine/src/create_defense.c \
		csfml_engine/src/manage_button.c \
		csfml_engine/src/parse_all.c \
		csfml_engine/src/manage_enemy.c \
		csfml_engine/src/create_all_instance.c \
		csfml_engine/src/init_system.c \
		csfml_engine/src/selected_tower.c \
		csfml_engine/src/change_cursor.c \
		csfml_engine/src/mouse_event.c \
		src/main.c \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@make -C lib/my
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS) -lmy -L./lib

clean :
	@make clean -C lib/my
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)
	@$(RM) lib/libmy.a


re : fclean all
