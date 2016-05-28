CC=g++
CFLAGS=-I.
LDFLAGS = -lSDL2 -lSDL2_image
SRC = $(shell find . -name "*cpp")
DEPS = $(patsubst %.cpp, %.o, $(SRC))

all: $(DEPS)
	$(CC) -o CitiesAndRockets $(DEPS) $(LDFLAGS) $(CFLAGS)
clean:
	rm *.o
