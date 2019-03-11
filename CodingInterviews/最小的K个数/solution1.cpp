class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k > input.size() || k <= 0) return {};
        
        vector<int> result;
        int start = 0, end = input.size()-1;
        int index = partition(input, start, end);
        
        while (index != k-1){
            if (index > k-1){
                end = index - 1;
                index = partition(input, start, end);
            }
            else {
                start = index + 1;
                index = partition(input, start, end);
            }
        }
        
        for (int i=0; i<k; i++)
            result.push_back(input[i]);
        
        return result;
    }
    int partition(vector<int>& arr, int low, int high){
        if (arr.empty() || low > high) return -1;
        int pivot = arr[high];
        int sortedIndex = low - 1;
        
        for (int i = low; i <= high-1; i++){
            if (arr[i] <= pivot){
                sortedIndex++;
                swap(arr[sortedIndex], arr[i]);
            }
        }
        swap(arr[sortedIndex+1], arr[high]);
        
        return sortedIndex+1;
    }
};
