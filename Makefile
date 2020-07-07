all:
	g++ parser.cpp test.cpp -o parse

clean:
	rm -f parse