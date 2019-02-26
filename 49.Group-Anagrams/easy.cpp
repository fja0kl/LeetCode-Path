class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        
        unordered_map<string, vector<string>> mapping;
        for (int i=0; i<strs.size(); i++){
            string key = getStrKey(strs[i]);
	    //mapping[key].push_back(strs[i]); 等效于下面的片段  
          if (mapping.find(key) != mapping.end()){
                mapping[key].push_back(strs[i]);
            } else {
                vector<string> t;
                t.push_back(strs[i]);
                mapping[key] = t;
            }
        }
        //store in the res
        for (auto k: mapping)
            res.push_back(k.second);
        
        return res;
    }
private:
    string getStrKey(string a){
        vector<int> count(26, 0);
        for (auto c: a)
            count[c - 'a']++;
        
        string key = "";
        for (int i = 0; i < 26; i++)
            key += to_string(count[i]);
        
        return key;
    }
};
