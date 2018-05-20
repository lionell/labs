package parcs;

import java.io.*;
import java.util.jar.*;

public class Executor extends Thread {       //поток, в котором запускается АлгМодуль
	private String fileName;
	private String className;
	public Executor(String fname) {	this(fname, loadFile(fname));}
	public Executor(String fname, byte[] jarfile){
		className = getJarMainClass(jarfile); fileName = fname;
	}
	public Executor(String cname, String fname){
		className = cname; fileName = fname;
	}

	public void run() {
		if ((className==null)||(fileName==null)) return;

		task curtask = new task(HostInfo.getLocalHost(), null);
		curtask.addJarFile(fileName);

		Class mainclass;
		try {
			//mainclass = loader.loadClass(class_name);
			mainclass = Class.forName(className, true, curtask.loader);
		} catch (ClassNotFoundException e) {
			System.err.println("executeClass: Main class "+className+
					" doesn't found in jar-file "+fileName+": "+e);
			return;
		}
		AM obj;
		try { obj = (AM)mainclass.newInstance();}
		catch (Exception e) {
			System.err.println("executeClass: Main class "+className+" is invalid: "+e);
			return;
		}

		obj.run(new AMInfo(curtask, (channel)null));
		curtask.end();
	}

	public static String getJarMainClass(byte[] buf) {
		if (buf==null) return null;
		JarInputStream jar;
		try{ jar = new JarInputStream(new ByteArrayInputStream(buf));
		} catch(IOException e){
			System.err.println("getJarMainClass: Invalid JAR file: "+e);
			e.printStackTrace();
			return null;	}

		Manifest manifest = jar.getManifest();
		if (manifest==null) {
			System.err.println("getJarMainClass: JAR file doesn't contain manifest: ");
			return null;	}
		Attributes attributes = manifest.getMainAttributes();
		if (attributes==null) {
			System.err.println("getJarMainClass: Manifest doesn't contain attributes: ");
			return null;	}
		String mainclass = attributes.getValue(Attributes.Name.MAIN_CLASS);
		if (mainclass==null) {
			System.err.println("getJarMainClass: Manifest doesn't contain Main-Class attribute: ");
			return null;	}
		return mainclass;
	}

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
}
