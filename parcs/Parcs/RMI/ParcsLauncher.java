import java.rmi.*;
import java.rmi.registry.LocateRegistry;

public class ParcsLauncher{
	public static void main(String[] args){
//		if (System.getSecurityManager()==null)
//			System.setSecurityManager(new RMISecurityManager());

		try{ LocateRegistry.createRegistry(1099); }
		catch (RemoteException e) {
			System.err.println("Registry create error:"+e);
		}
		parcs.Const.parseArgs(args);
		try {
			ParcsLauncherObj obj = new ParcsLauncherObj();
			Naming.rebind("rmi://localhost/ParcsLauncher", obj);
		} catch (Exception e) {
			System.err.println(e);
		}
		System.out.println("RMI object registered.");
	}
}
