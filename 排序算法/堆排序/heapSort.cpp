/*大顶堆*/
#include <vector>

//堆的父子节点寻址
int PARENT(int i)
{
    int ii = i + 1;
    return ii / 2 - 1;
}
int LEFT(int i)
{
    int ii = i + 1;
    return 2 * ii - 1;
}
int RIGHT(int i)
{
    int ii = i + 1;
    return 2 * ii + 1 - 1;
}

//维护堆，在i点开始下沉
void maxHeapify(std::vector<int> &v, int i, int heapSize)
{
    int ltree = LEFT(i);
    int rtree = RIGHT(i);
    int largest = i;
    if (ltree < heapSize && v[ltree] > v[largest])
    {
        largest = ltree;
    }
    if (rtree < heapSize && v[rtree] > v[largest])
    {
        largest = rtree;
    }
    if (largest != i)
    {
        int tmp = v[i];
        v[i] = v[largest];
        v[largest] = tmp;
        maxHeapify(v, largest, heapSize);
    }
}

//建堆
void buildMaxHeap(std::vector<int> &v, int heapSize)
{
    int length = v.size();
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        maxHeapify(v, i, heapSize);
    }
}

//堆排序
void heapSort(std::vector<int> &v)
{
    buildMaxHeap(v, v.size());
    for (int i = v.size() - 1; i > 0; i--)
    {
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        maxHeapify(v, 0, i);
    }
}

