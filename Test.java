public class Test {
    public static void main(String[] args) {
        int S = 10;
        int [] N = {1,2,3,4};
        int T = 1;
        int result = countSeries(S, N, T);
        System.out.println(result);
    }

    // public static int countSeries(int S, int N, int T) {
    //     int MOD = 1000000007;
    //     int[][] dp = new int[N + 1][S + 1];

    //     for (int i = T; i <= Math.min(S, T * N); i++) {
    //         dp[1][i] = 1;
    //     }

    //     for (int n = 2; n <= N; n++) {
    //         for (int s = 1; s <= S; s++) {
    //             for (int t = 1; t <= T; t++) {
    //                 if (s - t >= 0) {
    //                     dp[n][s] = (dp[n][s] + dp[n - 1][s - t]) % MOD;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[N][S];
    // }
    public static int countSeries(int input1, int[] input2, int input3) {
        queue<>
        return 0;
    }
}