/*
8.Program to convert decimal to binary and vice versa
9. Program to implement switch case statement. 
10. Program to generate the Fibonacci sequence. 
*/

/*
8
*/
#include<stdio.h> 

int main(){  
int a[10],n,i,temp; 

printf("Enter a no \n");    
scanf("%d",&n); 
temp = n;

for(i=0;n>0;i++){    
a[i]=temp%2;    
temp= temp/2;    
}    

printf("Binary of %d is",n);    

for(i=i-1;i>=0;i--){    
printf("%d",a[i]);    
}
     
}