#include <stdio.h>

int main() 
{
    
    int i,n, D, T, temp,k=0;
    scanf("%d\n",&T);
    while(k!=T)
    {
    scanf("%d %d\n",&n,&D);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
        for(i=D;i!=D-1;i++)
        {
            if(i==n)
            {
            i=0;
            }
            printf("%d ",arr[i]);
        }
    printf("%d\n",arr[D-1]);
    k++;
    }
	return 0;
}