package HostsServer;

import java.net.*;
import parcs.*;

/**
 * расширенная информация о хосте
 */
public class XHostInfo extends HostInfo implements Comparable{
	public volatile int pointsNumber;
	public int index;
	public volatile double perform; //производительность, больше-лучше
	public volatile int ping;       //пинг, меньше-лучше
	public volatile double nperform;//нормализированная производ-ть от 0 до 1, больше-лучше
	public volatile double nping;   //нормализированный пинг
	public double resPerf;      //результат вычисления функции производительности

	public int compareTo(Object o) {
		XHostInfo h =(XHostInfo)o;
		if (resPerf < h.resPerf) return 1;
		else if (resPerf == h.resPerf) return 0;
		else return -1;
	}

	public XHostInfo(String name) { super(name); }
	public XHostInfo(InetAddress ip) { super(ip); }
	public XHostInfo(String name, InetAddress ip) { super(name,ip); }
	public static HostInfo getLocalHost(){
		try { return new XHostInfo(InetAddress.getLocalHost());
		} catch (UnknownHostException e) { return new XHostInfo("localhost"); }
	}
	public synchronized HostInfo copy() {
		XHostInfo h = new XHostInfo(name, ipAddress);
		h.pointsNumber = pointsNumber;
		h.index = index; h.perform = perform;
		h.ping = ping;
		return h;
	}
	public boolean ipEquals(byte[] buf) {
		if (buf==null || ipAddress==null) return false;
		return java.util.Arrays.equals(ipAddress.getAddress(), buf);
	}

////	public int hashCode() { return name.hashCode();}
//	public boolean equals(Object o) { return name.equals(o);}
}
