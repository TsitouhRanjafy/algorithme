import java.util.Arrays;

public class CredibleDEratosthene {

    public static void main(String[] args) {
        int n = 100 ; // trouver les nombres premier jusqu'a 100
        boolean[] premiers =  credibleDEratosthene(n);

        for (int i=2;i <= n;i++){
            if (premiers[i]){
                System.out.print(i + " ");
            }
        }
    }

    private static boolean[] credibleDEratosthene(int n) {
        boolean[] premier = new boolean[n+1]; // créer un tableau boolean premier
        Arrays.fill(premier,true); // tout centenu du tableau premiers est true
        premier[0] = false;
        premier[1] = true;

        for (int p = 2; p * p <= n;p++){
            if (premier[p]){
                for (int i= p * p;i<=n;i+=p){
                    premier[i] = false;
                }
            }
        }

        return premier;
    }
}