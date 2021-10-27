### 快速幂

例题1：求A^B的最后三位数表示的整数（1<=A,B<=10000）

求解代码1：快速幂递归实现
```
int power(int a, int n){
    int ans;
    if(n==0)ans=1;
    else{  
        ans=power(a*a, n/2);
        if(n%2==1)ans*=a;
    }
     return ans;
}

```
求解代码2：快速幂非递归实现
```
int power(int a, int n){
    int ans=1;
    while(n){
         if(n&1)ans=*a;
         a*=a;
         n>>=1;
     }
     return ans;
}

```

练习题：
 数值的整数次方：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/