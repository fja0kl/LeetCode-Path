class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        int index1 = 0, index2 = rotateArray.size()-1;
        int indexMid = index1;
        while (rotateArray[index1] >= rotateArray[index2]){
            if (index1 == index2 - 1){
                indexMid = index2;
                break;
            }
            indexMid = (index1 + index2) / 2;
            if (rotateArray[index1] == rotateArray[index2] && 
                rotateArray[index1] == rotateArray[indexMid])
                return MinInOrder(rotateArray,index1, index2);
            if (rotateArray[indexMid] >= rotateArray[index1])
                index1 = indexMid;
            else if (rotateArray[indexMid] <= rotateArray[index2])
                index2 = indexMid;
        }
        return rotateArray[indexMid];
    }
    int MinInOrder(vector<int> arr, int start, int end){
        int res = arr[start];
        for (int i=start+1; i<=end; i++){
            if (arr[i] < res)
                res = arr[i];
        }
        return res;
    }
};
