package parcs;

import java.io.*;
import java.util.*;
import java.net.*;

/**
 * Задача, содержащая в себе некоторые точки и каналы. Создается конструктором
 * task(), завершается методом end(). Содержит методы для создания точки,
 * указания jar-файла с исходниками задачи и функции производительности.
 */
public class task implements Serializable {
	private static HostInfo staticServer; //сервер хостов (для текущей VM)
	private HostInfo server; //сервер хостов

	private static HashMap uniqueTasks = new HashMap();
	private static HashSet loadedFiles = new HashSet(); //файлы, уже загруженные на машину
	private transient HashSet fileNames = new HashSet(); //файлы, необходимые для данной задачи
	public transient JarClassLoader loader;

	public int number; //номер задачи (присваивается сервером хостов)

	public IRecovery recovery = null;

	/**
	 * возвращает объект task, который является уникальным по номеру задачи в
	 * пределах текущей VM
	 */
	public static task getUniqueTask(task t){
		Object obj = uniqueTasks.get(new Integer(t.number));
		if (obj!=null) return (task)obj;
		uniqueTasks.put(new Integer(t.number), t);
		return t;
	}

	Collection getFileNames(){
		synchronized(fileNames){ return (Collection)fileNames.clone(); }
	}
	private static HostInfo readServerFile() {
		BufferedReader in;
		String sname;
		try {
			in = new BufferedReader(new FileReader("server"));
			String str = in.readLine();
			if (str == null) {
				System.err.println("Invalid server file");
				return null;
			}
			else sname = str.trim();
			in.close();
		}
		catch (FileNotFoundException e) {
			System.err.println("Error: server file not found");
			return null;
		}
		catch (IOException e) {
			System.err.println("Error occurred while reading server file");
			return null;
		}
		return new HostInfo(sname);
	}

	public static synchronized HostInfo getStaticServer() {
		if (staticServer == null) {
			System.out.println("Reading server file...");
			staticServer = readServerFile();
			if (staticServer != null)
				if (!staticServer.resolveName()) {
					System.out.println(
							"Cannot resolve server name. Working with localhost...");
					staticServer = HostInfo.getLocalHost();
				}
		}
		return staticServer.copy();
	}

	public synchronized HostInfo getServer() {
		if (server == null) server = getStaticServer();
		return server.copy();
	}

	/**
	 * Создание задачи
	 */
	public task() {	this(task.getStaticServer(), null); }
	public task(IRecovery recovery) {	this(task.getStaticServer(), recovery); }
	public task(HostInfo serv, IRecovery recovery) {
		server = serv;
		this.recovery = recovery;

		ServerQuery query = new ServerQuery();
		DataOutputStream dout = query.getOutputStream(5);
		try {
			dout.writeByte(Const.HS_BEGIN_TASK);
			(new ObjectOutputStream(dout)).writeObject(recovery);
		} catch (IOException e) { System.err.println(e); }

		if (query.send(server, 4) == null)return;
		try {
			number = query.getInputStream().readInt();
		} catch (IOException e) { System.err.println(e);}
	}

	/**
	 * устанавливает функцию производительности для распределения точек по машинам
	 * @param func класс, реализующий интерфейс PerformFunction
	 */
	public void setPerfFunc(PerformFunction func) {
		ServerQuery query = new ServerQuery();
		DataOutputStream dout = query.getOutputStream(5);
		try {
			dout.writeByte(Const.HS_SET_FUNC);
			dout.writeInt(number);
			ObjectOutputStream oout = new ObjectOutputStream(dout);
			oout.writeObject(func);
		} catch (IOException e) { System.err.println(e); }

		query.send(getServer(), 0);
	}

	/**
	 * завершение задачи
	 */
	public void end() {
		HostInfo serv = getServer();

		ServerQuery query = new ServerQuery();
		DataOutputStream dout = query.getOutputStream(5);
		try {
			dout.writeByte(Const.HS_END_TASK);
			dout.writeInt(number);
		} catch (IOException e) { System.err.println(e); }

		query.send(serv, 0);
	}

	/**
	 * создать точку
	 */
	public point createPoint(int parentNumber) {
		return new point(this, parentNumber);
	}

	/**
	 * добавляет jar-файл в список для загрузки
	 * @param filename имя файла на диске
	 * @return true, если файл еще не был загружен
	 */
	public boolean addJarFile(String filename) {
		//JarClassLoader.addJarFileToLoader(filename);
/*		File f = new File(filename);
		if (!f.canRead()) {
			System.err.println("addJarFile: Can not read file "+filename);
			return false;
		}*/
		if (fileNames == null) fileNames = new HashSet();
		synchronized (fileNames) {
			if (loader == null)
				loader = new JarClassLoader(filename);
			else loader.addJarFile(filename);
			fileNames.add(filename);
			return loadedFiles.add(filename);
		}
	}

	public URL findResource(String name) {
		try {
			if (loader != null)	return loader.findResource(name);
			else return new URL(name);
		} catch (MalformedURLException e) {return null;}
	}
	public String findFile(String name) {
		URL u=null;
		if (loader!=null) u=loader.findResource(name);
		if (u!=null) return u.getPath();
		else return name;
	}
	public String addPath(String filename) {
		if (loader!=null) {
			URL[] urls = loader.getURLs();
			if (urls!=null && urls.length>=2) {
				return urls[1].getFile()+filename;
		    }
		}
		return filename;
	}
}
