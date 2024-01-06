APPS = ./apps
BIN = ./bin
INCLUDES = ./includes
OBJ = ./obj
SRC = ./src


all: 
	gcc -o3 -c $(SRC)/lista_encadeada_simples.c -I $(INCLUDES) -o $(OBJ)/lista_encadeada_simples.o
	gcc -o3 $(APPS)/programa.c $(OBJ)/*.o -I $(INCLUDES) -o $(BIN)/programa


run:
	./$(BIN)/programa



clean: 
	rm $(BIN)/* $(OBJ)/* 

