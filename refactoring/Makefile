all: parser

clean:
	rm -f lchild.yy.cpp lchild.tab.{cpp,hpp} parser example.txt

lchild.yy.cpp: lchild.l
	flex -o lchild.yy.cpp lchild.l

lchild.tab.cpp: lchild.y
	yacc -o lchild.tab.cpp -d lchild.y

parser: lchild.yy.cpp lchild.tab.cpp
	g++ -D_GLIBCXX_USE_CXX11_ABI=0 -w -o parser lchild.yy.cpp lchild.tab.cpp
