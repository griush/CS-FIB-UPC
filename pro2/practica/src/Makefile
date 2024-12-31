OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o valley.o city.o
	g++ *.o -o program.exe

%.o: %.cc
	g++ -c $^ -o $@  $(OPCIONS)

clean:
	rm program.exe
	rm *.o
	rm -fr dist/

tar:
	mkdir -p dist/
	tar -cvf dist/practica.tar *.cc *.hh Makefile html.zip justificacio.pdf
