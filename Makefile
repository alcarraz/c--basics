all: bin/c++-basics

bin/c++-basics: src/c++-basics.cpp
	mkdir -p bin
	g++ src/c++-basics.cpp -o bin/c++-basics

run: bin/c++-basics
	bin/c++-basics

clean:
	rm -rf bin
