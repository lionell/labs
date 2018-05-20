package HostsServer;

public interface UpdateHandler {
	void updatePointsNumber(int hostIndex, int pnum);
//	void updatePointsNumber(String hostName, int pnum);
	void updateHostInfo(String hname);
	void testsFinished();
}
