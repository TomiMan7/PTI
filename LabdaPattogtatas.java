package labdapattogtatas;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author tomiman
 */
public class LabdaPattogtatas {

    public static void main(String[] args) throws IOException, InterruptedException {
        int width = 50, height = 25;
        int x = 10, y = 10;
        int x1 = x, y1 = y;
        int i = 0;

        while (true) {
            TimeUnit.SECONDS.sleep(1);
            for (i = 1; i < 2; i = i + 0) {

                x += Math.pow(-1, (x1 - 1) / (width - 3));
                y += Math.pow(-1, (y1 - 1) / (height - 3));
                x1++;
                y1++;

                for (i = 0; i < width; i++) {
                    System.out.print("#");

                }
                System.out.print("\n");

                for (i = 0; i < y - 1; i++) {
                    System.out.print("|");
                    for (int j = 0; j < width - 2; j++) {
                        System.out.print(" ");
                    }
                    System.out.print("|\n");
                }
                System.out.print(" ");
                for (i = 0; i < x - 1; i++) {
                    System.out.print(" ");
                }
                System.out.print("O");
                for (i = x + 1; i < width - 1; i++) {
                    System.out.print(" ");
                }
                System.out.print("|\n");

                for (i = y; i < height - 2; i++) {
                    System.out.print("|");
                    for (int j = 0; j < width - 2; j++) {
                        System.out.print(" ");
                    }
                    System.out.print("|\n");
                }

                for (i = 0; i < x - 1; i++) {
                    System.out.print("#");
                }
                System.out.print(" ");
                for (i = x; i < width; i++) {
                    System.out.print("#");
                }
                System.out.print("\nx: " + x + " y:" + y + "\n");
            }
        }
    }
}