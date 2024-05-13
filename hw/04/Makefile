CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++17
SOURCES = main.cpp
OBJECTS = $(addprefix build/,$(SOURCES:.cpp=.o))

TARGET = matrix
BUILD_DIR = build

all: $(TARGET)
	mv $^ matrices

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJECTS): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(TARGET) $(BUILD_DIR)
