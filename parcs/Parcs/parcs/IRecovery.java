package parcs;

import java.io.Serializable;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public interface IRecovery extends Serializable {
	public void BeginTaskEvent(int taskNumber);
	public void EndTaskEvent();

	public int CreatePointEvent(HostsServer.XHostInfo target, int pointNumber, int parentNumber);
	public void DeletePointEvent(int pointNumber);

	public AM   ExecuteClassEvent(int pointNumber, String className);

	public void CreateChildEvent(int parent, int child);
	public void CreateChannelEvent(int from, int to);
	public void AddUserDataEvent(int pointNumber, Object key, Object value);

	public void Write(int from, int index, byte type, Object value);
	public void Write(int from, int index, byte[] value);
	public final static byte T_BYTE = 1;
	public final static byte T_INT = 2;
	public final static byte T_LONG = 3;
	public final static byte T_DOUNBLE = 4;
	public final static byte T_OBJ = 5;
	public final static byte T_ARRAY = 5;

}