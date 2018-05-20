import Matrixes.*;
import parcs.*;
import java.io.*;
import java.util.*;

public class Matr implements AM{
	public void run(AMInfo info) {

		byte b;
		if (info.data != null && info.data.containsKey("start"))
		{
			b = info.parent.readByte();

			( (channel) info.data.get("next")).write( (byte) (b + 1));
			channel c = (channel) info.data.get("prev");
			b = c.readByte();

			info.parent.write( (byte) (b + 1));
			return;
		}

		b = ( (channel) info.data.get("prev")).readByte();

		float x = 1/(b-5);

		( (channel) info.data.get("next")).write( (byte) (b + 1));

		/*		Matrix m = (Matrix)info.parent.readObject();
		Matrix m1 = (Matrix)info.parent.readObject();

		   Matrix res = new Matrix(m.Height(),m1.Width());
		   res.Assign(m);
		   res.MultiplyBy(m1);
		   info.parent.write(res);*/
    }
}
