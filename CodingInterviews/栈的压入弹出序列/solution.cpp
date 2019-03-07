class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty() || popV.empty()) return false;
        if (pushV.size() != popV.size()) return false;
        stack<int> dataStack;
        for (int i=0, j=0; i<pushV.size();){
            dataStack.push(pushV[i++]);//入栈
            // 如果栈顶元素和当前pop序列头元素相同，弹出
            while (j<popV.size() && dataStack.top() == popV[j]){
                dataStack.pop();
                j++;
            }
        }
        return dataStack.empty();
    }
};
