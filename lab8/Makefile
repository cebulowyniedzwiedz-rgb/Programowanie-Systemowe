SRCDIR := SRC
OUTDIR := build
TARGET := main
CC := gcc
CFLAGS := -Wall -Wextra -std=c11

SOURCES := main.c server.c worker.c
OBJECTS := $(SOURCES:.c=.o)
OBJECTS := $(addprefix $(OUTDIR)/,$(OBJECTS))

all: $(OUTDIR) $(OUTDIR)/$(TARGET)

$(OUTDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	rm -rf $(OUTDIR)
