# 题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

# Solution

依据partition函数，超过一半，那么排序后中位数一定是目标值；

注意验证性：如果不存在；如果输入数组为空;
