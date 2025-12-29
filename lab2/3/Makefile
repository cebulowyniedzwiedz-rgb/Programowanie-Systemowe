USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)
folder := build

all: data.txt $(folder)

	cp data.txt $(folder)/$(file)    
clean:
	rm -rf $(folder) data.txt
        
data.txt:
	echo "abcd" > data.txt
$(folder):
	mkdir $(folder)
