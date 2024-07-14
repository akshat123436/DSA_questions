import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        int ans = 0;
        if(input2 < 3) return 0;
        for (int i = 0; i < input2 - 2; i++) {
            if (input1[i] + input1[i + 2] == input1[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
}
