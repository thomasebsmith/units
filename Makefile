SRCDIR = ./src
TESTSDIR = ./tests

CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++2a

TESTFILES = $(TESTSDIR)/main.cpp
TESTHEADERS = $(TESTSDIR)/utils.hpp
SRCFILES = $(addprefix $(SRCDIR)/, Measurement.hpp Unit.hpp Product.hpp \
Quotient.hpp Power.hpp Operators.hpp DerivedUnits.hpp units.hpp)

test: $(TESTFILES) $(SRCFILES) $(TESTHEADERS)
	$(CC) $(CFLAGS) $(TESTFILES) -I $(SRCDIR) -o ./test

clean:
	rm -f ./test

.PHONY: clean
