import parcs.*;
import java.math.*;
import java.io.*;


public class SeriesS implements AM{

	public static void main(String[] args) {
		Const.parseArgs(args);
		task curtask = new task(new TieRecoveries(
					  new SafeRun("test"), new EventTrace(), true));
		curtask.addJarFile("Series.jar");
		(new SeriesS()).run(new AMInfo(curtask, (channel)null));
		curtask.end();
	}

	public void run(AMInfo info) {
		try {
		FileInputStream file = new FileInputStream(info.curtask.findFile("Series.data"));
		BigDecimal AR = new BigDecimal(0);
		ObjectInputStream in;
      		in = new ObjectInputStream(file);
      		AR = (BigDecimal)in.readObject();
		long kol = 20;
		point[] p = new point[4];
		channel[] c = new channel[4];
		for (int i=0; i<4; i++) {
			p[i] = info.createPoint();
			c[i] = p[i].createChannel();
			p[i].execute("Ser");
		}
		System.out.println("\nStart.");
		for (int i=0; i<4; i++) {
			c[i].write((long)i);
			c[i].write(AR);
			c[i].write(kol);
		}
		BigDecimal res1 = new BigDecimal(0);
		BigDecimal res = new BigDecimal(0);
		for (int i=0; i<4; i++) {
			res = res.add(res1 = (BigDecimal)c[i].readObject());
			System.out.println(res1.toString());
		
		}
		System.out.println(res.toString());
		} catch (Exception e){}
		
	}
}

