Readme for PPC-2021 HW02:

How to compile:
g++ -g main.cpp doprava.cpp -o main -std=c++17 -Wall -Wpedantic
or use makefile:
make all

How to test:
.\main --schedule "Petrackovo namesti" "Vitkov" "U Bufetu"  > out1.txt
.\main --line-routing  > out2.txt
.\main --driver-stops  > out3.txt
or use makefile:
make run


Feel free to change the stop names in test #1. The names of the stations are available in the provided file out2.txt.
Alternative variant of calling --schedule option is:
.\main --schedule Petrackovo_namesti Vitkov U_Bufetu > out1.txt
