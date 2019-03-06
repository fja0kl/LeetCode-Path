class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) return;
        vector<int> res;
        for(int i=0; i<array.size(); i++){
            if (!isEven(array[i]))
                res.push_back(array[i]);
        }
        for(int i=0; i<array.size(); i++){
            if (isEven(array[i]))
                res.push_back(array[i]);
        }
        for(int i=0; i<array.size(); i++){
            array[i] = res[i];
        }
    }
    bool isEven(int number){//偶数
        if ((number & 0x1) == 0)
            return true;
        return false;
    }
};
