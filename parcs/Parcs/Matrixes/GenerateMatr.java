import java.io.*;
import Matrixes.*;

public class GenerateMatr {
	public static void main(String[] args) throws IOException {
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter matrix width:");
		int w=new Integer(in.readLine().trim()).intValue();
		System.out.print("Enter matrix height:");
		int h=new Integer(in.readLine().trim()).intValue();
		Matrix A = new Matrix(h, w);
		A.RandomFill(255);

		System.out.print("Enter file name [ENTER-Matrix.data]:");
		String fname = in.readLine();
		if (fname==null || fname.equals("")) fname="Matrix.data";
		A.Save(fname);
		System.out.println("Matrix saved in file "+fname);
	}
}
