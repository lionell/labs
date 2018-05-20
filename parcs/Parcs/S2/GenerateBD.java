import java.io.*;
import java.math.*;

public class GenerateBD {
	public static void main(String[] args) throws IOException {
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter :");
		String nx = in.readLine();
		BigDecimal AR = new BigDecimal(nx);
		FileOutputStream file = new FileOutputStream("Series.data");
		ObjectOutputStream out = new ObjectOutputStream(file);
		out.writeObject(AR);
		out.flush();
		out.close();
	}
}
