/**
 * 最小栈：主要是记录最小值；
 */
class MinStack {
private:
    vector<int> nums;
    int minNum;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(nums.empty()) minNum = x;
        else minNum = min(minNum, x);
        
        nums.push_back(x);
    }
    
    void pop() {
        if(top() == minNum){
            minNum = INT_MAX;
            for(int i=0;i<nums.size()-1;i++)
                minNum = min(minNum, nums[i]);
        }
        nums.pop_back();
    }
    
    int top() {
        return nums.back();
    }
    
    int getMin() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
