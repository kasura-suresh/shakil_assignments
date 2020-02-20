/* programe to find length of array 
   date: 20 feb,2020    author: Md Shakil Ansari*/


#include <stdio.h>
int main()
{
    int length,n,i;
    printf("\n enter the size of the aray:");
    scanf("%d",&n);
    int arr[n];
    printf("\n enter the elements of array :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        }
    length=sizeof(arr)/sizeof(arr[0]);
    printf("\n the length of the array is %d",length);
    return 0;
}

