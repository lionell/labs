import parcs.*;
import java.io.*;
import java.util.*;
import java.math.*;

public class Log implements AM{
        public void run(AMInfo info) {
                int numb = info.parent.readInt();
                int k = info.parent.readInt();
                int scale = info.parent.readInt();
                long how = info.parent.readLong();
                BigDecimal x = new BigDecimal(0);
                x.setScale(scale);
                x = (BigDecimal)info.parent.readObject();
                x = x.subtract(new BigDecimal(1));
                BigDecimal res = new BigDecimal(0);
                res.setScale(scale);
                BigDecimal summer = new BigDecimal(1);
                summer.setScale(scale);
                summer = x.negate();
                summer = summer.pow(k+1);
                summer = summer.negate();
                BigDecimal multer = new BigDecimal(0);
                multer.setScale(scale);
                multer = x.negate();
                multer = multer.pow(numb);
                for (long i = (long)k+1; i <= how; i+=numb) {
                        BigDecimal divider = new BigDecimal(i);
                        res = res.add(summer.divide(divider,scale,summer.ROUND_HALF_EVEN));
                        summer = summer.multiply(multer);
                };
                info.parent.write(res);

        }
}