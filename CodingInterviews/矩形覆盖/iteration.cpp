class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) return 0;
        else if (number <= 2) return number;
        else{
            int result = 0, resNMns1 = 2, resNMns2 = 1;
            for (int i=3; i<=number; i++){
                result = resNMns1 + resNMns2;
                resNMns2 = resNMns1;
                resNMns1 = result;
            }
            return result;
        }
    }
};
