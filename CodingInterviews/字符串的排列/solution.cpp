class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.empty()) return result;
        permutation(str, 0, result);
        sort(result.begin(), result.end());
        return result;
    }
    void permutation(string str, int begin, vector<string>& res){
        if (str[begin] == '\0'){
            res.push_back(str);
            return;
        }
        for (int i=begin; i< str.size(); i++){
            if (i==begin || str[i] != str[begin]){
                swap(str[i], str[begin]);
                permutation(str, begin+1, res);
                swap(str[i], str[begin]);
            }
        }
    }
};
