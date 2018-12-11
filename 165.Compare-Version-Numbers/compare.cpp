/**
自己分割:依据分割符;同时计算对应整数,然后比较;

1.12 1.124 -1
**/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        int M = version1.size(), N = version2.size();
        while(i<M || j<N){
            //根据. 分割字符串,并转换成10进制.
            int tmp1=0, tmp2=0;
            while(i<M && version1[i] != '.'){
                tmp1 = tmp1*10 + version1[i] - '0';
                i++;
            }
            while(j<N && version2[j] != '.'){
                tmp2 = tmp2*10 + version2[j] - '0';
                j++;
            }
            //判断两个数大小
            if(tmp1 > tmp2) return 1;
            else if(tmp1 < tmp2) return -1;
            //相等,更新i,j---跳过.字符
            i++;
            j++;
        }
        return 0;
    }
};
