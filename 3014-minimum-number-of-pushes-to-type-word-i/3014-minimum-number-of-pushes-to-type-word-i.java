class Solution {
    public int minimumPushes(String word) {
        int l = word.length();
        int p = 0;
        if(l < 8){
            return l;
        }
        int temp = l;
        int i = 1;
        while(temp > 8){
            p += 8 * i;
            temp -= 8;
            i++;
        }
        p += temp * i;
        return p;
    }
}