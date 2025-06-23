#######################################################
## ARGUMENTS

# NAME

NAME	=	minirt

# CC FLAG INC

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-Iinc -Iminilibx-linux

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
RM			=	rm -rf

# HEADER

INC_FILES	=	minirt \
				structs \

HEADER		=	$(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))

#######################################################
## SRCS & OBJS

MAIN		=	main \
				parse \
				init \
				render \

PARSE		=	parse_element \
				parse_object \
				parse_vect \
				parse_utils \

RENDER		=	ray \
				inter_sphere \
				inter_plane \
				inter_cylinder \
				calcul_color \

VECTOR		=	vector \
				vector_operation \

FILES		=	$(addprefix main/, $(MAIN)) \
				$(addprefix parse/, $(PARSE)) \
				$(addprefix render/, $(RENDER)) \
				$(addprefix vector/, $(VECTOR)) \


SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#######################################################
## RULES

all : $(LIBX) $(LIBFT) $(NAME)

$(LIBFT) :
		@make --no-print-directory -C $(LIBFT_PATH)

$(LIBX) :
		@make --no-print-directory -C $(LIBX_PATH)

$(NAME) : $(OBJ_DIR) $(OBJS) Makefile
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBX) $(LIBFT)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR) \
		$(OBJ_DIR)main/ \
		$(OBJ_DIR)parse/ \
		$(OBJ_DIR)render/ \
		$(OBJ_DIR)vector/ \

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

norm :
		norminette $(LIBFT_PATH) inc/ $(SRC_DIR)

clean :
		@make --no-print-directory -C $(LIBX_PATH) clean
		@make --no-print-directory -C $(LIBFT_PATH) fclean
		$(RM) $(OBJ_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus libft
