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

public class TieRecoveries
	implements IRecovery {
	private IRecovery first, second;
	private boolean firstPrimary;

	public TieRecoveries(IRecovery first, IRecovery second, boolean firstPrimary) {
		this.first = first;
		this.second = second;
		this.firstPrimary = firstPrimary;
	}

	public void BeginTaskEvent(int taskNumber) {
		first.BeginTaskEvent(taskNumber);
		second.BeginTaskEvent(taskNumber);
	}

	public void EndTaskEvent() {
		first.EndTaskEvent();
		second.EndTaskEvent();
	}

	public int CreatePointEvent(XHostInfo target, int pointNumber,
															 int parentNumber) {
		 pointNumber = first.CreatePointEvent(target, pointNumber, parentNumber);
		 return second.CreatePointEvent(target, pointNumber, parentNumber);
	}

	public void DeletePointEvent(int pointNumber) {
		first.DeletePointEvent(pointNumber);
		second.DeletePointEvent(pointNumber);
	}

	public AM ExecuteClassEvent(int pointNumber, String className) {
		if (firstPrimary)
		{
			AM am = first.ExecuteClassEvent(pointNumber, className);
			second.ExecuteClassEvent(pointNumber, className);
			return am;
		}
		first.ExecuteClassEvent(pointNumber, className);
		return second.ExecuteClassEvent(pointNumber, className);
	}

	public void CreateChildEvent(int parent, int child) {
		first.CreateChildEvent(parent, child);
		second.CreateChildEvent(parent, child);
	}

	public void CreateChannelEvent(int from, int to) {
		first.CreateChannelEvent(from, to);
		second.CreateChannelEvent(from, to);
	}

	public void AddUserDataEvent(int pointNumber, Object key, Object value) {
		first.AddUserDataEvent(pointNumber, key, value);
		second.AddUserDataEvent(pointNumber, key, value);
	}

	public void Write(int from, int index, byte type, Object value) {
		first.Write(from, index, type, value);
		second.Write(from, index, type, value);
	}

	public void Write(int from, int index, byte[] value) {
		first.Write(from, index, value);
		second.Write(from, index, value);
	}

}