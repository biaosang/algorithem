#include<stdio.h>

void merge(int right, int mid, int left, int arr[])
{
    int r = right;
    int l = mid;
    int temp[left + 1 - right];
    int i = 0;
    while(r < mid && l <= left)
    {
        if(arr[r] > arr[l])
        {
            temp[i] = arr[l];
            l++;
        }
        else
        {
            temp[i] = arr[r];
            r++;
        }
        i++;
    }


    for(int j = r; j < mid; j++)
    {
        temp[i++] = arr[j];
    }
    for(int j = l; j <= left; j++)
    {
        temp[i++] = arr[j];
    }

    int j = 0;
    for(int k = right; k <= left; k++)
    {
        arr[k] = temp[j++];
    }

}

void merge_sort(int right,int left,int arr[])
{
    if(left <= right)
        return;

    int mid = (left - right + 1) / 2;
    merge_sort(right, mid + right - 1, arr);
    merge_sort(mid + right, left, arr);
    merge(right, mid + right, left ,arr);

}

int main(int arg, char* args[])
{
    int len;
    while(printf("input array length->n,(breaking when length < 1):") && scanf("%d",&len) && len > 0)
    {
        printf("input array,split by blank:");
        int arr[len];
        for(int i = 0; i < len; i++)
        {
            scanf("%d",&arr[i]);
        }

        merge_sort(0,len - 1,arr);
        printf("result:");
        for(int i = 0; i < len; i++)
        {
            if(i == len - 1)
                printf("%d",arr[i]);
            else 
                printf("%d,",arr[i]);
        }
        printf("\n");
    }

    return 0;
}