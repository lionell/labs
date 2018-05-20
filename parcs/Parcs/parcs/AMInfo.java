package parcs;
import java.util.*;

/**
 * Класс содержащий все необходимую информацию для запуска AM
 */

public class AMInfo {
	/**
	 * Текущая задача
	 */
	public task curtask;
	/**
	 * Канал связи с родительской точкой
	 */
	public channel parent;
	/**
	 * Список всех каналов из єтой точки, кроме родительского
	 */
	public ArrayList channels;
	/**
	 * Данные переданые этой точке
	 */
	public HashMap data;

	/**
	 *
	 */
	public AMInfo() {
		this(null, null, null, null);
	}

	/**
	 *
	 */
	public AMInfo(task curtask, channel parent) {
		this(curtask, parent, null, null);
	}

	/**
	 *
	 */
	public AMInfo(task curtask, channel parent, ArrayList channels, HashMap data) {
		this.curtask = curtask;
		this.parent = parent;
		this.channels = channels;
		this.data = data;
	}

	public point createPoint()
	{
		if (parent == null)
			return curtask.createPoint(0);
		return curtask.createPoint(parent.from);
	}

}