.PHONY: run build clean
.IGNORE: clean

run : build
	.build/main
	
build :
	clang++ -std=c++11 -o .build/main main.cpp

clean :
	rm -r .build
	mkdir .build