class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0) return 0;
        int result = 1;
        for (int i=1; i<number; i++){
            result *= 2;
        }
        return result;
    }
};
