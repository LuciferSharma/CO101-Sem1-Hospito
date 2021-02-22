#include<stdio.h>

int main(){ 
    int n,i,s,k,temp;
    printf("Input lenght of array \n" );
    scanf("%d",&n);
    int array[n];
    int start = 0, end =n-1, mid;


    for(i=0;i<n;i++){
        printf("Enter %d th element of array \n", i+1);
        scanf("%d", &array[i]);
    }

    //sorting the array

    for(i=0;i<n-1;i++){
        if( array[i]>array[i+1]){
            temp = array[i+1];
            array[i+1] = array[i];
            array[i] = temp;
        }
    }

    printf("Enter integer to search \n");
    scanf("%d",&s);

    printf("Input 1 for Linear Search \nInput 2 for Binary Search \n");
    scanf("%d",&k);

    switch (k)
    {
    case 1:
        for(i=0;i<n;i++){
            if (s==array[i]){
                printf("The integer %d ia at %d th place of the array",s,i+1);
            }
        }
        break;

    case 2:
    
        for(i=0;i<n;i++){
            mid = end-start;
            if(s== array[mid]){
                break;
            }
            if(s > array[mid]){
             start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        printf("The integer %d ia at %d th place of the array",s,mid);
        break;
    
    default:
    printf("Enter a valit option");
        break;
    }

}