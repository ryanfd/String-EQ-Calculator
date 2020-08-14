all:
	swig -c++ -python -py3 -modern parser.i
	hsc2hs hsFuncs.hsc
	ghc hsFuncs.hs
	ghc -fPIC -no-hs-main hs_wrapper.c hsFuncs.hs -o wrap
	g++ -fPIC -c parser.cpp parser_wrap.cxx -I/usr/include/python3.6
	g++ -shared parser.o parser_wrap.o -o _parser.so
	python3 interface.py

clean:
	rm -f parse