#include <stdio.h>
void swap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void swim(int a[],int n){
    int j;
    while(n > 0){
        j = (n-1)/2;
        if(a[n]>a[j]) swap(&a[n],&a[j]);
        else break;
        n = j;
    }
}
void sink(int a[],int n,int length){
    int j = n,k;
    while(j*2<length){
        k = j;
        j = j*2 + 1;
        if(j<length && j+1<length){
            if(a[j]<a[j+1]) j++;
        }
        if(a[k]>a[j]) break;
        if(j<length) swap(&a[k],&a[j]);
        else break;
    }
}
void print(int a[],int n){
    printf("\n");
    for(int i = 0;i<n;i++) printf("%d ",a[i]);
}
void Heapify(int a[],int length){
    for(int i = length -1 ;i>0;i--) swim(a,i);
}
void Heap_Sort(int a[],int length){
    Heapify(a,length);
    print(a,length);
    int i = length - 1;
    while(i>0){
        swap(&a[0],&a[i]);
        sink(a,0,i);
        i--;
    }
}
int main()
{
   int a[7];
   for(int i = 0;i<7;i++) scanf("%d",&a[i]);
   Heap_Sort(a,7);
   print(a,7);
   return 0;
}

