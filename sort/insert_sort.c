#include<stdio.h>

void insert_sort(int len,int *arr)
{
    for(int i = 1; i < len; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            int temp = arr[j];
            arr[j] = arr[j -1];
            arr[j - 1] = temp;
            j--;
        }

    }
}

int main(int arg,char *args[])
{
    int arr[] = {2,4,1,6,4,-100,8,5,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    insert_sort(len,arr);
    for(int i = 0; i < len; ++i)
    {
        if(i < len - 1)
            printf("%d,",arr[i]);
        else
            printf("%d\n",arr[i]);
    }
    return 0;
}


