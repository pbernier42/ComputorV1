PROJECT			=	COMPUTERV1

NO_TO_BE		=	ON

DIR_OBJ			=	objs
DIR_SRC			=	srcs
DIR_INC			=	includes

NAME			=	computor

CC				=	gcc
WFLAGS			=	-Wall -Werror -Wextra
DFLAGS			=	$(WFLAGS) -fsanitize=address -g

INCLUDES		=	-I $(DIR_INC)

SRC_INCLUDE		=	computorV1.h
SRC_FIlE		=	main.c
