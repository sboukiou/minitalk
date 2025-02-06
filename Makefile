CMP=cc -Wall -Werror -Wextra -c
BUILD= cc -Wall -Werror -Wextra -o

SERVER=server
CLIENT=client

CL_SRC=client.c
CL_OBJ=client.o

SRV_SRC=server.c
SRV_OBJ=server.o

OBJ_ALL= $(SRV_OBJ) $(CL_OBJ)

%.o: %.c
	$(CMP) $<

$(SERVER):  $(SRV_OBJ)
	$(BUILD) $(SERVER) $^

$(CLIENT):  $(CL_OBJ)
	$(BUILD) $(CLIENT) $^

all: $(SERVER) $(CLIENT)

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

