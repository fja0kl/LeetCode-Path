class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stack;//栈的思想，也可以不使用栈：数组也可以，但最好是动态的
        for(int i=0;i<ops.size();i++){//下标遍历vector容器
            if(ops[i] == "C"){
                stack.pop_back();
            }
            else if(ops[i] == "D"){
                stack.push_back(2*stack.back());
            }
            else if(ops[i] == "+"){
                stack.push_back(stack.back()+stack[stack.size()-2]);//下标访问元素
            }
            else{
                //string2int
                //int a = stoi(ops[i].c_str());//c stoi函数
                stack.push_back(stoi(ops[i]));
            }
        }
        return accumulate(stack.begin(),stack.end(),0);//vector求和；第三个参数指定返回类型，同时容器里元素能转换到该类型，且表示和的初始值；
        // int sum = 0;
        // for(int i=0;i<stack.size();i++)
        //     sum += stack[i];
        // return sum;
    }
};
