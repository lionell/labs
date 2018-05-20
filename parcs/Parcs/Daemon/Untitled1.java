import java.io.*;
import parcs.*;
public class Untitled1 extends Thread {
	public void run(){
		ClassLoader loader = new JarClassLoader("Matrixes.jar");
		try {
			Class clazz = Class.forName("Matr", true, loader);
			Object object= clazz.newInstance();
			System.out.println(object);
			AM obj = (AM)object; //byte[] buf=new byte[128];
			//
			obj.run((task)null, (channel)null);
		}
		catch (Exception e) { e.printStackTrace(); }
//		new BufferedReader(new InputStreamReader( System.in)).readLine();

	}
	public static void main(String[] args){
		(new Untitled1()).start();


/*		File f;
		try {
			f = new File("pardir/dir\\file");
			String par = f.getParent();
			if (par!=null)
				System.out.println(new File(par).mkdirs());
			System.out.println(f.createNewFile());
			//f.close();
		}
		catch (IOException e) { e.printStackTrace(); }*/
	}
}
