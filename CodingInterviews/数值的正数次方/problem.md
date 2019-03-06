# 题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

# Solution

全面性 & 异常值。

整数次方：

a的n次方：

- n为偶数：$a^n = a^{n/2} * a^{n/2}$

- n为奇数：$a&n = a^{(n-1)/2} * a^{(n-1)/2} * a$

可以用递归方法求解。


