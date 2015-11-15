
SRC_PATH=./src/
BIN_PATH=./bin/
TARGET = ${BIN_PATH}/helloworld
OBJECTS = ${SRC_PATH}/helloworld.o ${SRC_PATH}/api.o
${TARGET}:${OBJECTS}
	cc -g -o ${TARGET} ${OBJECTS} 
	@echo "make success"

${OBJECTS}:${SRC_PATH}/api.h


clean:
	rm ${OBJECTS}
	@echo "clean success"
