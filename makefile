mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

all : $(mkfile_dir)src/ProjectHex.cc
	g++ $(mkfile_dir)src/ProjectHex.cc -o ProjectHex.out

clean :
	rm -f *.o

#Work in progress
