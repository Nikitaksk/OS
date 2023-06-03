.PHONY: run build clean
.IGNORE: clean

run : build
	.build/main

build :
	clang++ -std=c++11 -lboost_chrono -lboost_thread-mt -o .build/main main.cpp

clean :
	rm -r .build
	mkdir .build
