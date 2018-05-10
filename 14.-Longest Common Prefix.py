#coding:utf8


def longestCommonPrefix(strs):
    """
    :type strs: List[str]
    :rtype: str
    """
    if len(strs) == 0:
        return ""
    result = strs[0]
    for i in range(1, len(strs)):
        # minLen = len(result)>len(strs[i])?len(strs[i]):len(result)
        minLen = min(len(result), len(strs[i]))
        index = 0
        for j in range(minLen):
            print(result[j],strs[i][j])
            if (result[j] == strs[i][j]):
                index += 1
                continue
            else:
                break
        result = result[:index]
        
        if len(result) == 0:
            return ""
    return result
