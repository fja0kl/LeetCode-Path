class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> allResults;
        if (sum <= 0) return allResults;
        int low = 1, high = 2;
        while (high > low){
            int current = (low + high)*(high - low + 1)/2;
            if (current == sum){
                vector<int> result;
                for (int i=low; i<=high; i++)
                    result.push_back(i);
                allResults.push_back(result);
                low++;
            }
            else if (current < sum)
                high++;
            else
                low++;
        }
        return allResults;
    }
};
