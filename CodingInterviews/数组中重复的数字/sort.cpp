/**
* 超时。
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
        // after the validation, solve the problem
        /**for (int i=0; i<length; i++){
            while (numbers[i] != i){
                if (numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;**/
        sort(numbers, numbers+length);
        for (int i=0; i<length; i++){
            /*并不一定是重复数字；有可能0缺失，这样nums[i] != i,
            * 但是还有可能存在重复数字,比如：[1,2,2,3,4]
            */
            while (numbers[i] != i){
                if (numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
            }
        }
        return false;
    }
};
