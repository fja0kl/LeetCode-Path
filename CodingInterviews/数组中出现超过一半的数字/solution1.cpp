class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int mid = numbers.size() >> 1;
        int start = 0 , end = numbers.size() -1;
        int index = partition(numbers, start, end);
        while (index != mid){
            if (index < mid){
                start = index + 1;
                index = partition(numbers, start, end);
            }
            else {
                end = index - 1;
                index = partition(numbers, start, end);
            }
        }
        int result = numbers[mid];
        if (!checkMoreThanHalf(numbers, result)) return 0;
        return result;
    }
    int partition(vector<int>& numbs, int lo, int hi){
        int pivot = numbs[hi];
        int i = lo - 1 ;//sorted array index
        // 左半部分小于等于pivot，右半部分大于pivot
        for (int j = lo; j <= hi - 1; j++){
            if (numbs[j] <= pivot){
                i++;
                swap(numbs[i], numbs[j]);
            }
        }
        //返回变化后pivot所在index
        swap(numbs[i+1], numbs[hi]);
        return i+1;
    }
    bool checkMoreThanHalf(vector<int> arr, int target){
        int times = 0;
        for (int i=0; i< arr.size(); i++)
            if (arr[i] == target)
                times++;
        return times * 2 > arr.size();
    }
};
