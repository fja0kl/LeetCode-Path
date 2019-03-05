# 问题描述

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

# Solution

一个栈用来入队列，一个栈用来出队列。

stack1 入队列，stack2 出队列。

出队列：如果stack1不为空，将stack1中元素全部出栈，压入stack2中，stack2中top元素是最先入队列的，从上到下就是元素入队列的顺序，正好符合队列的顺序。入栈stack算颠倒一次顺序，两次入栈顺序和原始顺序相同。

入队列：直接进入stack1中。

# Tests

stack1,stack2都为空：直接出队列，exception；

stack1，stack2都为空:入队列；

stack1不为空，stack2为空：出队列；入队列

stack1为空，stack2不为空：出队列；入队列

stack1，stack2都不为空：入队列；出队列。
