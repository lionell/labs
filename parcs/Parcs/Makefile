all: Fibon.jar
	@echo All done.

clean:
	rm -f parcs.jar {TCP,UDP}HostsServer.jar Daemon.jar Fibon/Fibon.jar

parcs.jar: parcs/*.class
	@jar cvf parcs.jar parcs/*.class

Fibon/Fibon.jar: parcs.jar Fibon/*.java
	@echo Building Fibon example...
	@javac -encoding WINDOWS-1251 -cp parcs.jar Fibon/*.java
	@cd Fibon && jar cf Fibon.jar *.class server
	@rm Fibon/*.class

TCPHostsServer.jar: HostsServer/*.class parcs/*.class
	@jar cvef HostsServer.TCPHostsServer TCPHostsServer.jar HostsServer/*.class parcs/*.class

UDPHostsServer.jar: HostsServer/*.class parcs/*.class
	@jar cvef HostsServer.UDPHostsServer UDPHostsServer.jar HostsServer/*.class parcs/*.class

Daemon.jar: Daemon/*.class parcs/*.class
	@jar cvef Daemon Daemon.jar -C Daemon . parcs/*.class
