# 题目描述

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

# Solution

不能用循环。

用递归实现；那么，最主要的问题就在于，如何退出递归--递归终止条件怎么实现：

条件符合，不再进行计算，返回结果，向上回归。

短路与---前面条件不符合，后面就不再计算；终止递推，开始回归运算。


