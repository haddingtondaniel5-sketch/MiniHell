# Define the target executable
TARGET := MiniHell

# Compiler
C_COMPILER := clang

# Compiler & Linker flags
CFLAGS := -I/opt/homebrew/Cellar/raylib/5.5/include
LDFLAGS := -L/opt/homebrew/Cellar/raylib/5.5/lib  -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

FLAGS := -Wextra -Wall -Werror
ADDSAN := -fsanitize=address

# Directories
SRC_DIR := source/
OBJ_DIR := object/

# Source and object files
SOURCE := $(wildcard $(SRC_DIR)*.c)
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) $(FLAGS) $(ADDSAN) -o $(TARGET) $(OBJECTS) $(CFLAGS) $(LDFLAGS)

# Build all
all: $(TARGET)

test: all
	./MiniHell

# Build executable
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE..."
	$(LINK)

# Compile object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECT ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)

brewlibs:
	brew install raylib

.PHONY: clean all
.SILENT: