// Flag: n00bz{r3v_1s_s0_e4zy_r1ght??!!}
import java.util.Arrays;


public class EZrev {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("L");
            return;
        }
        String flag = args[0];
        if (flag.length() != 31) {
            System.out.println("L");
            return;
        }
        int[] f = flag.chars().toArray();
        for (int i = 0; i < f.length; i++) {
            if (i % 2 == 0) {
                f[i] = (char)(((int)f[i]) ^ 0x13);
            } else {
                f[i] = (char)(((int)f[i]) ^ 0x37);
            }
        }
        for (int i = 0; i < f.length/2; i++) {
            if (i % 2 == 0) {
                int temp = (int)f[i] - 10;
                f[i] = (char)(((int)f[f.length-1-i]) + 20);
                f[f.length-1-i] = (char)(temp);
            } else {
                f[i] = (char)((int)f[i] + 30);
            }
        }
        int[] theFlag = new int[] {130, 37, 70, 115, 64, 106, 143, 34, 54, 134, 96, 98, 125, 98, 138, 104, 25, 3, 66, 78, 24, 69, 91, 80, 87, 67, 95, 8, 25, 22, 115};
        // for (int i = 0; i < f.length; i++) {
        //     System.out.println(f[i] + " " + theFlag[i]);
        // }
        if (Arrays.equals(f, theFlag)) {
            System.out.println("W");
        } else {
            System.out.println("L");
        }
    }
}
