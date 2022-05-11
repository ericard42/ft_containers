NAME_VEC	=	vector_test
NAME_VEC_S	=	vector_test_std
NAME_MAP	=	map_test
NAME_MAP_S	=	map_test_std
NAME_STACK	=	stack_test
NAME_STACK_S=	stack_test_std

CC			=	c++

FLAGS		=	-Werror -Wextra -Wall -std=c++98
FLAGS_STD	=	-Werror -Wextra -Wall -std=c++98 -D STD

SRCS_VEC	=	mains/vector_main.cpp
SRCS_MAP	=	mains/map_main.cpp
SRCS_STACK	=	mains/stack_main.cpp


all		:	$(NAME_VEC)
			$(NAME_MAP)
			$(NAME_STACK)

$(NAME_VEC)	:	$(SRCS_VEC)
				$(CC) $(FLAGS) $(SRCS_VEC) -o $(NAME_VEC)
				$(CC) $(FLAGS_STD) $(SRCS_VEC) -o $(NAME_VEC_S)
				./$(NAME_VEC) > $(NAME_VEC).log
				./$(NAME_VEC_S) > $(NAME_VEC_S).log

$(NAME_MAP)	:	$(SRCS_MAP)
				$(CC) $(FLAGS) $(SRCS_MAP) -o $(NAME_MAP)
				$(CC) $(FLAGS_STD) $(SRCS_MAP) -o $(NAME_MAP_S)
				./$(NAME_MAP) > $(NAME_MAP).log
				./$(NAME_MAP_S) > $(NAME_MAP_S).log

$(NAME_STACK):	$(SRCS_STACK)
				$(CC) $(FLAGS) $(SRCS_STACK) -o $(NAME_STACK)
				$(CC) $(FLAGS_STD) $(SRCS_STACK) -o $(NAME_STACK_S)
				./$(NAME_STACK) > $(NAME_STACK).log
				./$(NAME_STACK_S) > $(NAME_STACK_S).log

clean		:
				rm -rf $(NAME_VEC).log $(NAME_VEC_S).log
				rm -rf $(NAME_MAP).log $(NAME_MAP_S).log
				rm -rf $(NAME_STACK).log $(NAME_STACK_S).log

fclean		:	clean
				rm -rf $(NAME_VEC) $(NAME_VEC_S)
				rm -rf $(NAME_MAP) $(NAME_MAP_S)
				rm -rf $(NAME_STACK) $(NAME_STACK_S)


re			:	fclean all

.PHONY		: all clean fclean re