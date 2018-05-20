package parcs;

import java.net.*;
import java.io.*;

/**
 * Загрузчик классов для загрузки локальных и удаленных jar-файлов
 */
public class JarClassLoader extends URLClassLoader {
    private static JarClassLoader loader;

    /**
     * Создает JarClassLoader для указанного url.
     */
    public JarClassLoader(URL url) {
        super(new URL[] { url });
    }
	/**
	 * Создает JarClassLoader для указанного файла.
	 */
	public JarClassLoader(String filename) {
		this(filenameToURL(filename));
		String s=new File(filename).getParent();
		//System.out.println(s+File.separator);
		if (s!=null)
			addURL(filenameToURL(s+File.separator));
	}

	private static URL filenameToURL(String filename) {
		try { return new URL("file:" + filename);
		} catch (MalformedURLException e) {
			System.err.println("JarClassLoader. Wrong file name:"+filename);
			return null;
		}
	}

/*	protected Class loadClass(String name, boolean resolve)
					   throws ClassNotFoundException {
		System.out.print(name);
		URL[] urls = getURLs();
		for (int i=0; i<urls.length; i++) System.out.print(" "+urls[i]);
	    Class cl = super.loadClass(name, true);
		System.out.println(" "+cl);
		return cl;
	}*/

    /**
     * Adds the jar file with the following url into the class loader. This can be
     * a local or network resource.
     * @param url The url of the jar file i.e. http://www.xxx.yyy/jarfile.jar
     *            or file:c:\foo\lib\testbeans.jar
     */
    public void addJarFile(URL url) { addURL(url); }

    /**
     * Adds a jar file from the filesystems into the jar loader list.
     * @param jarfile The full path to the jar file.
     */
	public void addJarFile(String jarfile)  {
		addURL(filenameToURL(jarfile));
		String s=new File(jarfile).getParent();
		//System.out.println(s+File.separator);
		if (s!=null)
			addURL(filenameToURL(s+File.separator));
	}

	/**
	 * добавляет файл к разделяемому загрузчику loader, или создает loader, если он
	 * еще не создан
	 * @param jarfile имя jar-файла
	 */
	public static JarClassLoader addJarFileToLoader(String jarfile)  {
		if (loader == null)
			loader = new JarClassLoader(jarfile);
			else loader.addJarFile(jarfile);
		return loader;
	}

    /**
     * Возвращает статический экземпляр загрузчика
     */
    public static JarClassLoader getLoader() { return loader; }
    /**
     * Устанавливает статический экземпляр загрузчика
     */
    public static void setLoader(JarClassLoader cl) { loader = cl; }
}
