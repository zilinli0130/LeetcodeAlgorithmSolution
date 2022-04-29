class Solution {
    public int numSquares(int n) {
        
        boolean[] visited = new boolean[n + 1];
        List<Integer> squareNumbers = new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (i % 1 == 0) {
                squareNumbers.add(i * i);
                // System.out.println(i*i);
            }
        }
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(n);
        
        int res = -1;
        while (!queue.isEmpty()) {
            
            res++;
            int len = queue.size();
            while (len-- > 0) {
                
                int num = queue.poll();
                
                if (visited[num]) continue;
                visited[num] = true;
                
                if (num == 0) {
                    return res;
                }
                
                for (int squareNumber : squareNumbers) {
                    int diff = num - squareNumber;
                    if (diff < 0) continue;
                    if (visited[diff]) continue;
                    queue.add(diff);
                }
            }
        }
        return -1;
    }
}

    


