CC=gcc
GFLAGS=-c -Wall -O2
SOURCES=utilities.c angle.c vector2.c vector3.c complex.c cotes-number.c \
        matrix2x2.c matrix2x3.c matrix3x2.c matrix3x3.c matrixes.c \
        rotation3.c quaternion.c versor.c
OBJECTS=$(SOURCES:.c=.o)
OBJECT_DIRECTORY=obj/Release
BINARY_DIRECTORY=bin/Release
BACK_PATH=../..
LIBRARY=libbasic-geometry.a

all: directories $(SOURCES) $(LIBRARY)
$(LIBRARY): $(OBJECTS)
	cd ./$(OBJECT_DIRECTORY); \
	ar -rv -s $(BACK_PATH)/$(BINARY_DIRECTORY)/$@ $(OBJECTS); \
	cd $(BACK_PATH)

directories:
	mkdir -p $(OBJECT_DIRECTORY)
	mkdir -p $(BINARY_DIRECTORY)

.c.o:
	$(CC) $(GFLAGS) $< -o $(OBJECT_DIRECTORY)/$@

clean:
	rm -rf ./obj ./bin
