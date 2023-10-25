all: bin/c++-basics

GPP_OPTS = -std=c++23 -pedantic -Wall -Wextra 


bin/c++-basics: src/c++-basics.cpp
	mkdir -p bin
	g++ $(GPP_OPTS) src/c++-basics.cpp -o bin/c++-basics

run: bin/c++-basics
	bin/c++-basics

clean:
	rm -rf bin
