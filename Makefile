#######################################################
## ARGUMENTS

# NAME

NAME	=	minirt

# CC FLAG INC

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
INC		=	-Iinc #-Iminilibx-linux

# DIR

SRC_DIR	=	src/
OBJ_DIR	=	obj/
INC_DIR	=	inc/

# LIB

LIBX_PATH	=	minilibx-linux
LIBFT_PATH	=	libft

LIBX		=	$(LIBX_PATH)/libmlx_Linux.a -lXext -lX11 -lm -lz
LIBFT		=	$(LIBFT_PATH)/libft.a

#

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

LIBS		=	-L libft -lft
RM			=	rm -rf

# HEADER

INC_FILES	=	minirt \
				structs \

HEADER		=	$(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))

#######################################################
## SRCS & OBJS

PARSE		=	parse \
				parse_element \
				parse_object \

VECTOR		=	vector \
				vector_operation \

FILES		=	main \
				check_args \
				utils \
				allocation \
				$(addprefix parse/, $(PARSE)) \
				$(addprefix vector/, $(VECTOR)) \

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#######################################################
## RULES

all : $(LIBFT) $(NAME)
#$(LIBX)
$(LIBX) :
		@make --no-print-directory -C $(LIBX_PATH)

$(LIBFT) :
		@make --no-print-directory -C $(LIBFT_PATH)

$(NAME) : $(OBJ_DIR) $(OBJS) Makefile
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR) \
		$(OBJ_DIR)parse/ \
		$(OBJ_DIR)vector/ \

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

norm :
		norminette $(LIBFT_PATH) inc/ $(SRC_DIR)

clean :
		@make --no-print-directory -C $(LIBFT_PATH) fclean
		$(RM) $(OBJ_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus libft
