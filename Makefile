SRCS = ft_puterror.c parse_utils.c parse.c utils.c listfunctions.c createlist.c pscommand.c \
pscommand2.c core.c testing.c insertion.c insertion2.c

MAIN = main.c

DIRECTORYS = srcs/

SRCSD =	$(addprefix ${DIRECTORYS}, $(SRCS))

EFLAGS = -Wall -Wextra -Werror

OBJS =	${SRCSD:.c=.o}

OFLAGS = -c

NAME   = push_swap

%.o: %.c ${HEADER}
	gcc ${OFLAGS} ${EFLAGS} -o $@ $<

${NAME}: ${OBJS}
	gcc $(EFLAGS) -o $(NAME) $(MAIN) ${SRCSD}
			
all:	${NAME}

clean:
		rm  -f ${OBJS}

fclean:	clean
		rm  -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re