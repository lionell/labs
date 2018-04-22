all: parser

clean:
	rm -f field.yy.cpp field.tab.{cpp,hpp} parser example.txt

field.yy.cpp: field.l
	flex -o field.yy.cpp field.l

field.tab.cpp: field.y
	yacc -o field.tab.cpp -d field.y

parser: field.yy.cpp field.tab.cpp
	g++ -D_GLIBCXX_USE_CXX11_ABI=0 -w -o parser field.yy.cpp field.tab.cpp
