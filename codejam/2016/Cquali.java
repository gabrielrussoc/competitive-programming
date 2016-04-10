import java.io.*;
import java.util.*;
import java.math.*;

public class Cquali {

    private static BigInteger ZERO = new BigInteger("0");
    private static BigInteger ONE = new BigInteger("1");
    private static BigInteger TWO = new BigInteger("2");
    private static Random random = new Random();

    private static BigInteger base(long a, int b){
        BigInteger ret = BigInteger.ZERO;
        BigInteger aux, bb, pot;
        pot = BigInteger.ONE;
        bb = new BigInteger((new Integer(b)).toString());
        while(a > 0) {
            aux = new BigInteger((new Long(a&1l)).toString());
            ret = ret.add(aux.multiply(pot));
            pot = pot.multiply(bb);
            a >>= 1;
        }
        return ret;
    }
    
    public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }

    public static void main (String[] args){
        int t, n, j;
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        n = in.nextInt();
        j = in.nextInt();
        System.out.println("Case #1:");
        
        BigInteger[] v = new BigInteger[11];
        BigInteger a = BigInteger.ZERO;

        for(long i = (1l<<(n-1)) + 1l; i < (1l<<(n)); i += 2l){
            int k;
            for(k = 2; k < 11; k++){
                a = base(i, k);       
                if(a.isProbablePrime(100)) break;
                v[k] = PollardRho.rho(a);
            }
            if(k == 11) {
                System.out.printf(a.toString());
                for(int p = 2; p < 11; p++) System.out.print(" " + v[p]);
                System.out.println();
                j--;
            }
            if(j == 0) break;
        }
        
    
    }
}
