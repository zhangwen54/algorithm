#include <vector>


void merge(std::vector<int> &v, int left, int right, int mid)
{
    std::vector<int> v1(mid - left + 1);
    std::vector<int> v2(right - mid + 2); //mid-1是v1的终点，末尾增加一个哨兵的空间，所以+1；mid是v2的起点，末尾增加一个哨兵的空间，所以+2
    for (int i = 0, j = left; j < mid; i++, j++)
        v1[i] = v[j];
    v1[mid - left] = INT_MAX;
    for (int i = 0, j = mid; j <= right; i++, j++)
        v2[i] = v[j];
    v2[right - mid + 1] = INT_MAX;
    int i1 = 0;
    int i2 = 0;
    for (int i = left; i <=right; i++)
    {
        if (v1[i1] < v2[i2])
        {
            v[i] = v1[i1];
            i1++;
        }
        else
        {
            v[i] = v2[i2];
            i2++;
        }
    }

}

void mergeSort(std::vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right + 1) / 2; //奇数为中，偶数偏右
        mergeSort(v, left, mid - 1);      //因为mid在数组长度偶数个时定位偏右，所以排序时左侧范围要在mid偏左
        mergeSort(v, mid, right);
        merge(v, left, right, mid); //合并
    }
}

