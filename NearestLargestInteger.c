//Nearest larger element
#include<stdio.h>
#include <stdlib.h>
int top=-1,N,a;
int stack[1000];
void push(int number){
    top++;
    stack[top]=number;
}
int pop(){
    a=stack[top];
    top--;
    return a;
}
int main()
{
    scanf("%d",&N);
    int array[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    push(array[N-1]);
    for(int i=N-2;i>=0;i--){
        if(array[i]>array[i+1]){
            if(array[i]>stack[top]){
                push(array[i]);
            }
            else{
                push(stack[top]);
            }
        }
        else{
            if(array[i]<stack[top]){
                push(array[i+1]);
            }
            else{
                push(stack[top]);
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%d - %d\n",array[i],pop());
    }
}
