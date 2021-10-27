### 摩尔投票法

算法概述：
摩尔投票法（Boyer–Moore majority vote algorithm），也被称作「多数投票法」,算法解决的问题是：如何在任意多的候选人中（选票无序），选出获得票数超过总票数一半的那个。

算法可以分为两个阶段：
1、对抗阶段：分属两个候选人的票数进行两两对抗抵消
2、计数阶段：计算对抗结果中最后留下的候选人票数是否有效

注意：所要寻找的数量最多的选票一定要超过总数量的一半，比如总票数4票，则必须3票以及3票以上才可以求解，因为只要两票的话有可能被另外两个票分别抵消掉。

例题1：假设有一个字母数组ans={'A','D','C','B','A','A','A'}，存在一个字母数量超过数组大小的一半，找出这个字母。
解决思路：
开始计数对抗：
1、ans[0]——》['A',1];表示对抗到当前位置，对抗抵消后还剩下一个A；
2、ans[1]——》['A',0];A和D进行对抗后，互相抵消了，啥也不剩；
3、ans[2]——》['C',1];表示对抗到当前位置，对抗抵消后还剩下一个C；
4、ans[3]——》['C',0];C和B进行对抗后，互相抵消了，啥也不剩；
5、ans[4]——》['A',1];表示对抗到当前位置，对抗抵消后还剩下一个A；
6、ans[5]——》['A',2];表示对抗到当前位置，对抗抵消后还剩下两个A；
7、ans[6]——》['A',3];表示对抗到当前位置，对抗抵消后还剩下三个A；
最后只剩下A，所以答案是A。
算法实现：
```C++
char findMost(vector<char> v){
    pair<char,int> ans;
    ans.first=v[0];
    ans.second=1;
    for(int i=1;i<v.size();i++){
        if(ans.first!=v[i]){
            if(ans.second!=0){
                ans.second--;
            }else{
                ans.first=v[i];
                ans.second++;
            }
        }else ans.second++;
    }
    return ans.first;
}
```


时间复杂度：O(n)
空间复杂度：O(1)

参考文章：https://blog.csdn.net/qq_44443986/article/details/112366223

练习题：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/