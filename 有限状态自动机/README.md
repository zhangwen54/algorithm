### 有限状态自动机

概念：
有限状态自动机拥有有限数量的状态，每个状态可以迁移到零个或多个状态，输入字串决定执行哪个状态的迁移。有限状态自动机可以表示为一个有向图。

可以解决的问题类型：
涉及到不同状态之间相互转换的问题。

从题目上来理解：

例题1：去除一个字符串中连续的空格，即h___e__l_lo变成h_e_l_lo，其中‘_’表示空格。
解题思路：
首先从问题的解决思路上来看，我们用getchar()依次读取字符，并打印输出到终端：当第一次遇到空格时，一样打印空格，打印之后需要记住这次是空格，因为下一次可能是空格也可能是字符，如果下一次依然是空格，则直接丢弃空格继续判断下一个字符，如果下一次不是空格，则打印字符，同时之前的情况不再影响以后了，之前的记忆就可以清除了。
在上面的解决思路中，总共抽象出两种状态：一种是记住上一次打印为空格，一种是什么也不用记忆，在这里我们可以用0、1来表示。
状态0 (flag = 1) 若当前字符是空格，输出并跳转到状态1(flag = 1),如果是非空格，则打印字符；
状态1 (flag = 1) 若当前字符为非空格，则输出并跳转到状态0，若是空格，则不打印。

代码实现：
```C
#include <stdio.h>  

int main(int argc, char *argv[])
{  
    char flag = 0;  
    int ch;  
    while((ch = getchar()) != EOF)  
    {  
        switch(flag)  
        {  
        case 0:  
            if(ch == ' ')  
                flag = 1;  
            putchar(ch);  
            break;  
        case 1:  
            if(ch == ' ')  
                continue;  
            flag = 0;  
            putchar(ch);  
            break;  
        default:  
            break;  
        }  
    }  
    return 0;  
}

```
关于有限状态机问题的解题思路，可以画图或者写状态转移方程组来表示，可以方便地理清思路。继续通过题目加深理解：

例题2：""以内的字符和空格全部打印，""以外的如例题1，另外这道题还需要判断转义序列'\"'，比如he___l_lo___"li____hua"变成he_l_lo_"li____hua"。

解题思路：
有几种状态可以慢慢找出来，不用急于求成。
首先第一种状态：0
1、如果遇到是字符，打印，下一步；
2、如果遇到是空格'_'，打印，跳转到状态1；
3、如果遇到是"，打印，跳转到状态2。

由状态0得知还需要状态：1
1、如果遇到字符，打印，跳转到状态0；
2、如果遇到是_，不打印，下一步；
3、如果遇到是"，打印，跳转到状态2。

由状态0和状态1得知还需要状态：2
1、如果遇到"，打印，跳转到状态0；
2、如果遇到转义序列\"，打印，下一步；
2、其它任何字符，打印，下一步；

代码实现：
```C
#include <stdio.h>  

int main(int argc, char *argv[])  
{  
    char flag = 0;  
    int ch;  
    while((ch = getchar()) != EOF){  
        switch(flag){  
        case 0:  
            if(ch == ' ')  
                flag = 1;  
            if(ch == '"')  
                flag = 2;  
            putchar(ch);  
            break;  
        case 1:  
            if(ch != ' '){  
                flag = 0;  
                if(ch == '"')  
                    flag = 2;  
                putchar(ch);  
            }  
            break;  
        case 2:  
            if(ch == '"')  
                flag = 0;  
            if(ch == '\"')  
                ch = '"';  
            putchar(ch);  
            break;  
        default:  
            printf("error!\n");  
            break;  
        }  
    }  
    return 0;  
}  
```


参考文章：https://blog.csdn.net/baixiaoshi/article/details/77493899
练手题目：
表示数值的字符串：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

