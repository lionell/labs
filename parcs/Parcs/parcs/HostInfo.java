package parcs;
import java.net.*;
import java.io.*;

/**
 * @(#)HostInfo.java
 */
public class HostInfo  implements Serializable{
	public String name;
	public InetAddress ipAddress;
	//public transient boolean respond = false;
	public transient Socket socket;
	//public int connectionsNumber = 0;
	//public transient int pointsNumber = 0;

	protected HostInfo() {}
	public HostInfo(String name) { this.name = name; }
	public HostInfo(InetAddress ip) { ipAddress = ip; }
	public HostInfo(String name, InetAddress ip) {
		this.name = name; ipAddress = ip;
	}

	public HostInfo copy() {
		HostInfo h = new HostInfo(name, ipAddress);
		return h;
	}

	public synchronized boolean resolveName(){
		if (ipAddress!=null) return true;
		try{ ipAddress = InetAddress.getByName(name);
			 return true;
		}catch (UnknownHostException e){
			return false;
		}
	}

	public boolean connect()throws Exception {
		return connect(false, Const.DAEMON_TCP_PORT);
	}
	public boolean connect(int port)throws Exception {
		return connect(false, port);
	}
	public boolean connect(boolean breakconn)throws Exception {
		return connect(breakconn, Const.DAEMON_TCP_PORT);
	}

	/**
	 * законнектиться к хосту. если breakconn==true, то соединение после
	 * установления сразу разрывается
	 *
	 * @param breakconn если true, то соединение разрывается
	 * @param port удаленный TCP порт
	 * @return true, если соединение было установлено
	 */
	public synchronized boolean connect(boolean breakconn, int port) {
		if (isConnected()) {
			if (socket==null) System.err.println("cycleConnect: error: socket==null");
			return true;
		}
		socket = null;
		try {
			if (!resolveName()) return false;
			socket = new Socket(ipAddress, port);
			if (socket == null) return false;

			if (breakconn) {
				socket.close();
				socket = null;
			}
		} catch(IOException e) { return false;}
		if (socket==null) System.err.println("cycleConnect: error: socket==null");
		return true;
	}

	public boolean cycleConnect(){
		return cycleConnect(Const.DAEMON_TCP_PORT);
	}
	public boolean cycleConnect(int port){
		if (!resolveName()) return false;
		for(int i=0;i<10;i++) {
			if (connect(false, port)) {
				if (socket==null) System.err.println("cycleConnect: error: socket==null");
				return true;
			}
			else try { Thread.sleep(400); }
				 catch (InterruptedException e) {}
			}
		return false;
	}

	public String toString(){
	  if (name!=null) return name;
	  if (ipAddress!=null) return ipAddress.toString();
	  return null;
	}

	public static void closeSocket(Socket sock){  //просто для удобства
		if (sock!=null)
			try { sock.close(); }
			catch(IOException e) { System.err.println("closeSocket: "+e); }
	}
	public synchronized void closeSocket(){
		if (socket!=null) {
			try { socket.close(); }
			catch(IOException e) { System.err.println("closeSocket: "+e); }
			socket = null;
		}
	}
	public static HostInfo getLocalHost(){
		try { return new HostInfo(InetAddress.getLocalHost());
		} catch (UnknownHostException e) {
			return new HostInfo("localhost");
		}
	}

	public boolean isConnected(){
		return (socket!=null)&&(!socket.isClosed())&&(socket.isConnected());
	}
}

