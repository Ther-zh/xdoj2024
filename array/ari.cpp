#include <stdio.h>
void exchange(int *arr, int a, int b)
{
    int tem = arr[a];
    arr[a] = arr[b];
    arr[b] = tem;
}

void sort(int *arr, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int i = begin;
    for (int j = i + 1; j <= end; j++)
    {
        if (arr[j] < arr[i])
        {
            if (j == i + 1)
            {
                exchange(arr, i, j);
            }
            else
            {
                exchange(arr, i + 1, j);
                exchange(arr, i, i + 1);
            }
            i++;
        }
    }
    sort(arr, begin, i - 1);
    sort(arr, i + 1, end);
}
int main()
{
    int arr[100] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n - 1);
    int gap = arr[1] - arr[0];
    int result = 1;
    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != gap)
        {
            result = 0;
            break;
        }
    }
    if (result == 1)
    {
        printf("%d", gap);
    }
    else
    {
        printf("no");
    }
}