class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
	// vector判断是否为空
        if (strs.empty()) return res;
        
        unordered_map<string, vector<string>> mapping;
        for (auto& str : strs){
            string t = str;
            sort(t.begin(), t.end());
	    // 包含多个步骤：将t加入mapping键中，然后将值加入数组中(t存在，不存在)；
	    // 自动生成vector<string>，然后push_back;
            mapping[t].push_back(str);
        }
        //store in the res
        for (auto& k: mapping)
            res.push_back(k.second);
        
        return res;
    }

};
