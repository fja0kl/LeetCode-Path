class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;
        int current = 0, before = 0, after = 0;
        while (n/i != 0){
            current = (n / i) % 10;//当前位
            before = n / (i * 10);//高位
            after = n - (n / i) * i;//低位
            
            if (current == 0)//当前位等于0，由更高位决定
                count += before * i;
            // 当前位等于1：由更高位和低位决定:高位*当前位+低位+1
            else if (current == 1)
                count += before * i + after + 1;
            else
                //如果大于1,出现1的次数由高位决定,（高位数字+1）* 当前位数
                count += (before + 1) * i;
            
            i *= 10;
        }
        return count;
    }
};
