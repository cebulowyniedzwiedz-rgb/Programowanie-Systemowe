USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)

all:
	touch $(file)
  
clean:
	rm $(USERNAME).*
