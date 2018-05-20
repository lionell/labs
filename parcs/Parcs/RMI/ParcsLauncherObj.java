import java.rmi.*;
import java.rmi.server.*;
import java.io.*;
import java.util.*;
import HostsServer.*;
import parcs.*;

public class ParcsLauncherObj extends UnicastRemoteObject implements ParcsLauncherInt{
	private TCPHostsServer hServer;

	public ParcsLauncherObj() throws RemoteException{}

	public void printHosts(List hosts_list) {
		for (Iterator i = hosts_list.iterator(); i.hasNext();) {
			String s = (String)i.next();
			System.out.println(s);
		}
	}

	public void executeClass(String class_name, String filename, byte[] buf, List hosts_list, boolean async) {
		if (class_name==null) executeClass(filename, buf, hosts_list, async);
		//if (hosts_list!=null) printHosts(hosts_list);

		if (buf==null) return;
		String taskname;
		if (filename==null) {
			try {
				File tempfile = File.createTempFile("Class", ".temp");
				tempfile.deleteOnExit();
				filename = tempfile.getName();
				taskname = class_name;
			}
			catch (IOException e) {
				System.err.println("executeClass: Cannot create tempfile: "+e);
				return;
			}
		} else taskname = filename;
	    if (!Executor.saveFile(filename, buf)) return;

		if (hServer==null) {
			if (hosts_list==null) hServer = new TCPHostsServer();
			else hServer = new TCPHostsServer(hosts_list);
			hServer.start();
			System.out.println("HostsServer launched...");
		} else if (hosts_list!=null) hServer.getServerModel().setHostList(hosts_list);

	    if (async) (new Executor(class_name, filename)).start();
		System.out.println("Problem "+taskname+" launched...");
		if (!async) (new Executor(class_name, filename)).run();
	}

	/**
	 * запускает класс из jar-архива, содержимое которого находится
	 * в массиве buf, имя класса считывается из файла манифеста META-INF/manifest.mf,
	 * используются машины из списка hosts_list
	 */
	public void executeClass(String filename, byte[] buf, List hosts_list, boolean async) {
		if (buf==null) {
			System.err.println("executeClass: buf==null");
			return;	}
		String mainclass = Executor.getJarMainClass(buf);
		executeClass(mainclass, filename, buf, hosts_list, async);
	}
	public void executeClass(String filename, byte[] buf) { executeClass(filename, buf, null, false);}

	public void saveInputFile(String filename, byte[] buf) throws RemoteException {
		if (!Executor.saveFile(filename, buf))
			throw new RemoteException("Cannot save file "+filename);
	}

	public byte[] loadOutputFile(String filename) throws RemoteException {
		byte[] buf = Executor.loadFile(filename);
		if (buf==null) throw new RemoteException("Cannot load file "+filename);
		return buf;
	}
}

