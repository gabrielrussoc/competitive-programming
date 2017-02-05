import java.io.*;
import java.math.*;
import java.util.*;

public class B9 {

    static Scanner in;  
    static PrintWriter out = new PrintWriter(System.out);
    BigInteger[] memo = new BigInteger[202];
    BigInteger[][] c = new BigInteger[202][202];
    BigInteger[] f = new BigInteger[202];
    BigInteger[] d = new BigInteger[202];

    BigInteger dp(int n) {
        if(n == 0) return BigInteger.ONE;    
        if(memo[n] != null) return memo[n];
        memo[n] = dp(n-1);
        for(int i = 2; i <= n; i++) memo[n] = memo[n].add(c[n-1][i-1].multiply(d[i]).multiply(f[i-1]).multiply(dp(n-i)));
        return memo[n];
    }
    
    void run(){
        int n = in.nextInt();
        f[0] = BigInteger.ONE;
        d[0] = BigInteger.ONE;
        for(int i = 1; i <= n; i++) f[i] = f[i-1].multiply(BigInteger.valueOf(i));
        for(int i = 1; i <= n; i++) d[i] = d[i-1].multiply(new BigInteger("2"));
        for(int i = 1; i <= n; i++) c[0][i] = BigInteger.ZERO;
        for(int i = 0; i <= n; i++) c[i][0] = BigInteger.ONE;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) 
                c[i][j] = c[i-1][j].add(c[i-1][j-1]);
        out.println(dp(n));
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("derangements.in"));
        out = new PrintWriter(new File("derangements.out"));
        new B9().run();   
        out.close();
    }
}
