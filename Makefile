CMP=cc -Wall -Werror -Wextra -c
BUILD= cc -Wall -Werror -Wextra -o
LIBFT_DIR=./dependencies/libft
PRINTF_DIR=./dependencies/ft_printf

UTILS=utils.c
UTILS_OBJ=$(UTILS:%.c=%.o)

SERVER=server
CLIENT=client

CL_SRC=client.c
CL_OBJ=client.o

SRV_SRC=server.c
SRV_OBJ=server.o

%.o: %.c
	$(CMP) $< -o $@

LIBFT_SRC=$(LIBFT_DIR)/ft_atoi.c   $(LIBFT_DIR)/ft_calloc.c   $(LIBFT_DIR)/ft_memset.c  $(LIBFT_DIR)/ft_strlcat.c  $(LIBFT_DIR)/ft_strlen.c\
$(LIBFT_DIR)/ft_bzero.c  $(LIBFT_DIR)/ft_isdigit.c  $(LIBFT_DIR)/ft_split.c   $(LIBFT_DIR)/ft_strlcpy.c  $(LIBFT_DIR)/ft_strncmp.c\
$(LIBFT_DIR)/ft_itoa.c
LIBFT_OBJ= $(LIBFT_SRC:%.c=%.o)

DEPS=$(LIBFT_OBJS) $(PRINTF_OBJ)

PRINTF_SRC=$(PRINTF_DIR)/format_handler.c  $(PRINTF_DIR)/ft_printf.c  $(PRINTF_DIR)/printers.c
PRINTF_OBJ= $(PRINTF_SRC:%.c=%.o)

OBJ_ALL= $(SRV_OBJ) $(CL_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ) $(UTILS_OBJ)


all: $(SERVER) $(CLIENT)

$(SERVER): $(PRINTF_OBJ) $(LIBFT_OBJ) $(SRV_OBJ) $(UTILS_OBJ)
	$(BUILD) $(SERVER) $^

$(CLIENT): $(PRINTF_OBJ) $(LIBFT_OBJ) $(CL_OBJ) $(UTILS_OBJ)
	$(BUILD) $(CLIENT) $^

printf: $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(BUILD) printf $(LIBFT_OBJ) $(PRINTF_OBJ) $(PRINTF_DIR)/main.c

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) printf
re: fclean all
