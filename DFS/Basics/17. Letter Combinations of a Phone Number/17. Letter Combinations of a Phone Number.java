class Solution {
    List<String> res;
    Map<Character, String> map;
    public List<String> letterCombinations(String digits) {
        
        res = new ArrayList<>();
        
        if (digits.length() == 0) {
            return res;
        }
        
        map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
        dfs(digits, new StringBuilder(), 0);
        return res;
    }
    
    void dfs(String digits, StringBuilder temp, int idx) {
        
        if (idx == digits.length()) {
            res.add(temp.toString());
            return;
        }
        
        String str = map.get(digits.charAt(idx));
        for (int i = 0; i < str.length(); i++) {
            temp.append(str.charAt(i));
            dfs(digits, temp, idx + 1);
            temp.setLength(temp.length() - 1);
        }
    }
}