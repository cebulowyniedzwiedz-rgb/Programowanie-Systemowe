USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)

all: data.txt
	cp data.txt $(file)	
clean:
	rm $(USERNAME).*
        
data.txt:
	echo "abcd" > data.txt
