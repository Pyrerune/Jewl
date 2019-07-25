FILES=src/main.cc src/Interpreter.cc
CXXFLAGS=-o jewl
all:
	${CXX} ${FILES} ${CXXFLAGS}

install:
	mv jewl ~/sys/bin
test:
	./jewl tests/main.d
