CMP=cc -Wall -Werror -Wextra -c
BUILD= cc -Wall -Werror -Wextra -o

SERVER=server
CLIENT=client

SRV_SRC=server.c
SRV_OBJ=server.o

OBJ_ALL= $(SRV_OBJ)

%.o: %.c
	$(CMP) $^

$(SERVER):  $(SRV_OBJ)
	$(BUILD) $(SERVER) $^

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

