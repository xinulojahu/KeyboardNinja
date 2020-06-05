# компилятор
CC=gcc

# флаги
CFLAGS=-c -Wall -Werror 
TFLAGS=-I thirdparty -I src
# путь до объектных файлов
OBJDIR=builder/
# путь до исходников
SRCDIR=src/
# путь до тестов
TSTDIR=test/

# общие файлы
FILES=menu.c language.c practice.c stats.c texts.c
# одинаковые наименования
SMFLS=main.c
# только в тестах
TTFLS=test.c

# объектные файлы приложения
OBJ=$(patsubst %.c, $(OBJDIR)$(SRCDIR)%.o, $(FILES) $(SMFLS))
# объектные файлы тестов
TTOBJ=$(patsubst %.c, $(OBJDIR)$(TSTDIR)%.o, $(FILES) $(SMFLS) $(TTFLS))

# выходной файл
EXECUTABLE=bin/keyboardninja
TTEXE=bin/tests

.PHONY: clean

all: $(EXECUTABLE) $(TTEXE)
 
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

$(TTEXE): $(TTOBJ)
	$(CC) -o $@ $^

$(OBJDIR)$(TSTDIR)%.o: $(TSTDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^ $(TFLAGS)

$(OBJDIR)$(TSTDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJ) $(TTOBJ) $(EXECUTABLE) $(TTEXE)
