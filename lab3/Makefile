SRCDIR := SRC
OUTDIR := build
TARGET := helloworld
CC := gcc

all: $(TARGET)

$(TARGET): $(TARGET).o $(OUTDIR)
	$(CC) $(OUTDIR)/$(TARGET).o -o $(OUTDIR)/$(TARGET)
$(TARGET).o: $(OUTDIR)
	$(CC) -c $(SRCDIR)/$(TARGET).c -o $(OUTDIR)/$(TARGET).o
clean:
	rm $(OUTDIR)/$(TARGET)
$(OUTDIR):
	mkdir $(OUTDIR)
