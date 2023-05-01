class Solution {
public:
    double average(vector<int>& salary) {
        double avgSal = 0;
        int maxSal = INT_MIN;
        int minSal = INT_MAX;
        
        // sort(salary.begin(), salary.end());
        
        int totalSum = 0;
        int n = salary.size();
        
        // for(int i = 1; i < n-1; i++){
        //     totalSum+=salary[i];
        // }
        
        // avgSal = totalSum/((n-2)*1.0);
        
        for(int i = 0; i<n; i++){
            totalSum+=salary[i];
            maxSal = max(maxSal, salary[i]);
            minSal = min(minSal, salary[i]);
        }
        
        int deduction = maxSal + minSal;
        
        avgSal = (totalSum - deduction)/((n-2)*1.0);
        
        return avgSal;
        
    }
};