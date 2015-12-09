
SRC_PATH=./src
BIN_PATH=./bin
BIN_FILE=helloworld

SOURCE := $(wildcard ./*.c)
SOURCE += $(wildcard ${SRC_PATH}/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCE))

TARGET = ${BIN_PATH}/${BIN_FILE}

CC = gcc
CFLAGS = -g -Wall


## set .c .h search path
## VPATH=${SRC_PATH}:${SRC_PATH}/include/
vpath %.h ${SRC_PATH}
vpath %.c ${SRC_PATH}

${TARGET}:${OBJECTS}
	${CC} -o ${TARGET} ${OBJECTS} 
	@echo "make ${BIN_FILE} success"

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm ${OBJECTS}
	@echo "clean success"
