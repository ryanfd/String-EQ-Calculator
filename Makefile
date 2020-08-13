all:
	swig -c++ -python -py3 -modern parser.i
	g++ -fPIC -c parser.cpp parser_wrap.cxx -I/usr/include/python3.6
	g++ -shared parser.o parser_wrap.o -o _parser.so
	ghc recursiveFuncs.hs

clean:
	rm -f parse