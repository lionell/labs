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
                DataInputStream in = new DataInputStream(System.in);
                String func = in.readLine();
                String Lnumb = in.readLine();
                int numb = (int)(new Integer(Lnumb));

                String Lscale = in.readLine();
                int scale = (int)(new Integer(Lscale));

                String Llim = in.readLine();
                long lim = (long)(new Long(Llim));

                String dt = in.readLine();
                BigDecimal AR = new BigDecimal(dt);

                AR.setScale(scale);
                point[] p = new point[numb];
                channel[] c = new channel[numb];
                for (int i=0; i<numb; i++) {
                        p[i] = info.createPoint();
                        c[i] = p[i].createChannel();
                        p[i].execute(func);
                }
                for (int i=0; i<numb; i++) {
                        c[i].write(numb);
                        c[i].write(i);
                        c[i].write(scale);
                        c[i].write(lim);
                        c[i].write(AR);
                }
                BigDecimal res = new BigDecimal(0);
                res.setScale(scale);
                for (int i=0; i<numb; i++) {
                        res = res.add((BigDecimal)c[i].readObject());
                
                }
                System.out.println(res.toString());
                } catch (Exception e){System.out.println(e);}
                
        }
}