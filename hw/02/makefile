CXX = clang++
CXXFLAGS= -g -std=c++17 -Wall -Wpedantic
SOURCES = $(wildcard *.cpp)

main: $(SOURCES) 
	$(CXX) $^ -o $@ $(CXXFLAGS)

out1.txt: main network.txt driver_list.txt
	./main --schedule "Petrackovo namesti" "Vitkov" "U Bufetu" > out1.txt
	
out2.txt: main network.txt driver_list.txt
	./main --line-routing  > out2.txt

out3.txt: main network.txt driver_list.txt
	./main --driver-stops  > out3.txt

all: main

run: out1.txt out2.txt out3.txt

clean:
	rm -f main out1.txt out2.txt out3.txt
