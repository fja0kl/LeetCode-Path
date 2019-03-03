/**
* 空间换时间。O(n)空间复杂度
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // validate the solid values: numbers & length--not null
        if (numbers == nullptr || length <=0) return false;
        // if the numbers is not null, validate the elements in the array
        // the value of the element is less than length, greater than 0
        for (int i=0; i<length; i++){
            if (numbers[i] <0 || numbers[i] >= length)
                return false;
        }

        unordered_map<int, bool> hash;
        for (int i=0; i<length; i++){
            if (hash.find(numbers[i]) != hash.end()){
                *duplication = numbers[i];
                return true;
            }
            hash[numbers[i]] = true;
        }
        
        return false;
    }
};
