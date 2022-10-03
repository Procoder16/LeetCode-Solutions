class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        auto prevColor{colors[0]};
        auto prevSum{0};
        auto prevMax{0};
        auto res{0};

        for (auto i = 0; i != neededTime.size(); ++i) {
            if (colors[i] != prevColor) {
                res += prevSum - prevMax;
                prevSum = prevMax = 0;
                prevColor = colors[i];
            }

            prevSum += neededTime[i];
            prevMax = std::max(prevMax, neededTime[i]);
        }

        return res + prevSum - prevMax;
    }
};
