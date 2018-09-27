class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        result = {}
        
        for domain in cpdomains:
            n, record = domain.strip().split()
            n, record = int(n), record.strip().split('.')
            for i in range(len(record)):
                s = '.'.join(record[i:])#连接，形成对应的键
                # 在字典中查找如果不存在置为0，再加上本身的计数
                result[s] = result.get(s, 0) + n
        
        return [str(result[i]) + ' ' + i for i in result]#列表推导式
