/**
 * 本质上是一种对应关系---编码，解码
 * unsorted_map 一种字典形式
 * 结论：如果需要内部元素自动排序，使用map，不需要排序使用unordered_map
 * 插入元素为字典形式；取元素时，第一个值用first；第二个值用second
 */
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto key = to_string(index);
        map.insert({key, longUrl});
        
        index++;
        
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto retVal = map.find(shortUrl);
        
        return retVal->second;
    }
private:
    unordered_map<string,string> map;
    uintmax_t index = {0};
};

