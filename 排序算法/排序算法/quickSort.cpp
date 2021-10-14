#include <vector>

int partition(std::vector<int> &v, int left, int right)
{
    int temp = v[right];
    int midleft = left - 1;
    for (int i = left; i < right; i++)
    {
        if (v[right] >= v[i])
        {
            midleft++;
            int tmp = v[midleft];
            v[midleft] = v[i];
            v[i] = tmp;
        }
    }
    int tmp = v[midleft + 1];
    v[midleft + 1] = v[right];
    v[right] = tmp;
    return midleft + 1;
}

void quickSort(std::vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int mid = partition(v, left, right);
        quickSort(v, left, mid - 1);
        quickSort(v, mid + 1, right);
    }
}
