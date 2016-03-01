import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class UVA10925 {
        public static void main(String[] argv){
            int N, F, i, turn = 1;
            Scanner scan = new Scanner(System.in);
            while (true) {
        
                N = scan.nextInt();
                F = scan.nextInt();
                if (N == 0 && F == 0){
                    break;
                }   
                BigInteger price, sum = BigInteger.ZERO;
                for (i = 0; i < N; i++){
                    price = scan.nextBigInteger();
                    sum = sum.add(price);
                }
                System.out.printf("Bill #%d costs %d: each friend should pay %d\n\n", turn, sum, sum.divide(BigInteger.valueOf(F)));
                turn ++;
            }
        }
}
