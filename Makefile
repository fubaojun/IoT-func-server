OS = $(shell uname)
PLATFORM ?= Ubuntu
ifeq "$(PLATFORM)" "LOONGSON"
CC = mipsel-linux-gcc
else
CC = gcc
endif
#CFLAGS += -O2 -static
CFLAGS += -O0 -I . 

PROGRAMDIR := .
PROGRAM := $(PROGRAMDIR)/serverDemo
OBJDIR := ./obj
OBJ := $(PROGRAMDIR)/serverDemo.o $(PROGRAMDIR)/wrap.o $(PROGRAMDIR)/cJSON.o $(PROGRAMDIR)/cJSON_Utils.o $(PROGRAMDIR)/user_webserver.o $(PROGRAMDIR)/user_json.o 


all:$(PROGRAM)

$(PROGRAM):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $(PROGRAM)
	echo "---1---"

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@
	echo "---2---"
	#mv $@ $(PROGRAM)

install:
	ncat -l4p 83 < $(PROGRAM)

clean:
	$(RM) *.o $(PROGRAM) $(OBJ)
