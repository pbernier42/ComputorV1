PROJECT			=	COMPUTERV1

NO_TO_BE		=	ON

DIR_OBJ			=	objs/
DIR_SRC			=	srcs/
DIR_INC			=	includes/

NAME			=	computor

CC				=	gcc
WFLAGS			=	-Wall -Werror -Wextra
DFLAGS			=	$(WFLAGS) -fsanitize=address -g

INCLUDES		=	-I $(DIR_INC)

SRC_INCLUDE		=	computorV1.h
SRC_FIlE		=	main.c \
					init.c \
					read.c \

FLAGS			=	$(WFLAGS)
INC				=	$(addprefix $(DIR_INC),$(SRC_INCLUDE))
SRC				=	$(addprefix $(DIR_SRC),$(SRC_FIlE))
OBJ				=	$(addprefix $(DIR_OBJ),$(notdir $(SRC:.c=.o)))

UND				= \033[4m
RES				= \033[0m

all: $(NAME)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

help:
	@printf "[$(PROJECT)] make \n"
	@printf "    		-- compile the project '$(NAME)'\n"
	@printf "  computor	-- compile the project '$(NAME)'\n"
	@printf "  lldb		-- switch to lldb compile mode\n"
	@printf "  normal	-- switch to normal compile mode\n"
	@printf "  flag		-- shows what flags will be used with \'$(CC)\'\n"
	@printf "  clean		-- remove all file \'.o\' from \'$(DIR_OBJ)\'\n"
	@printf "  fclean	-- $(UND)clean$(RES) and remove '$(NAME)'\n"
	@printf "  re		-- $(UND)fclean$(RES) then $(UND)make$(RES)\n"

$(NAME): $(DIR_OBJ) $(OBJ)
# LIB
	@printf "[$(PROJECT)] Objs compilation done.                    \n"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS)
# LIB
	@printf "[$(PROJECT)] "
ifeq ($(FLAGS),$(DFLAGS))
	@printf "(lldb mode) "
endif
	@printf "$(NAME) compiled.\n"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC) Makefile
	@printf "[$(PROJECT)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

# LIB

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

lldb:
#	@make -C $(LIB_MAKE) lldb
ifeq ($(FLAGS),$(WFLAGS))
	@sed '/^FLAGS/ s/WFLAGS/DFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT)] Swap to lldb mode.\n"
	@make
else
	@printf "[$(PROJECT)] Already in lldb mode.\n"
endif

normal:
#	@make -C $(LIB_MAKE) normal
ifeq ($(FLAGS),$(DFLAGS))
	@sed '/^FLAGS/ s/DFLAGS/WFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT)] Swap to normal mode.\n"
	@make
else
	@printf "[$(PROJECT)] Already in normal mode.\n"
endif

flag:
	@printf "[$(PROJECT)] "
ifeq ($(FLAGS),$(WFLAGS))
	@printf "Normal mode activated {$(FLAGS)}.\n"
else
	@printf "Lldb mode activated {$(FLAGS)}.\n"
endif

clean:
	@rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(PROJECT)] $(NAME)) removed.\n"

re: fclean $(NAME)

.PHONY: all $(NAME) lldb clean fclean re
