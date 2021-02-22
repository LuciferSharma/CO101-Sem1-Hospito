#include<stdio.h>
int main(){
    int i;
    printf("enter n - ");
    scanf("%d",&i);
printf("factorial of %d is %d",i,fac(i));
    return 0;
}

int fac(int num){
    if (num==0 || num==1){
    return 1;
}
else{
    return (num*fac(num-1));
}
}