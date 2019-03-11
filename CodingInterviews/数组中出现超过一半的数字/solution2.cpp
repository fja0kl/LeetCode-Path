/**
不修改原始数组
**/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int result = numbers[0];
        int times = 1;
        for (int i=1; i<numbers.size(); i++){
            if (times == 0){
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] != result)
                times--;
            else
                times++;
        }
        
        if (!checkMoreThanHalf(numbers, result)) return 0;
        return result;
    }
    bool checkMoreThanHalf(vector<int> arr, int target){
        int times = 0;
        for (int i=0; i< arr.size(); i++)
            if (arr[i] == target)
                times++;
        return times * 2 > arr.size();
    }
};
