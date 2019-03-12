class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) return "";
        string answer = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i=0; i< numbers.size(); i++)
            answer += to_string(numbers[i]);
        
        return answer;
    }
    static bool cmp(int a, int b){
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        
        return A < B;
    }
};
