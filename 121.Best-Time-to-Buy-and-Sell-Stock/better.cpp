/**
 * 不用管之后；
 * 按照买入时间前后依次计算；
 * 比较当前如果卖出，收益如何；同时取当前情况下收益的最大值；
 * 同时将买入价格设为截止到当前日期时，买入的最小值---为后续遍历做准备。
 *
 *
 * 不用两次训练；
 *
 * 复杂度降低O(N)
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) 
            return 0;
        
        int profit = 0;
        int minIn = prices[0];
        for(int i=1;i<prices.size();i++){
            profit = max(profit, prices[i]-minIn);
            minIn = min(minIn,prices[i]);
        }
        return profit;
    }
};
