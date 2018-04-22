all: run

clean:
	rm -f out/Bluck.jar out/DFS.jar

out/Bluck.jar: out/parcs.jar src/Bluck.java src/Node.java
	@javac -cp out/parcs.jar src/Bluck.java src/Node.java
	@jar cf out/Bluck.jar -C src Bluck.class -C src Node.class
	@rm -f src/Bluck.class src/Node.class

out/DFS.jar: out/parcs.jar src/DFS.java src/Node.java
	@javac -cp out/parcs.jar src/DFS.java src/Node.java
	@jar cf out/DFS.jar -C src DFS.class -C src Node.class
	@rm -f src/DFS.class src/Node.class

build: out/Bluck.jar out/DFS.jar

run: out/Bluck.jar out/DFS.jar
	@cd out && java -cp 'parcs.jar:Bluck.jar' Bluck
