OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O3 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o valley.o city.o
	mkdir -p bin/
	g++ obj/*.o -o bin/program.exe

%.o: src/%.cc
	mkdir -p obj/
	g++ -c $^ -o obj/$@  $(OPCIONS) -ggdb

clean:
	rm -rf dist/
	rm -rf obj/
	rm -rf bin/

run: program.exe
	./bin/program.exe

# tests
public: program.exe
	./bin/program.exe < sample/sample.inp > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/sample.cor result.out --color -y --left-column --width=120 --minimal

test3: program.exe
	./bin/program.exe < sample/test3.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/correcta3.txt result.out --color -y --left-column --width=120 --minimal

test4: program.exe
	./bin/program.exe < sample/test4.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/correcta4.txt result.out --color -y --left-column --width=120 --minimal

test5: program.exe
	./bin/program.exe < sample/test5.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/correcta5.txt result.out --color -y --left-column --width=120 --minimal

privat: program.exe
	./bin/program.exe < sample/privat.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/privat_out.txt result.out --color -y --left-column --width=120 --minimal

inputA: program.exe
	./bin/program.exe < sample/inputA.inp > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/outputA.cor result.out --color -y --left-column --width=120 --minimal

inputB: program.exe
	./bin/program.exe < sample/inputB.inp > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/outputB.cor result.out --color -y --left-column --width=120 --minimal

inputD: program.exe
	./bin/program.exe < sample/inputD.inp > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/outputD.cor result.out --color -y --left-column --width=120 --minimal

inputF: program.exe
	./bin/program.exe < sample/inputF.inp > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/outputF.cor result.out --color -y --left-column --width=120 --minimal

testgen1: program.exe
	./bin/program.exe < sample/testgen1.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen1_out.txt result.out --color -y --left-column --width=120 --minimal

testgen2: program.exe
	./bin/program.exe < sample/testgen2.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen2_out.txt result.out --color -y --left-column --width=120 --minimal

testgen3: program.exe
	./bin/program.exe < sample/testgen3.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen3_out.txt result.out --color -y --left-column --width=120 --minimal

testgen4: program.exe
	./bin/program.exe < sample/testgen4.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen4_out.txt result.out --color -y --left-column --width=120 --minimal

testgen5: program.exe
	./bin/program.exe < sample/testgen5.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen5_out.txt result.out --color -y --left-column --width=120 --minimal

testgen6: program.exe
	./bin/program.exe < sample/testgen6.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen6_out.txt result.out --color -y --left-column --width=120 --minimal

testgen7: program.exe
	./bin/program.exe < sample/testgen7.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen7_out.txt result.out --color -y --left-column --width=120 --minimal

testgen8: program.exe
	./bin/program.exe < sample/testgen8.txt > result.out
	clear
	#-------------------- <<COR | OUT >> ---------------#
	diff sample/testgen8_out.txt result.out --color -y --left-column --width=120 --minimal
