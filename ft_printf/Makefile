NAME =	libftprintf.a 

CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS = -Werror -Wextra -Wall
OBJS = $(SRCS:.c=.o)
RM = rm -rf
LIBFT = ./libft/libft.a

SRCS = ft_printf.c ft_printf_csdiu.c ft_printf_tool.c ft_printf_xp.c

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) bonus -C ./libft
	cp ~/projets42/libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean : 
	$(MAKE) -C libft clean
	$(RM) $(OBJS) $(OBJSBONUS)

fclean : clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) a.out *.gch

re : fclean all

.PHONY : all clean fclean re bonus
