class Solution {
    public int reverseDegree(String s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            int p = 26 - (int)(s.charAt(i) - 'a');
            System.out.println(p);
            sum+=(i+1)*p;
        }
        return sum;
    }
}