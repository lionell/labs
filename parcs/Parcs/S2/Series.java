import parcs.*;                 	

public class Series implements AM{

    public static void main(String[] args) {
		Const.parseArgs(args);
		task curtask = new task(new TieRecoveries(
					  new SafeRun("test"), new EventTrace(), true));
		curtask.addJarFile("Matrixes.jar");
		(new Series()).run(new AMInfo(curtask, (channel)null));
		curtask.end();
    }

	public void run(AMInfo info) {
		point[] p = new point[8];
		channel c;
		for (int i=0; i<8; i++) {
			p[i] = info.createPoint();
			//c[i] = p[i].createChannel();
			//p[i].execute("Matr");
		}

		//p[0] = info.curtask.createPoint();

		System.out.println("\nStart.");

		c = p[0].createChannel();
		p[0].connectPoint("next" ,p[1], "prev");
		p[0].AddData("start", null);
//		p[0].execute("Matr");

		for (int i=1; i<8; i++)
		{
			p[i].createChannel();
			p[i].connectPoint("next", p[(i+1)%8], "prev");
			//p[i].createChannel();
			p[i].execute("Matr");
		}

		p[0].execute("Matr");

		c.write((byte)0);

		System.out.println("\nWaiting for result...");

		int res = c.readByte();

		System.out.println("\nResult found!. " + res);
/*		Matrix A = new Matrix(info.curtask.findFile("Matrix1.data"));
		Matrix B = new Matrix(info.curtask.findFile("Matrix2.data"));

	point[] p = new point[8];
	channel[] c = new channel[8];
	for (int i=0; i<8; i++) {
		p[i] = info.curtask.createPoint();
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
	Res.Save(info.curtask.addPath("Matrix.res"));*/
	}
}
