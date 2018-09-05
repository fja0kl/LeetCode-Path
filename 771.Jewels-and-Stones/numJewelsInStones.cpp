/**
 * 时间复杂度O(n*n)；
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int nums = 0;
        for(int i=0;i<J.length();i++){
            for(int j=0;j<S.length();j++){
                if(J[i] == S[j])
                    nums++;
            }
        }
        return nums;
    }
};
//other solution
// 时间复杂度O(n)；空间复杂度O(1);
// better
int numJewelsInStones(string J, string S) {
	int exist[256] = {0}; //ASCII码表长度：多出一倍
        for (int i = 0;i < J.length();i++) {
            exist[J.at(i)] = 1;//字符转数字，在对应数组位置中设为1；
        }
        int num = 0;
        for (int i = 0;i < S.length();i++) {
            if (exist[S.at(i)]) {//如果S中字符在数组中对应位置出现，num++
                num++;
            }
        }
        
        return num;
}
