mkfile_path = $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir = $(dir $(mkfile_path))

all : $(mkfile_dir)src/Project_Hex.cc
	g++ $(mkfile_dir)src/Project_Hex.cc -o Project_Hex.out

clean :
	rm -f *.o

#Work in progress
