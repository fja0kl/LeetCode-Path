class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        int maxlen = INT_MIN;
        for(int i=0; i<n; i++){
            set<char> map;
            for(int j=i; j<n; j++){
                if(map.find(s[j]) == map.end())
                    map.insert(s[j]);
                else
                    break;
            }
            int cnt = map.size();
            maxlen = max(maxlen, cnt);
        }
        
        return maxlen;
    }
};
