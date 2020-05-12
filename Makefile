SRCDIR = ./src
TESTSDIR = ./tests

CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++2a

TESTFILES = $(TESTSDIR)/main.cpp
SRCFILES = $(addprefix $(SRCDIR)/, Measurement.hpp Unit.hpp Product.hpp \
units.hpp)

test: $(TESTFILES) $(SRCFILES)
	$(CC) $(CFLAGS) $(TESTFILES) -I $(SRCDIR) -o ./test

clean:
	rm -f ./test

.PHONY: clean
