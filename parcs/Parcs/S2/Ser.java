import parcs.*;
import java.io.*;
import java.util.*;
import java.math.*;

public class Ser implements AM{
	public void run(AMInfo info) {
		long k = info.parent.readLong();
		BigDecimal a = new BigDecimal(0);
		a.setScale(200);
		a = (BigDecimal)info.parent.readObject();
		long kol = info.parent.readLong();
		int f1 = 1;
		if (k == 2) f1 = 2;
		if (k == 3) f1 = 6;
		BigDecimal res = new BigDecimal(1);
		res.setScale(200);
		//res = res.divide(new BigDecimal(f1),200,res.ROUND_DOWN);
		BigDecimal f2 = new BigDecimal(0);
		f2.setScale(200);
		f2 = a.pow((int)k);
		f2 = f2.divide(new BigDecimal(f1),200,res.ROUND_DOWN);
		res = res.multiply(f2);
		BigDecimal step = new BigDecimal(0);
		step.setScale(200);
		step = a.pow(4);
		System.err.println("k="+k+",step="+step.toString()+",res="+res.toString()+"\n");
		for (long i = k+4; i <= kol; i+=4) {
//			System.err.println("A"+k+"/"+i+" f2="+f2.toString()+"step="+step.toString()+"a="+a.toString()+"\n");
			f2 = f2.multiply(step);
			long e = i*(i-1)*(i-2)*(i-3);
//			System.err.println("B"+k+"/"+i+" f2="+f2.toString()+"step="+step.toString()+"a="+a.toString()+"\n");
			f2 = f2.divide(new BigDecimal(e),200,f2.ROUND_DOWN);
			res = res.add(f2);
			System.err.println("e,f2("+k+","+i+")="+e+","+f2.toString()+"\n");
		};                     
		info.parent.write(res);

	}
}
