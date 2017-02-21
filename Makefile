#
# Makefile
# lishuming02, 2017-02-03 16:59
#

.PHONY: all clean cpp

all: cpp
	
cpp:
	cd cpp/ && g++ -o main ./main.cpp
	cd cpp/ && ./main

clean:
	find . -name ".*~"|xargs rm
	find . -name ".*sw*"|xargs rm
	find . -name "core.*"|xargs rm
	cd cpp/ && rm ./main

# vim:ft=make
#
