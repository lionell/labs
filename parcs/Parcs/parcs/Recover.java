package parcs;

import java.io.*;
import java.net.*;
import java.util.*;
import HostsServer.XHostInfo;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class Recover
	implements IRecovery {
	private String name;
	private ArrayList points = null;
	private int pointCount = 0;

	private void writeObject(java.io.ObjectOutputStream out) throws IOException {
		out.writeObject(name);
	}

	private void readObject(java.io.ObjectInputStream in) throws IOException,
		ClassNotFoundException {
		name = (String) in.readObject();
	}

	public Recover(String name) {
		if (name == null) {
			this.name = "default";
		}
		else {
			this.name = name;
		}
	}

	public void BeginTaskEvent(int taskNumber) {
		points = new ArrayList();
		points.add(new PointData(0, 0, null, 0));

		File file = new File(SafeRun.PATH_SRV + name);
		ObjectInputStream serverFile = null;
		try {
			serverFile = new ObjectInputStream(new FileInputStream(file));
//			int taskNumberOld = serverFile.readInt();
			int pointNumber;
			while (true) {
				byte type = serverFile.readByte();
				switch (type) {
					case SafeRun.FL_POINT_START:
						pointNumber = serverFile.readInt();
						int parentNumber = serverFile.readInt();
						String hostName = (String) serverFile.readObject();
						if (pointNumber != points.size()) {
							System.err.println(
								"Error: Recover internal error, inconsistent point number");
						}
						points.add(new PointData(pointNumber,
																		 parentNumber,
																		 hostName,
																		 ++Get(parentNumber).count));
						continue;
					case SafeRun.FL_POINT_END:
						pointNumber = serverFile.readInt();
						Get(pointNumber).finished = true;
						continue;
					case SafeRun.FL_END:
						break;
					default:
						System.err.println(
							"Error: Recover internal error, inconsistent type");
						break;
				}
				break;
			}
		}
		catch (IOException ex) {
			System.err.println("Error: Recovery couldn't create file \"" +
												 SafeRun.PATH_SRV + name + "\".");
		}
		catch (ClassNotFoundException ex) {
			System.err.println(ex.getMessage());
		}

		pointCount = points.size();
		for (int i = 0; i < pointCount; ++i)
			Get(i).count = 0;
	}

	public void EndTaskEvent() {
	}

	public int CreatePointEvent(XHostInfo target, int pointNumber,
															 int parentNumber) {
		int parentNum = Math.abs(parentNumber);
		int ind = ++Get(parentNum).count;
		for (int i = 0; i < points.size(); ++i)
			if (Get(i).parentNumber == parentNum && Get(i).index == ind)
			{
				pointNumber = Get(i).pointNumber;
				if (Get(i).finished)
				{
					pointNumber = -pointNumber;
					target = new XHostInfo(Get(i).hostName);
				}
				return pointNumber;
			}

		pointNumber = pointCount++;
		return pointNumber;
	}

	public void DeletePointEvent(int pointNumber) {
	}

	public AM ExecuteClassEvent(int pointNumber, String className) {
		if (pointNumber >= 0)
			return null;
		className = "AMRecover";
		return new AMRecover();
	}

	public void CreateChildEvent(int parent, int child) {
	}

	public void CreateChannelEvent(int from, int to) {
	}

	public void AddUserDataEvent(int pointNumber, Object key, Object value) {
	}

	public void Write(int from, int index, byte type, Object value) {
	}

	public void Write(int from, int index, byte[] value) {
	}

	private PointData Get(int i) {
		return (PointData) points.get(i);
	}

	public class AMRecover implements AM {
		public void run(AMInfo info) {
			ObjectInputStream deamonFile = null;
			File file = new File(SafeRun.PATH_DMN + name);
			try {
				deamonFile = new ObjectInputStream(new FileInputStream(file));
				info.channels.add(info.parent);
				while (true) {
					byte type = deamonFile.readByte();
					switch (type) {
						case SafeRun.FL_WRITE:
							int from = deamonFile.readInt();
							int index = deamonFile.readInt();
							if (index == -1)
								index = info.channels.size()-1;

							byte t = deamonFile.readByte();
							if (t == IRecovery.T_ARRAY)
							{
								int len = deamonFile.readInt();
								byte[] value = new byte[len];
								deamonFile.readFully(value, 0 ,len);
								if (Math.abs(from) != Math.abs(info.parent.from))
									continue;
								((channel)info.channels.get(index)).write(value);
							} else
							{
								Serializable value = (Serializable)deamonFile.readObject();
								if (Math.abs(from) != Math.abs(info.parent.from))
									continue;
								switch (t) {
									case IRecovery.T_BYTE:
										((channel)info.channels.get(index)).write(((Byte)value).byteValue());
										break;
									case IRecovery.T_DOUNBLE:
										((channel)info.channels.get(index)).write(((Double)value).doubleValue());
										break;
									case IRecovery.T_INT:
										((channel)info.channels.get(index)).write(((Integer)value).intValue());
										break;
									case IRecovery.T_LONG:
										((channel)info.channels.get(index)).write(((Long)value).longValue());
										break;
									case IRecovery.T_OBJ:
										((channel)info.channels.get(index)).write(value);
										break;
									default:
										System.err.println(
											"Error: Recover internal error, inconsistent type");
										break;
								}
							}

							continue;
						case SafeRun.FL_END:
							break;
						default:
							continue;
					}
					break;
				}
			}
			catch (IOException ex) {
				System.err.println("Error: Recover couldn't read file \"" +
										 SafeRun.PATH_DMN + name + "\".");
			}
			catch (ClassNotFoundException e) {
				System.err.println(e.getMessage());
			}

		}
	}
}

class PointData {
	int pointNumber;
	int parentNumber;
	String hostName;
	boolean finished = false;

	int index;
	int count = 0;

	PointData(int pointNum, int parentNum, String name, int ind) {
		pointNumber = pointNum;
		parentNumber = parentNumber;
		hostName = name;
		index = ind;
	}
}