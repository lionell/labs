import java.rmi.*;
import java.io.*;
import java.util.*;

public class ParcsClient {

	public static boolean saveFile(String filename, byte[] buf) {
		FileOutputStream file=null;
		try {
			file = new FileOutputStream(filename);
			file.write(buf);
		} catch (Exception e) {
			System.err.println("saveFile "+filename+": "+e);
			return false;
		}
		finally { try{file.close();} catch (Exception e){} }
		return true;
	}
	public static byte[] loadFile(String filename){
		FileInputStream file=null;
		try {
			file = new FileInputStream(filename);
			byte[] buf = new byte[file.available()];
			file.read(buf);
			return buf;
		} catch (IOException e) {
			System.err.println("loadFile "+filename+": "+e);
			return null;
		}
		finally { try{file.close();} catch (Exception e){}}
	}

	private static void readSettingsFile() {
		try {
			BufferedReader in = new BufferedReader(new FileReader("client.ini"));
			hostName = in.readLine();
			taskFile = in.readLine();
			dataFiles = in.readLine();
			resFiles = in.readLine();
			in.close();
		}
		catch (Exception e) {}
	}

	static String hostName, taskFile, dataFiles, resFiles;

	public static void main(String[] args){
//		if (System.getSecurityManager()==null)
//			System.setSecurityManager(new RMISecurityManager());
		readSettingsFile();
		ParcsLauncherInt obj;
		if (hostName==null || hostName.equals("")) hostName="localhost";
		try{ obj = (ParcsLauncherInt)Naming.lookup("rmi://"+hostName+"/ParcsLauncher");
		} catch (Exception e) {
			System.err.println("Can not connect to RMI server: "+e);
			return;
		}
		if (obj==null) {
			System.err.println("RMI object not found");
			return;
	    }

		try {
//			System.out.println(dataFile+"|"+taskFile+"|"+resFile);
			if (dataFiles!=null && !dataFiles.equals("") && !dataFiles.equals("-"))
				for (StringTokenizer s=new StringTokenizer(dataFiles); s.hasMoreTokens();){
					String str=s.nextToken();
					System.out.println("Transferring file "+str+"...");

					obj.saveInputFile(str, loadFile(str));
				}
			if (taskFile!=null && !taskFile.equals("") && !taskFile.equals("-")) {
				System.out.println("Transferring task file "+taskFile+"...");

				obj.executeClass(taskFile, loadFile(taskFile));
			}
			System.out.println("Waiting for result...");
			if (resFiles!=null && !resFiles.equals("") && !resFiles.equals("-"))
				for (StringTokenizer s=new StringTokenizer(resFiles); s.hasMoreTokens();){
					String str=s.nextToken();
					System.out.println("Receiving file "+str+"...");

					saveFile(str, obj.loadOutputFile(str));
				}
			System.out.println("OK");
		} catch (RemoteException e) {System.err.println("Server error: "+e);}
	}
}
