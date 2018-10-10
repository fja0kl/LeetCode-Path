/**
 * O(N^2)
 * 复杂度太高
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
            int maxPrice = 0;
            for(int j=i+1;j<prices.size();j++){
                maxPrice = max(maxPrice,prices[j]);
            }
            profit = max(profit, maxPrice-prices[i]);
        }
        
        return profit;
    }
};
