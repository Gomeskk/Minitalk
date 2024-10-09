# ------------------------------ Sources ------------------------------

# Files
SERVER		=	server.c

CLIENT		=	client.c

CLIENT_BONUS	=	client_bonus.c  

SERVER_BONUS	=	server_bonus.c

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

FT_PRINTF_SRC	=	libft/printf/ft_printf.c

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

CLIENT_BONUS_OBJS =	$(CLIENT_BONUS:.c=.o)

SERVER_BONUS_OBJS =	$(SERVER_BONUS:.c=.o) 

FT_PRINTF_OBJS	=	$(FT_PRINTF_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS) \
				$(FT_PRINTF_OBJS) \

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

SERVER_BONUS_NAME	=	server_bonus

CLIENT_BONUS_NAME	=	client_bonus

NAME		=	server

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLI_BONUS_READY	=	echo "\n📟 Bonus Client ready!\n"

SERV_BONUS_READY	=	echo "\n📥 Bonus Server ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------


all: $(NAME)

$(NAME): comp_start ft_server ft_client

comp_start:
	@$(COMP_START)
	@$(LIBFT)

ft_server: $(SERVER_OBJS) $(FT_PRINTF_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(FT_PRINTF_OBJS) $(LIB) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client: $(CLIENT_OBJS) $(FT_PRINTF_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(FT_PRINTF_OBJS) $(LIB) -o $(CLIENT_NAME)
	@$(CLI_READY)

ft_server_bonus: $(SERVER_BONUS_OBJS) $(FT_PRINTF_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_BONUS_OBJS) $(FT_PRINTF_OBJS) $(LIB) -o $(SERVER_BONUS_NAME)
	@$(SERV_BONUS_READY)

ft_client_bonus: $(CLIENT_BONUS_OBJS) $(FT_PRINTF_OBJS)  
	@$(GCC) $(FLAGS) $(CLIENT_BONUS_OBJS) $(FT_PRINTF_OBJS) $(LIB) -o $(CLIENT_BONUS_NAME)
	@$(CLI_BONUS_READY)

clean:
	@rm -rf $(OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)  # Clean bonus objects too
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)  # Clean bonus executables too
	@cd libft && make fclean
	@$(FCLEANED)

.c.o:
	@$(GCC) $(FLAGS) $(INCLUDE) -c $< -o $@

re: fclean all

bonus: ft_client_bonus ft_server_bonus

.PHONY: all minitalk server client clean fclean re bonus
