import java.io.*;
import java.util.*;

class Main {
    
    public class Bit {
        int max = 10000007;
        long[] bit = new long[max];

        long query(int idx) {
            long sum = 0;
            for(int i = idx; i > 0; i -= i&-i)
                sum += bit[i];
            return sum;
        }
        void update(int idx, int val) {
            for(int i = idx; i < max; i += i&-i)
                bit[i] += val;
        }
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int t,n;
        int[] v = new int[200003];
        t = sc.nextInt();
        for(int w = 0; w < t; w++){    
            Bit foo = new Bit();
            n = sc.nextInt();
            for(int i = 0; i < n; i++)
                v[i] = sc.nextInt();
            long ans = 0;
            for(int i = 0; i < n; i++) {
                ans += i-foo.query(v[i]);
                foo.update(v[i],1);
            }
            System.out.println(ans);
        }
    }
    public static void main (String[] args) {
        new Main().solve();
    }
}
