NAME	=	lib_linkedlist.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-I$(DIR_HEADERS)

RM	=	rm -vf

DIR_HEADERS	=	header/

DIR_FILES	=	srcs/

FILES	=	list_init.c		\
	list_push_back.c	\
	list_push_front.c	\
	list_push_at.c		\
	list_concat_back.c	\
	list_concat_front.c	\
	list_concat_at.c	\
	list_pop_back.c		\
	list_pop_front.c	\
	list_get_back.c		\
	list_get_front.c	\
	list_get_at.c		\
	list_iter.c		\
	list_iter_rev.c		\
	list_clear.c		\
	list_remove_range.c	\
	list_remove_at.c	\
	list_delete.c		\
	list_dup.c		\
	list_reverse.c	\
	list_find.c		\
	list_swap.c		\

SRCS	=	$(addprefix $(DIR_FILES), $(FILES))

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo -en "\033[36m"
	ranlib $(NAME)
	@echo  "\033[1;32mLinkedlist library ready !\033[0m"

all:	$(NAME)

clean :
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: 	all clean fclean re
