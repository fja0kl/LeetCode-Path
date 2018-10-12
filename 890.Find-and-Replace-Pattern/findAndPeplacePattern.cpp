/**
 * unordered_map<char,string> 字典
 * 插入时：
 * unordered_map.insert({'a',"b"});字典里面是逗号分割
 */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string b) {
        vector<string> res;
        string p = isSame(b);
        for(auto ele : words){
            if(isSame(ele) == p)
                res.push_back(ele);
        }
        return res;
    }
    string isSame(string a){
        unordered_map<char,string> to;
        string ret = "";
        int idx = 0;
        for(auto w:a){
            if(to.find(w) == to.end())
                to.insert({w,to_string(idx++)});
            ret += to.find(w)->second;
        }
        return ret;
    }
};

