# компилятор
CC=gcc

# флаги
CFLAGS=-c -Wall -Werror -g3 

# общие файлы
FILES=main.c menu.c practice.c stats.c texts.c

OBJ=$(patsubst %.c, %.o, $(FILES))
# объектные файлы тестов

# выходной файл
EXECUTABLE=keyboardninja

.PHONY: clean

all: $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJ) $(EXECUTABLE)
