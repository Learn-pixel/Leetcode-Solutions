class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int arr[][] = new int[n][n];
        for(int i = 0; i < n; i++){
            arr[i][i] = piles[i];
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                arr[i][j] = Math.max(piles[i] - arr[i+1][j], piles[j] - arr[i][j-1]);
            }
        }
        return arr[0][n-1]>0;
    }
}