# 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

# Solution

应用了辅助栈。

如果只使用一个变量存储当前最小值，会出错；如果存储最小值被pop弹出，变量指向的最小值就会出错。 辅助栈，当数据栈有数据入栈时，同时完成辅助栈的入栈，压入的是当前的最小值(辅助栈也存储着前面栈中的目前的最小值)。


