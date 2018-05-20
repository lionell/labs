import parcs.*;
import java.io.*;
import java.util.*;
import java.math.*;

public class Sin implements AM{
        public void run(AMInfo info) {
                int numb = info.parent.readInt();
                int k = info.parent.readInt();
                int scale = info.parent.readInt();
                long how = info.parent.readLong();
                BigDecimal x = new BigDecimal(0);
                x.setScale(scale);
                x = (BigDecimal)info.parent.readObject();
                BigDecimal res = new BigDecimal(0);
                res.setScale(scale);
                BigDecimal summer = new BigDecimal(1);
                summer.setScale(scale);
                summer = x.negate();
                summer = summer.pow(k);
                summer = summer.multiply(x.pow(k+1));
                for (int j = 1; j <= 2*k+1; j++){
                        summer = summer.divide(new BigDecimal(j),scale,summer.ROUND_HALF_EVEN);
                };
                BigDecimal multer = new BigDecimal(0);
                multer.setScale(scale);
                multer = x.negate();
                multer = multer.pow(numb);
                multer = multer.multiply(x.pow(numb));
                for (long i = (long)k; i <= how; i+=numb) {
                        res = res.add(summer);
                        summer = summer.multiply(multer);
                        BigDecimal divider = new BigDecimal(1);
                        for (long j = 2*i+2; j <= 2*i + numb*2+1; j++){
                                divider = divider.multiply(new BigDecimal(j));
                        };
                        summer = summer.divide(divider,scale,summer.ROUND_HALF_EVEN);
                };
                info.parent.write(res);

        }
}