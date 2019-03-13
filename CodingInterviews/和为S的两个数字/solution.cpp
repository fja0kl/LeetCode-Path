class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if (array.empty()) return res;
        int left = 0, right = array.size() - 1;
        while (left < right){
            int tempSum = array[left] + array[right];
            if (tempSum == sum){
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            }
            else if (tempSum > sum)
                right--;
            else
                left++;
        }
        return res;
    }
};
