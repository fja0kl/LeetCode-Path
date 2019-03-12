class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //if (data.empty()) return -1;
        int firstIdx = getFirstIdxOfK(data,k,0,data.size()-1);
        int lastIdx = getLastIdxOfK(data, k,0,data.size()-1);
        int times = 0;
        if (firstIdx > -1 && lastIdx > -1)
            times = lastIdx - firstIdx + 1;
        return times;
    }
    int getFirstIdxOfK(vector<int> data, int k, int low, int high){
        if (low > high)//没找到
            return -1;
        int mid = (low + high) >> 1;
        int midData = data[mid];
        //比较
        if (midData == k){//确保是第一次出现
            if ((mid > 0 && data[mid-1] != k) || mid == 0)
                return mid;
            else
                high = mid - 1;
        }
        else if (midData < k)
            low = mid + 1;
        else
            high = mid - 1;
        //接着查找
        return getFirstIdxOfK(data,k,low,high);
    }
    int getLastIdxOfK(vector<int> data, int k, int low, int high){
        if (low > high)
            return -1;
        int mid = (low + high) >> 1;
        int midData = data[mid];
        if (midData == k){
            if ((mid < data.size()-1 && data[mid+1] != k) || mid == data.size() - 1)
                return mid;
            else
                low = mid + 1;
        }
        else if (midData < k)
            low = mid + 1;
        else
            high = mid - 1;
        
        return getLastIdxOfK(data,k,low,high);
    }
};
