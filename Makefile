initials = RL
execs = string_01 tests_string

all: $(execs)
.PHONY: all

clean:
	rm $(execs)

% : %.cc
	g++ -g -std=c++11 $< -o $@

string_01 :	string_01 string_01.h
tests_string : 	tests_string.cc string_01.h
