#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        // 在每次遍历中，比较相邻元素并交换，把最大元素移动到数组的末尾
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换arr[j]和arr[j + 1]的值
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 快速排序函数
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // 找到基准元素的位置，并对数组进行分割
        int pivotIndex = partition(arr, low, high);

        // 递归地对基准元素的左侧和右侧子数组应用快速排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// 快速排序辅助函数，用于找到基准元素的位置并对数组进行分割
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // 选择数组的最后一个元素作为基准元素
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // 交换arr[i]和arr[j]的值
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 将基准元素放置在正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // 返回基准元素的位置
}

// 测试排序函数
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("原数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr, n);

    printf("排序后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
