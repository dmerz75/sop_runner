# Makefile

# Declaration of variables
CC       := gcc
CXX      := g++
CL       := clang --analyze
# LINKER := gcc -fPIC
# OBJDIR := obj

# Compiler Flags: Use $(CF) for generic/old architectures
CF       := -g
CC_FLAGS := -g -O3
CFLAGS   := -O2 -g -Wall
CFLAGS_1 := -ansi -std=gnu99
CFLAGS_2 := -ansi -pedantic -std=gnu99 -Wall -W
CFLAGS_3 := -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -g -O2

# Valgrind
VAL      := valgrind --track-origins=yes -v
VALFULL  := valgrind --track-origins=yes --leak-check=full -v
VALMEM   := valgrind --track-origins=yes --tool=memcheck --leak-check=full \
--show-leak-kinds=all --show-reachable=yes --num-callers=20 \
--track-fds=yes -v
VALMASS  := valgrind --tool=massif prog

# c files
CFILES   := $(wildcard src/*.c*)
# CFILES   := $(wildcard src/*.cpp)
SOURCES  := $(CFILES) # $(CFILES2) all CFILES

# o files
OBJECTS  := $(SOURCES:.cpp=.o)

# lib
LIB      := -pthread
# LIB    := -pthread -larmadillo
# LIB    := -pthread -lmongoclient -L lib -lboost_thread-mt \
-lboost_filesystem-mt -lboost_system-mt

# include
INC      := -Iinclude

# DIRS
SRCDIR   := src
BUILDDIR := build
BIN_DIR  := bin
BIN      := run_segment
SRCEXT   := cpp
ODIR     := build
TESTD    := test

# File names
EXEC = sop_runner

# ------------------------------------------------------------------------------
# Macros
MACRO = -D
DCDTEST = -DDCDTEST
DCD     = -DDCDREAD
DCDW    = -DDCDREAD -DDCD_WRITE_B -DDCD_WRITE -DDCD_WRITE_E


# ------------------------------------------------------------------------------
# Main target
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -lm -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CXX) $(CC_FLAGS) $(INC) -c $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

go:
	./$(EXEC)

foo:
	@echo $(CFILES)

main:
	$(CXX) $(CF) $(CFILES) $(LIB) $(INC) -o test/$(EXEC)_one


# ------------------------------------------------------------------------------
# Testing:
dev:
	$(CXX) $(CF) $(INC) $(CFILES) $(DCDW) -o test/$(EXEC)_1
	cd test/ && ./$(EXEC)_1 sop.conf
