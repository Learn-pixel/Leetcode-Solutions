class Solution {
    public int minimumPushes(String word) {
        Map<Character, Integer> count = new HashMap<>();
        for(char c : word.toCharArray()){
            count.put(c, count.getOrDefault(c , 0) + 1);
        }   
        List<Integer> freq = new ArrayList<>(count.values());
        Collections.sort(freq, Collections.reverseOrder());
        int p = 0;
        for(int i = 0; i < freq.size(); i++){
            p += freq.get(i) * ((i/8) + 1);
        }
        return p;
    }
}