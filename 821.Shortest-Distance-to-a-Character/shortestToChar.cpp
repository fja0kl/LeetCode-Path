/**
 * 最小值的求法：时机
 */
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> indices;
        vector<int> res(S.size(),S.size());
        for(int i=0;i<S.size();i++)
            if(S[i] == C) indices.push_back(i);
        
        for(int i=0;i<S.size();i++)//对每个字符，遍历计算重复下标距离的最小值
            for(int j=0;j<indices.size();j++)//
                res[i] = min(res[i], abs(indices[j]-i));//indices[i]-j计算重复下标当前下标与字符的距离，遍历求最小值
        
        return res;
    }
};
