typedef pair<int, int> PII;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        char prevDir = 'U';
        long res = 0;
        int idx1 = 0, idx2 = 0, x = 0, y = 0;
        set<PII> obstacleSet;
        unordered_map<char, char> leftMap{{'U','L'},{'D','R'},{'L','D'},{'R','U'}};
        unordered_map<char, char> rightMap{{'U','R'},{'D','L'},{'L','U'},{'R','D'}};
        
        for (const auto& obstacle : obstacles) {
            obstacleSet.emplace(pair(obstacle[0], obstacle[1]));
        }
        
        for (int i = 0; i < commands.size(); i++) {
            
            int command = commands[i];
            if (command == -2) {
                prevDir = leftMap[prevDir];
            } else if (command == -1) {
                prevDir = rightMap[prevDir];
            } else {
                for (int j = 0; j < command; j++) {
                    if (prevDir == 'U' && obstacleSet.find(pair(x,y+1)) == obstacleSet.end()) {
                        y++;
                        continue;
                    } else if (prevDir == 'D' && obstacleSet.find(pair(x,y-1)) == obstacleSet.end()) {
                        y--;
                        continue;
                    } else if (prevDir == 'L' && obstacleSet.find(pair(x-1,y)) == obstacleSet.end()) {
                        x--;
                        continue;
                    } else if (prevDir == 'R' && obstacleSet.find(pair(x+1,y)) == obstacleSet.end()) {
                        x++;
                        continue;
                    }
                    break;
                }
            }
            res = max(res, (long)(x*x+y*y));
        }
        return res;
    }
};