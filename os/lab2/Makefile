all: main child
	echo 5 0 | ./child &
	echo 10 0 | ./child &
	./main

clean:
	rm -f main child

main: main.cc pipes.cc
	g++ -o main main.cc

child: child.cc pipes.cc
	g++ -o child child.cc
