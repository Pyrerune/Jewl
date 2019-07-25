FILES=main.cc Interpreter.cc
CXXFLAGS=-o jewl
all:
	${CXX} ${FILES} ${CXXFLAGS}

install: 
	mv jewl ~/sys/bin
	


