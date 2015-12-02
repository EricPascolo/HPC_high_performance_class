CPPCOMP = g++

es1.x: es1.cpp
	$(CPPCOMP) -O0 -g $(CPPFLAGS) $^ -o $@

.PHONY: clean xclean

all: es1.x
clean:
	rm *.out* *.e* core*.*

xclean:
	rm  *.x
