"""
单个字母计数,单个变量就可以实现,不用使用字典!!!

New: 添加额外字符,保证遍历原始输入时不会发生溢出
计数方式: 先设为1,和之后元素比较;从第二个元素开始比较,如果第二个和第一个相等,cnt++;
之前的计数方式,都是从0开始,也就是从第一个元素开始,第一个元素一定是1,所以省略这个过程
"""
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        # 保证不会越界
        pre = self.countAndSay(n-1) + '0'
        cnt = 1 # 计数
        res = "" 
        for i in range(len(pre)-1):# 对(n-1)th返回结果进行遍历,统计连续字母出现次数; -1:保证遍历的是原字符串
            if pre[i] == pre[i+1]:#连续相同字母
                cnt += 1
            else:#不连续,结果更新,完成单个字母的count & say,同时重置cnt
                res = res + str(cnt) + pre[i]
                cnt = 1 
                
        return res
