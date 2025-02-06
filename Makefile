# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Wno-unused-variable -Wno-unused-function

# Source files
SRCS = main.c basic_processes_posix.c semaphores_posix_example.c pThreadExample_failsafe.c dining_philo.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = lecture4

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean