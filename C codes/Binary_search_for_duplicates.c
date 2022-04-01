#include <stdio.h>
#include <stdlib.h>
int binarysearch(int *a,int left,int right,int target,int *index)
{
    int mid;
    while(left <= right)
    {
        mid = (right + left)/2;
        if (target == a[mid]) return mid;
        else if(target < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
int max(int *a,int limit)
{
    int i,mini = a[0];
    for(i = 1; i < limit; i++)
    {
        if(mini < a[i]) mini = a[i];
    }
    return mini;
}
int main()
{
    int *arr = (int*)malloc(10*sizeof(int));
    int *index = (int*)malloc((10) * sizeof(int));
    int c[10] = {1,4,4,4,4,4,97,101,109,302};
    int *repeat = (int*)malloc(sizeof(int));
    int target;
    for(target = 0; target < 10 ; target++) 
    {
        arr[target] = c[target];
        index[target] = target;
    }
    printf("Enter desired number ");
    scanf("%d",&target);
    int ind,use = 0;
    do
    {
        ind = binarysearch(arr,0,9 - use,target,index);
        if (ind != -1)
        {
            repeat = (int*)realloc(repeat,(use + 2)*sizeof(int));
            *(repeat+use) = index[ind];
            use ++;
            printf("\n%d at index %d",target,index[ind]);
            int i;
            for(i = ind;i < 10 - use ;i++)
            {
                arr[i] = arr[i + 1];
                index[i] = index[i + 1];
            }
        }
        
    }while(ind != -1);
    if (use == 0) printf("\nDesired number is not present ");
    else printf("\nRight most index is %d",max(repeat,use));
    free(repeat);
    free(arr);
    free(index);
    return 0;
}




