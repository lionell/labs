import java.io.*;

public class StreamClassLoader extends ClassLoader {
	InputStream input;
	private static StreamClassLoader loader;

	public StreamClassLoader(InputStream inp){ input = inp;}

	protected synchronized Class loadClass(String name, boolean resolve)
	{
		Class c = findLoadedClass(name);
		if (c == null)
			try { c = findSystemClass(name);
			    if (resolve) resolveClass(c);
			    return c;
		    } catch (ClassNotFoundException e) {return findClass(name);}

		loadClassData(name);
		if (resolve) resolveClass(c);
		return c;
	}
/*	public Class load(String name) throws ClassNotFoundException {
		Class c = loadClass(name, true);
		return c;
	}*/
	public Class findClass(String name) {
		//System.out.println("Loading file "+name+"...");
        byte[] buf = loadClassData(name);
        try {
			Class c = defineClass(name, buf, 0, buf.length);
			//System.out.println("loader: "+parcs.AM.class.isAssignableFrom(c));
			return c;
        }
        catch (ClassFormatError e) {
            System.err.println("Recieved data is not a class: "+e); return null;
        }
    }

    public/*private*/ byte[] loadClassData(String name) {
        try {
            DataInputStream din = new DataInputStream(input);

            int len = din.readInt();
            if (len==0) return null;
            byte[] buf = new byte[len];
            if (buf==null) return null;

            try {
                int c = input.read(buf);
                if (c<len) return null;
            } catch (IOException e) {
                System.err.println("Error occured while reading class: "+e);
            }
            return buf;

        }
        catch(Exception e) {
            System.err.println(e);
            return null;
        }
    }
	/**
	 * Возвращает статический экземпляр загрузчика
	 */
	public static StreamClassLoader getLoader(InputStream inp)  {
		if (loader==null) loader = new StreamClassLoader(inp);
		else loader.input = inp;
		return loader;
	}
	/**
	 * Устанавливает статический экземпляр загрузчика
	 */
	public static void setLoader(StreamClassLoader cl)  {
		loader = cl;
	}
}
