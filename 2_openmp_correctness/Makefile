CPPCOMP = g++-5
CPPFLAGS =


es2_1.x: es2_1.cpp
	$(CPPCOMP) -O0 -g $(CPPFLAGS) $^ -o $@

.PHONY: clean xclean

all: es2_1.x

clean:
	rm *.out* *.e* core*.*

xclean:
	rm  *.x
