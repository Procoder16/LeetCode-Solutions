class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        const int n = points.size();

        if(n == 1)
            return 1;

        int total_max = 0;

        for(int i = 0; i < n; ++i) {
            unordered_map<string, int> slopes;
            unordered_map<int, int> vertical, horizontal;

            int max_line = 0;

            for(int j = i+1; j < n; ++j) {

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(y1 == y2) {
                    ++horizontal[y1];
                    max_line = max(max_line, horizontal[y1] + 1);
                }
                else if(x1 == x2) {
                    ++vertical[x1];
                    max_line = max(max_line, vertical[x1] + 1);
                }
                else {
                    int y = y2 - y1;
                    int x = x2 - x1;
                    string sign = (y > 0 && x > 0) || (y < 0 && x < 0) ? "+" : "-";
                    
                    y = abs(y);
                    x = abs(x);

                    int g = __gcd(y, x);

                    y /= g;
                    x /= g;

                    string key = sign + to_string(y) + "/"+to_string(x);
                    ++slopes[key];

                    max_line = max(max_line, slopes[key] + 1);
                }

            }

            total_max = max(total_max, max_line); 
        }



        return total_max;
    }
};