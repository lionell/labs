//rmi-интерфейс системы
import java.rmi.*;
import java.util.*;

public interface ParcsLauncherInt extends Remote{

	/**
	 * передает на сервер файл данных для программы
	 * @param filename имя файла
	 * @param buf содержимое файла
	 */
	void saveInputFile(String filename, byte[] buf) throws RemoteException;

	/**
	 * загружает с сервера файл результата
	 * @param filename имя файла
	 * @return содержимое файла
	 */
	byte[] loadOutputFile(String filename) throws RemoteException;

	/**
	 * запускает класс из jar-архива, содержимое которого находится в массиве buf,
	 * имя класса считывается из файла манифеста META-INF/manifest.mf, используются
	 * машины из списка hosts_list
	 * @param filename имя jar-файла (для учета)
	 * @param buf содержимое jar-файла
	 * @param hosts_list список машин. Если null, то используется список хостов на
	 *   сервере
	 * @param async если true, функция возвращается, не дожидаясь завершения задачи
	 */
	void executeClass(String filename, byte[] buf, List hosts_list, boolean async) throws RemoteException;
	/**
	 * запускает класс из jar-архива, содержимое которого находится
	 * в массиве buf, имя класса считывается из файла манифеста
	 * то же, что executeClass(filename, buf, null, false)
	 */
	void executeClass(String filename, byte[] buf) throws RemoteException;
}
