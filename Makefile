initials = RL
execs = string_01

all: $(execs)
.PHONY: all

clean:
	rm $(execs)

$(objects): % : %.cc
	g++ -std=c++11 $< -o $@
