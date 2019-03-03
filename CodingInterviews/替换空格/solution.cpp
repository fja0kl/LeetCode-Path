class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == nullptr || length <= 0) return;
        int originLength = 0, numOfBlank = 0;
        int i = 0;
        // count the length of str and the number of blank in the str.
        while (str[i] != '\0'){
            if (str[i] == ' ')
                numOfBlank++;
            originLength++;
            i++;
        }
        int newLength = originLength + numOfBlank * 2;
        // check the vality of the newLength (<= length);
        // length: the total size of the array, containing the empty set
        if (newLength > length) return;
        int indexOfNew = newLength, indexOfOrigin = originLength;
        // iterate the array, set the new result
        while (indexOfOrigin >= 0){
            // the blank
            if (str[indexOfOrigin] == ' '){
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            } else {//not blank
                str[indexOfNew--] = str[indexOfOrigin];
            }
            // the same operation
            indexOfOrigin--;
        }
	}
};
