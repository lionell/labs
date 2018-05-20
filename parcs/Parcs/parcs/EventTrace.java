package parcs;

import HostsServer.XHostInfo;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class EventTrace
	implements IRecovery {
	public EventTrace() {
	}

	public void BeginTaskEvent(int taskNumber) {
		System.out.println("Trace: BeginTaskEvent, taskNumber = " + taskNumber);
	}

	public void EndTaskEvent() {
		System.out.println("Trace: EndTaskEvent");
	}

	public int CreatePointEvent(XHostInfo target, int pointNumber,
															 int parentNumber) {
		System.out.println("Trace: CreatePointEvent, target = "
											 + target.name + ", pointNumber = "
											 + pointNumber + ", parentNumber = "
											 + parentNumber);
		return pointNumber;
	}

	public void DeletePointEvent(int pointNumber) {
		System.out.println("Trace: DeletePointEvent, pointNumber = " + pointNumber);
	}

	public AM ExecuteClassEvent(int pointNumber, String className) {
		System.out.println("Trace: ExecuteClassEvent, pointNumber = "
											 + pointNumber + ", className = "
											 + className);
		return null;
	}

	public void CreateChildEvent(int parent, int child) {
		System.out.println("Trace: CreateChildEvent, parent = "
											 + parent + ", child = "
											 + child);
	}

	public void CreateChannelEvent(int from, int to) {
		System.out.println("Trace: CreateChannelEvent, from = "
											 + from + ", to = "
											 + to);
	}

	public void AddUserDataEvent(int pointNumber, Object key, Object value) {
		System.out.println("Trace: AddUserDataEvent, pointNumber = " + pointNumber);
	}

	public void Write(int from, int index, byte type, Object value) {
		System.out.print("Trace: Write, from = "
											 + from + ", index = "
											 + index + ", type = ");
		switch (type) {
			case IRecovery.T_BYTE:
				System.out.println("T_BYTE, value = " + value);
				break;
			case IRecovery.T_DOUNBLE:
				System.out.println("T_DOUNBLE, value = " + value);
				break;
			case IRecovery.T_INT:
				System.out.println("T_INT, value = " + value);
				break;
			case IRecovery.T_LONG:
				System.out.println("T_LONG, value = " + value);
				break;
			case IRecovery.T_OBJ:
				System.out.println("T_OBJ");
				break;
			default:
				System.err.println(
					"Error: Recover internal error, inconsistent type");
				break;
		}
	}

	public void Write(int from, int index, byte[] value) {
		System.out.println("Trace: Write, from = "
											 + from + ", index = "
											 + index + ", type = T_ARRAY");
	}

}