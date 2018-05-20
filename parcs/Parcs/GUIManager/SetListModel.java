
import java.util.*;
import javax.swing.*;

/**
 * Модель (хранилище) данных для графического списка JList. Не может содержать
 * одинаковых элементов
 */
public class SetListModel extends AbstractListModel
{
	private HashSet set = new HashSet();
	private LinkedList delegate = new LinkedList();
	private HashMap numbers;

	public void setNewList(List list) {
		int size1 = delegate.size();
		int size2 = list.size();
		if (list instanceof LinkedList) delegate = (LinkedList)list;
		else delegate = new LinkedList(list);

		set.clear();
		set.addAll(list);
		int min=size2;
		if (size1<size2) {fireIntervalAdded(this, size1, size2-1); min=size1;}
		else if (size1>size2) fireIntervalRemoved(this, size2, size1-1);
		fireContentsChanged(this, 0, min-1);
	}
	/**
	 * Returns the number of components in this list.
	 * @see #size()
	 */
	public int getSize() {return delegate.size();}

	/**
	 * Returns the component at the specified index.
	 * @param      index   an index into this list
	 * @return     the component at the specified index
	 * @exception  ArrayIndexOutOfBoundsException  if the <code>index</code>
	 *             is negative or greater than the current size of this
	 *             list
	 * @see #get(int)
	 */
	public Object getElementAt(int index) {
		Object o = delegate.get(index);
		if (numbers!=null) {
			Integer num = (Integer)numbers.get(new Integer(index));
			if (num!=null && num.intValue()!=0) {
				try{ o = (String)o+" : "+num; }
				catch (ClassCastException e) {}
		    }
		}
		return o;
	}

	/**
	 * Returns the number of components in this list.
	 * @see LinkedList#size()
	 */
	public int size() {return delegate.size();}

	/**
	 * Tests whether this list has any components.
	 * @return  <code>true</code> if and only if this list has
	 *          no components, that is, its size is zero;
	 *          <code>false</code> otherwise
	 * @see LinkedList#isEmpty()
	 */
	public boolean isEmpty() {
	return delegate.isEmpty();
	}

	/**
	 * Tests whether the specified object is a component in this list.
	 * @param   elem   an object
	 * @return  <code>true</code> if the specified object
	 *          is the same as a component in this list
	 * @see LinkedList#contains(Object)
	 */
	public boolean contains(Object elem) {
	return set.contains(elem);
	}

	/**
	 * Searches for the first occurrence of <code>elem</code>.
	 * @param   elem   an object
	 * @return  the index of the first occurrence of the argument in this
	 *          list; returns <code>-1</code> if the object is not found
	 * @see LinkedList#indexOf(Object)
	 */
	public int indexOf(Object elem) {
	return delegate.indexOf(elem);
	}

	/**
	 * Returns the index of the last occurrence of <code>elem</code>.
	 * @param   elem   the desired component
	 * @return  the index of the last occurrence of <code>elem</code>
	 *          in the list; returns <code>-1</code> if the object is not found
	 * @see LinkedList#lastIndexOf(Object)
	 */
	public int lastIndexOf(Object elem) {
	return delegate.lastIndexOf(elem);
	}

	/**
	 * Returns a string that displays and identifies this
	 * object's properties.
	 * @return a String representation of this object
	 */
   public String toString() { return delegate.toString();}

	/**
	 * Returns the element at the specified position in this list.
	 * @param index index of element to return
	 */
	public Object get(int index) {return delegate.get(index);}

	/**
	 * Replaces the element at the specified position in this list with the
	 * specified element.
	 * <p>
	 * @param index index of element to replace
	 * @param element element to be stored at the specified position
	 * @return the element previously at the specified position
	 */
	public Object set(int index, Object element) {
	if (set.add(element)) {
		Object rv = delegate.set(index, element);
		fireContentsChanged(this, index, index);
		return rv;
	} else return null;
	}
/*	public Object setPointsNum(int index, int num) {
	if (set.add(element)) {
		Object rv = delegate.set(index, element);
		fireContentsChanged(this, index, index);
		return rv;
	} else return null;
	}*/

	/**
	 * Inserts the specified element at the specified position in this list.
	 * @param index index at which the specified element is to be inserted
	 * @param element element to be inserted
	 */
	public void add(int index, Object element) {
	if (set.add(element)) {
		delegate.add(index, element);
		fireIntervalAdded(this, index, index);
	}
	}
	/**
	 * Inserts the specified element in this list.
	 * @param element element to be inserted
	 */
	public boolean add(Object element) {
	if (set.add(element)) {
		int index = delegate.size();
		delegate.add(element);
		fireIntervalAdded(this, index, index);
		return true;
	} else return false;
	}
	public void setNumber(int index, int pnum){
		if (numbers==null) numbers = new HashMap();
		numbers.put(new Integer(index), new Integer(pnum));
		//System.out.println(index+"---"+pnum);
		fireContentsChanged(this, index, index);
	}

	/**
	 * Removes the element at the specified position in this list.
	 * Returns the element that was removed from the list.
	 * @param index the index of the element to removed
	 */
	public Object remove(int index) {
	Object rv = delegate.remove(index);
	set.remove(rv);
	fireIntervalRemoved(this, index, index);
	return rv;
	}
	/**
	 * Removes the specified element from this list if it is present.
	 * @param o object to be removed from this list, if present.
	 * @return <tt>true</tt> if the set contained the specified element.
	 */
	public boolean remove(Object o) {
	if (set.remove(o)) {
		int index = delegate.indexOf(o);
		delegate.remove(index);
		fireIntervalRemoved(this, index, index);
		return true;
	} else return false;
	}

	/**
	 * Removes all of the elements from this list.  The list will
	 * be empty after this call returns (unless it throws an exception).
	 */
	public void clear() {
	int index1 = delegate.size()-1;
	delegate.clear();
	set.clear();
	if (index1 >= 0) {
		fireIntervalRemoved(this, 0, index1);
	}
	}

	public List getList() {return delegate;}
	/**
	 * возвращает копию списка
	 */
	public List getListCopy() {
		return (List)delegate.clone();
	}
}
