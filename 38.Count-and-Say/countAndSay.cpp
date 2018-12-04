/**
Same Solution
**/
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        if (n == 1) return "1";
        string pre = countAndSay(n-1) + "*";
        int cnt = 1; 
        string res = "";
        //对上次输出结果进行遍历
        for(int i=0;i<pre.size()-1;i++){
            if (pre[i] == pre[i+1])
                cnt++;
            else{
                res = res + to_string(cnt) + pre[i];
                cnt = 1;
            }
        }
        return res;
    }
};
