import parcs.*;
import Matrixes.*;

public class Matrixs implements AM{
    static String file1, file2;

    public static void main(String[] args) {
		if (args.length<2 ) { 
			System.out.println("Usage: Matrixs file1 file2"); 
			return;
		}
		file1 = args[0];
		file2 = args[1];
		Const.parseArgs(args);
		task curtask = new task(new TieRecoveries(
					  new SafeRun("test"), new EventTrace(), true));
		curtask.addJarFile("Matrixes.jar");
		(new Matrixs()).run(new AMInfo(curtask, (channel)null));
		curtask.end();
    }

	public void run(AMInfo info) {

	Matrix A = new Matrix(info.curtask.findFile(file1));
	Matrix B = new Matrix(info.curtask.findFile(file2));
	if ( A.Width() != B.Height() ) { 
		System.err.println("Cannot multiply Matrixes with such dimensions. Matrix 1 is "+A.Width()+"x"+A.Height()+", Matrix 2 is "+
			B.Width()+"x"+B.Height());
		return;
	}

	point[] p = new point[8];
	channel[] c = new channel[8];
	for (int i=0; i<8; i++) {
		p[i] = info.createPoint();
		c[i] = p[i].createChannel();
		p[i].execute("Matr");
	}

	c[0].write(A.SubMatrix(0, 0, A.Height() / 2, A.Width() / 2));
	c[0].write(B.SubMatrix(0, 0, B.Height() / 2, B.Width() / 2));

	c[1].write(A.SubMatrix(0, A.Width() / 2, A.Height() / 2, A.Width() / 2 + A.Width() % 2));
	c[1].write(B.SubMatrix(B.Height() / 2, 0, B.Height() / 2 + B.Height() % 2, B.Width() / 2));

	c[2].write(A.SubMatrix(0, 0, A.Height() / 2, A.Width() / 2));
	c[2].write(B.SubMatrix(0, B.Width() / 2, B.Height() / 2, B.Width() / 2 + B.Width() % 2));

	c[3].write(A.SubMatrix(0, A.Width() / 2, A.Height() / 2, A.Width() / 2 + A.Width() % 2));
	c[3].write(B.SubMatrix(B.Height() / 2, B.Width() / 2, B.Height() / 2 + B.Height() % 2, B.Width() / 2 + B.Width() % 2));

	c[4].write(A.SubMatrix(A.Height() / 2, 0, A.Height() / 2 + A.Height() % 2, A.Width() / 2));
	c[4].write(B.SubMatrix(0, 0, B.Height() / 2, B.Width() / 2));

	c[5].write(A.SubMatrix(A.Height() / 2, A.Width() / 2, A.Height() / 2 + A.Height() % 2, A.Width() / 2 + A.Width() % 2));
	c[5].write(B.SubMatrix(B.Height() / 2, 0, B.Height() / 2 + B.Height() % 2, B.Width() / 2));

	c[6].write(A.SubMatrix(A.Height() / 2, 0, A.Height() / 2 + A.Height() % 2, A.Width() / 2));
	c[6].write(B.SubMatrix(0, B.Width() / 2, B.Height() / 2, B.Width() / 2 + B.Width() % 2));

	c[7].write(A.SubMatrix(A.Height() / 2, A.Width() / 2, A.Height() / 2 + A.Height() % 2, A.Width() / 2 + A.Width() % 2));
	c[7].write(B.SubMatrix(B.Height() / 2, B.Width() / 2 , B.Height() / 2 + B.Height() % 2, B.Width() / 2 + B.Width() % 2));

	System.out.println("\nWaiting for result...");

	Matrix[][] Parts = new Matrix[2][2];

			Parts[0][0]  =  (Matrix)c[0].readObject();
			Parts[0][0].Add((Matrix)c[1].readObject());
			Parts[0][1]  =  (Matrix)c[2].readObject();
			Parts[0][1].Add((Matrix)c[3].readObject());
			Parts[1][0]  =  (Matrix)c[4].readObject();
			Parts[1][0].Add((Matrix)c[5].readObject());
			Parts[1][1]  =  (Matrix)c[6].readObject();
			Parts[1][1].Add((Matrix)c[7].readObject());

			Matrix Res = new Matrix(A.Height(), B.Width());
			Res.FillSubMatrix(Parts[0][0], 0, 0);
			Res.FillSubMatrix(Parts[0][1], 0, Res.Width() / 2);
			Res.FillSubMatrix(Parts[1][0], Res.Height() / 2, 0);
			Res.FillSubMatrix(Parts[1][1], Res.Height() / 2, Res.Width() / 2);


	System.out.println("\nResult found!. Saving to file Matrix.res");
	Res.Save(info.curtask.addPath("Matrix.res"));
	}
}
