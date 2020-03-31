CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I .       # compile with project directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable
COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test_tax : bin/test_tax.o bin/tax.o
	$(LINK) $@ $^

bin/test_tax.o : src/test_tax.cc inc/test_tax.h inc/tax.h
	$(COMPILE) -o $@ $<

bin/tax.o : src/tax.cc inc/tax.h
	cpplint --root=../ $^
	$(COMPILE) -o $@ $<

archive : clean
	zip -r ../hw4.zip ./

clean:
	rm -f bin/* test_tax
