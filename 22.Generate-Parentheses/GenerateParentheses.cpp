class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, 0,0,"",n);
        
        return res;
    }
private:
    void helper(vector<string>& res, int open, int close, string tmp, int n){
        if(tmp.length() == n*2)
            res.push_back(tmp);
        if(open < n)
            helper(res, open+1, close, tmp+'(', n);
        if(close < open)
            helper(res, open,close+1, tmp+')', n);
    }
};