class Solution
{
public:
    Solution(){
        index = 0;
        for (int i=0; i<256; i++)
            occurence[i] = -1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (occurence[ch] == -1)
            occurence[ch] = index;//第一次出现，value设置为出现的下标
        else if (occurence[ch] >= 0)
            occurence[ch] = -2;
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char res = '\0';
        int minIdx = INT_MAX;
        for (int i=0; i< 256; i++){
            // 保证minIdx是最小的，最先出现
            if (occurence[i] >= 0 && occurence[i]< minIdx){//第一次出现
                res = (char)i;//记录字符
                minIdx = occurence[i];//记录字符出现的index
            }
        }
        if (res == '\0')
            return '#';
        return res;
    }
private:
    int occurence[256];
    int index;
};
