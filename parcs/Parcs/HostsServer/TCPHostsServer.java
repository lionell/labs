package HostsServer;

import java.io.*;
import java.net.*;
import java.util.*;
import parcs.*;

/**
 * TCP-сервер дл€ приема запросов
 * «апросы обрабатываютс€ функци€ми HostsServer.java
 */
public class TCPHostsServer extends Thread {
	boolean quit = false; //если true - происходит завершение
	private static HostsServer hserver;
	private ServerSocket ss = null;

	public TCPHostsServer() { hserver = new HostsServer(); }
	public TCPHostsServer(List c) { hserver = new HostsServer(c); }
	public HostsServer getServerModel(){ return hserver;}

	public void quit() {
		quit = true;
		synchronized(ss){ try { ss.close();}catch (Exception e){} }
	}

	public void run() {
		try {
		ss = new ServerSocket(Const.HOSTSSERVER_TCP_PORT);
		System.out.println("Accepting connections on port "+Const.HOSTSSERVER_TCP_PORT+"...");
		while (!quit) {
			Socket s;
			try { s = ss.accept();}
			catch (Exception e) {
				if (!quit) System.err.println(e);
				continue;
			}
			synchronized (ss){
			if ( (s==null)||(s.isClosed()) )
				continue;

			//System.out.println("Connection accepted from "+s.getInetAddress());
			BufferedInputStream inp;
			BufferedOutputStream out;
			try {
				inp = new BufferedInputStream(s.getInputStream());
				out = new BufferedOutputStream(s.getOutputStream());
			}
			catch (IOException e) {
				System.err.println(e);
				continue;
			}

			DataInputStream dinp = new DataInputStream(inp);
			DataOutputStream dout = new DataOutputStream(out);
			byte type = dinp.readByte();

			try{ int tasknum, pointnum;
				switch (type) {
				case Const.HS_CREATE_POINT:    //создание новой точки (выделить под нее машину)
					tasknum = dinp.readInt();
					int parentNumber = dinp.readInt();
					PointInfo p = hserver.createPoint(tasknum, parentNumber,
							s.getInetAddress().getAddress());
					if (p!=null) {
						dout.writeInt(p.number);
						dout.write(p.getHostIP());
					} else {
						dout.writeInt(Const.HS_WAIT);
						dout.write(new byte[4]);
					}
					out.flush();
				break;
				case Const.HS_DELETE_POINT:    //удаление точки
					tasknum = dinp.readInt();
					pointnum = dinp.readInt();
					hserver.deletePoint(tasknum, pointnum);
				break;
				case Const.HS_BEGIN_TASK:       //начало задачи
					dout.writeInt(hserver.beginTask((IRecovery)(new ObjectInputStream(inp)).readObject()));
					dout.flush();
				break;
				case Const.HS_END_TASK:        //конец задачи
					hserver.endTask(dinp.readInt());
				break;
				case Const.HS_SET_FUNC:
					tasknum = dinp.readInt();
					Object o=(new ObjectInputStream(inp)).readObject();
					if (o instanceof PerformFunction)
						hserver.setPerfFunc(tasknum, (PerformFunction)o);
				break;
				}
			} catch (Exception e){e.printStackTrace();}
			finally{ HostInfo.closeSocket(s);}
			} //synchronized
		}    //while
		} catch (BindException e){
			System.err.println("TCP port "+Const.HOSTSSERVER_TCP_PORT+" was already bound.\n"
					+"May be another copy of TCPHostsServer already launched.\n"
					+"Try to use command line option --hsport <port>");
		} catch (Exception e) {
			System.err.println("TCPHostsServer: "+e);
			e.printStackTrace();
		} finally {
			try{ ss.close();} catch (Exception e) {}
		}
	}

	public static void main(String[] args){
		TCPHostsServer tcp_hserver = new TCPHostsServer();
		tcp_hserver.start();
	}
}
