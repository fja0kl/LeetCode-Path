class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int numbOfZeros = 0;
        int numbOfGaps = 0;
        for (int i=0; i<numbers.size() && numbers[i] == 0; i++)
            ++numbOfZeros;
        int small = numbOfZeros;
        int big = small + 1;
        while (big < numbers.size()){
            if (numbers[small] == numbers[big])
                return false;
            numbOfGaps += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }
        return numbOfZeros >= numbOfGaps;
    }
};
