import Matrixes.*;
import parcs.*;

public class Matr implements AM{
	public void run(AMInfo info) {
		Matrix m = (Matrix)info.parent.readObject();
		Matrix m1 = (Matrix)info.parent.readObject();

		   Matrix res = new Matrix(m.Height(),m1.Width());
		   res.Assign(m);
		   res.MultiplyBy(m1);
		   info.parent.write(res);
    }
}
