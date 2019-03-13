class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1) return -1;
        list<int> ring;
        for (int i=0; i<n; i++)
            ring.push_back(i);
        list<int>:: iterator current = ring.begin();
        // 删除元素:剩一个
        while (ring.size() > 1){
            // 循环移动，得到要删除的元素
            for (int i = 1; i< m; i++){
                current++;
                if (current == ring.end())
                    current = ring.begin();
            }
            list<int>::iterator next = ++current;
            if (next == ring.end())
                next = ring.begin();
            --current;
            ring.erase(current);
            current = next;
        }
        return *current;
    }
};
