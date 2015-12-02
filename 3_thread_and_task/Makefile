CPPCOMP = g++
CPPFLAGS =


es3_1.x: es3_1.cpp
	$(CPPCOMP) -O -fopenmp -g $(CPPFLAGS) $^ -o $@

es3_2.x: es3_2.cpp
	$(CPPCOMP) -O -fopenmp -g $(CPPFLAGS) $^ -o $@

.PHONY: clean xclean

all: es3_1.x es3_2.x

clean:
	rm *.out* *.e* core*.* *.mxt

xclean:
	rm  *.x *.mxt
