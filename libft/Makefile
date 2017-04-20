# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 18:11:45 by blee              #+#    #+#              #
#    Updated: 2017/03/20 20:08:08 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_is{alnum,alpha,ascii,digit,print}.c \
	  ft_itoa.c \
	  ft_lst{add,del,delone,iter,map,new}.c \
	  ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
	  ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,str,str_fd}.c \
	  ft_str{cat,chr,clr,cmp,cpy,del,dup,equ,iter,iteri,join}.c \
	  ft_str{lcat,len,map,mapi}.c \
	  ft_strn{cat,cmp,cpy,equ,ew,str}.c \
	  ft_str{rchr,split,str,sub,trim}.c \
	  ft_to{lower,upper}.c \
	  ft_abs.c \
	  ft_swap.c \
	  ft_sort_int.c \
	  ft_numlen.c \
	  ft_strsplit_lst.c \
	  ft_isprime.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
