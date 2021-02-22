#include<stdio.h>

int fac(int num){
    if (num==0 || num==1){
    return 1;
}
else{
    return (num*fac(num-1));
}
}
int main(){
    int i;
    printf("enter n - ");
    scanf("%d",&i);
printf("factorial of %d is %d",i,fac(i));
    return 0;
}
