#include "stdio.h"
#include "string.h"

int len = 9;

/**
 * @brief 打印数组，采用递归的方式打印
 * 
 * @param arr 待打印数组
 * @param length 剩余未打印数组长度
 * @return * void 
 */
void Show(int arr[], int length)
{
    if (length >= 2)
    {
        printf("%d\t", arr[len-length+1]);
        Show(arr, length - 1);
    }
}

/**
 * @brief 普通的顺序查找
 *
 * @param arr 待查找数组
 * @param key 查找元素
 * @return * int 返回下标
 */
int Search_Seq(int arr[],int key){
    int i;
    for (i = len; i >= 1;i--){
        if(arr[i] == key){
            return i;
        }
    }
    return 0;
}

/**
 * @brief 设置了哨兵的查找。数组第一个元素为哨兵，从后往前找
 * 
 * @param arr 待查找数组
 * @param key 查找元素
 * @return * int 返回下标
 */
int Search_Seq_S(int arr[],int key){
    int i;
    arr[0] = key;
    for (i = len; arr[i] != key; i--)
        ;
    return i;
}

int Search_Bin(int arr[],int key){
    int low = 1;
    int high = len;
    int mid;
    while(low<=high){
        mid = (low + high) / 2;
        if(arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return 0;
}

/**
 * @brief 直接插入排序
 * 
 * @param arr 待排序数组
 * @return * void 
 */
void InsertSort(int arr[]){
    int i;
    for (i = 2; i < len;i++)
    {
        Show(arr, len);
        printf("\n");
        if (arr[i]<arr[i-1])
        {
            arr[0] = arr[i];
            arr[i] = arr[i - 1];
            int j;
            for (j = i - 2; arr[0] < arr[j];j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
}

void BubbleSort(int arr[]){
    int i = len-1;
    int j;
    int tmp;
    for (; i >= 0; i--)
    {
        Show(arr, len);
        printf("\n");
        // 注意数组下标不要越界，最大只能到 i-1的位置。因为判断出用到了 j+1
        for (j=1;j<i;j++){
            if(arr[j]>arr[j+1]){
                // printf("%d--%d--%d\n",j,arr[j],arr[j+1]);
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

/**
 * @brief 快速排序
 * 
 * @param arr 待排序数组
 * @param low 表的左边
 * @param high 表的右边
 * @return * void 
 */
void QuickSort(int arr[],int low,int high){
    // 递归的时候，如果low>=high，就不用继续递归下去
    if(low>=high){
        return;
    }
    int i = low;
    int j = high;
    int key = arr[low];
    Show(arr, len);
    printf("\n");
    while (i < j)
    {
        // j--的时候，仍然要保证 i<j
        while (i<j&&arr[j]>key)
        {
            j--;
        }
        arr[i] = arr[j];
        // 同理，i++的时候，仍然要保证 i<j
        while (i<j&&arr[i]<key)
        {
            i++;
        }
        arr[j] = arr[i];
        // i++;
    }
    arr[i] = key;
    Show(arr, len);
    printf("\n");
    // 一次排序完成后，数组就分为左右两部分，对这两部分继续使用快速排序
    QuickSort(arr, i+1, high);
    QuickSort(arr, low, i-1);
}

void main(){
    int arr[] = {0,99,33,55,66,22,77,44,88};
    // int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    // int re = Search_Seq(arr, 55);
    // printf("顺序查找：%d\n",re);

    // re = Search_Seq_S(arr, 55);
    // printf("哨兵查找：%d\n",re);

    printf("\n");

    // re = Search_Bin(arr,50);
    // printf("二分查找：%d\n",re);

    // printf("直接插入排序：\n");
    // InsertSort(arr);

    // printf("冒泡排序：\n");
    // BubbleSort(arr);

    printf("快速排序：\n");
    QuickSort(arr, 1,len-1);
    Show(arr, len);
}
