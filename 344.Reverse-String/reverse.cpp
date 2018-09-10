class Solution {
public:
    string reverseString(string s) {
        stack<char> stack;
        for(int i=0;i<s.length();i++)
            stack.push(s[i]);
        for(int j=0;j<s.length();j++){
            s[j] = stack.top();
            stack.pop();
        }
        return s;
    }
};
