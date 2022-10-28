public class Kary {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        //int k = Integer.parseInt(args[1]);

        int power = 1;
        while (power <= x / 2) {
            power *= 2;
        }

        // check for presence of powers of 2 in n, from largest to smallest
        while (power > 0) {

            // power is not present in n
            if (x < power) {
                System.out.print(0);
            }

            // power is present in n, so subtract power from n
            else {
                System.out.print(1);
                x -= power;
            }

            // next smallest power of 2
            power /= 2;
        }

        System.out.println();
    }
}

