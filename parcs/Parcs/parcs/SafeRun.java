package parcs;

import java.io.*;
import HostsServer.XHostInfo;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class SafeRun
		implements IRecovery {
	private ObjectOutputStream serverFile = null;
	static private ObjectOutputStream deamonFile = null;
	private String name;

	private void writeObject(java.io.ObjectOutputStream out) throws IOException {
		out.writeObject(name);
	}
	private void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException{
		name = (String)in.readObject();
	}


	public final static String PATH = "c:\\temp\\parcs\\recovery\\";
	public final static String PATH_SRV = PATH + "srv\\";
	public final static String PATH_DMN = PATH + "dmn\\";

	public final static byte FL_END = 0;
	public final static byte FL_POINT_START = 1;
	public final static byte FL_POINT_END = 2;

	public final static byte FL_CREATE_CHANNEL = 3;
	public final static byte FL_ADD_DATA = 4;
	public final static byte FL_EXECUTE = 5;
	public final static byte FL_WRITE = 6;

	public SafeRun(String name) {
		if (name == null) {
			this.name = "default";
		}
		else {
			this.name = name;
		}
	}

	public void BeginTaskEvent(int taskNumber) {
		synchronized (this)
		{
			File file = new File(PATH_SRV + name);
			try {
				file.createNewFile();
				serverFile = new ObjectOutputStream(new FileOutputStream(file));
				//serverFile.writeInt(taskNumber);
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't create file \"" +
													 PATH_SRV + name + "\".");
			}
		}
	}

	public void EndTaskEvent() {
		synchronized (this)
		{
			try {
				CheckServerFile();
				serverFile.writeByte(FL_END);
				serverFile.flush();
				serverFile.close();
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't write to file \"" +
													 PATH_SRV + name + "\".");
			}
		}
	}

	public int CreatePointEvent(XHostInfo target, int pointNumber,
								 int parentNumber) {
		synchronized (this)
		{
			try {
				CheckServerFile();
				serverFile.writeByte(FL_POINT_START);
				serverFile.writeInt(pointNumber);
				serverFile.writeInt(parentNumber);
				serverFile.writeObject(target.name);
				serverFile.flush();
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't write to file \"" +
													 PATH_SRV + name + "\".");
			}
			return pointNumber;
		}
	}

	public void DeletePointEvent(int pointNumber) {
		synchronized (this)
		{
			try {
				CheckServerFile();
				serverFile.writeByte(FL_POINT_END);
				serverFile.writeInt(pointNumber);
				serverFile.flush();
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't write to file \"" +
													 PATH_SRV + name + "\".");
			}
		}
	}

	public AM ExecuteClassEvent(int pointNumber, String className) {
/*		try {
			InitDeamonFile();
			deamonFile.writeByte(FL_EXECUTE);
			deamonFile.writeInt(pointNumber);
			deamonFile.writeObject(className);
			deamonFile.flush();
		}
		catch (IOException ex) {
			System.err.println("Error: Recovery couldn't write to file \"" +
							   PATH_DMN + name + "\".");
		}*/
		return null;
	}

	public void CreateChildEvent(int parent, int child) {
	}

	public void CreateChannelEvent(int from, int to) {
/*		try {
			InitDeamonFile();
			deamonFile.writeByte(FL_CREATE_CHANNEL);
			deamonFile.writeInt(from);
			deamonFile.writeInt(to);
			deamonFile.flush();
		}
		catch (IOException ex) {
			System.err.println("Error: Recovery couldn't write to file \"" +
							   PATH_DMN + name + "\".");
		}*/
	}

	public void AddUserDataEvent(int pointNumber, Object key, Object value) {
/*		try {
			InitDeamonFile();
			deamonFile.writeByte(FL_ADD_DATA);
			deamonFile.writeInt(pointNumber);
			deamonFile.writeObject(key);
			deamonFile.writeObject(value);
			deamonFile.flush();
		}
		catch (IOException ex) {
			System.err.println("Error: Recovery couldn't write to file \"" +
							   PATH_DMN + name + "\".");
		}*/
	}

	public void Write(int from, int index, byte type, Object value) {
		synchronized (this)
		{
			try {
				InitDeamonFile();
				deamonFile.writeByte(FL_WRITE);
				deamonFile.writeInt(from);
				deamonFile.writeInt(index);
				deamonFile.writeByte(type);
				deamonFile.writeObject(value);
				deamonFile.flush();
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't write to file \"" +
													 PATH_DMN + name + "\".");
			}
		}
	}

	public void Write(int from, int index, byte[] value) {
		synchronized (this)
		{
			try {
				InitDeamonFile();
				deamonFile.writeByte(FL_WRITE);
				deamonFile.writeInt(from);
				deamonFile.writeInt(index);
				deamonFile.writeByte(IRecovery.T_ARRAY);
				deamonFile.writeInt(value.length);
				deamonFile.write(value);
				deamonFile.flush();
			}
			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't write to file \"" +
													 PATH_DMN + name + "\".");
			}
		}
	}

	private void InitDeamonFile() throws IOException {
			if (deamonFile != null) {
				return;
			}
			File file = new File(PATH_DMN + name);
			try {
				file.createNewFile();
				deamonFile = new ObjectOutputStream(new FileOutputStream(file));
			}

			catch (IOException ex) {
				System.err.println("Error: Recovery couldn't create file \"" +
					PATH_DMN + name + "\".");
				throw new IOException();
			}
	}

	private void CheckServerFile() throws IOException {
		if (serverFile == null) {
			throw new IOException();
		}
	}
}