class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()){//stack2 is empty
            while (stack1.size() > 0){
                int top = stack1.top();
                stack1.pop();
                stack2.push(top);
            }
        }
        if (stack2.empty()) throw new exception();
        int top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    stack<int> stack1;//push
    stack<int> stack2;//pop
};
