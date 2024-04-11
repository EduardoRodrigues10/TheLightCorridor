CC = gcc
CFLAGS = -ansi -Wall
LDFLAGS = -lGL -lGLEW -lglfw -lm -lGLU -std=c11 -lglut
SRC = src/
BIN = bin/
INCLUDE = include/
OBJFILES = $(BIN)Interaction.o $(BIN)Jeu.o $(BIN)Raquette.o $(BIN)Ballon.o $(BIN)Main.o $(BIN)Couloir.o $(BIN)Obstacle.o $(BIN)Bonus.o $(BIN)Menu.o
TARGET = $(BIN)TheLightCorridor


all: $(BIN)$(TARGET)

$(BIN)$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

$(BIN)Main.o : $(SRC)Main.c $(INCLUDE)Menu.h
	$(CC) $(CFLAGS) -o $(BIN)Main.o -c $(SRC)Main.c $(LDFLAGS)

$(BIN)Interaction.o : $(SRC)Interaction.c $(INCLUDE)Interaction.h $(INCLUDE)Jeu.h
	$(CC) $(CFLAGS) -o $(BIN)Interaction.o -c $(SRC)Interaction.c $(LDFLAGS)

$(BIN)Jeu.o : $(SRC)Jeu.c $(INCLUDE)Jeu.h $(INCLUDE)Bonus.h $(INCLUDE)Menu.h 
	$(CC) $(CFLAGS) -o $(BIN)Jeu.o -c $(SRC)Jeu.c $(LDFLAGS)

$(BIN)Ballon.o : $(SRC)Ballon.c $(INCLUDE)Ballon.h $(INCLUDE)Couloir.h $(INCLUDE)Obstacle.h $(INCLUDE)Raquette.h
	$(CC) $(CFLAGS) -o $(BIN)Ballon.o -c $(SRC)Ballon.c $(LDFLAGS)

$(BIN)Raquette.o : $(SRC)Raquette.c $(INCLUDE)Raquette.h
	$(CC) $(CFLAGS) -o $(BIN)Raquette.o -c $(SRC)Raquette.c $(LDFLAGS)

$(BIN)Obstacle.o : $(SRC)Obstacle.c $(INCLUDE)Obstacle.h
	$(CC) $(CFLAGS) -o $(BIN)Obstacle.o -c $(SRC)Obstacle.c $(LDFLAGS)

$(BIN)Couloir.o : $(SRC)Couloir.c $(INCLUDE)Couloir.h
	$(CC) $(CFLAGS) -o $(BIN)Couloir.o -c $(SRC)Couloir.c $(LDFLAGS)

$(BIN)Bonus.o : $(SRC)Bonus.c $(INCLUDE)Bonus.h $(INCLUDE)Raquette.h $(INCLUDE)Ballon.h
	$(CC) $(CFLAGS) -o $(BIN)Bonus.o -c $(SRC)Bonus.c $(LDFLAGS)

$(BIN)Menu.o : $(SRC)Menu.c $(INCLUDE)Menu.h $(INCLUDE)Interaction.h
	$(CC) $(CFLAGS) -o $(BIN)Menu.o -c $(SRC)Menu.c $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~