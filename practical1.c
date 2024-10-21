#include<stdio.h>
#define MAX 100
int arr[MAX];
int top=-1;
int push(int data){
    if(top==MAX-1){
        return -1;
    }
    top++;
    arr[top]=data;
    return 1;
}
int pull(){
    if(top==-1){
        return -1;
    }
    int data=arr[top];
    top--;
    return data;
}
int peek(){
    if(top==-1){
        return -1;
    }
    return arr[top];;
}
void display(){
    int i;
    if(top==-1){
        printf("Array is empty");
    }
    else{
        for(i=0;i<=top;i++){
            printf("%d\t",arr[i]);
        }
    }
        printf("\n");
}
void main(){
    push(4);
    display();
    push(5);
    display();
    push(6);
    display();
    pull();
    display();
    printf("%d",peek());
}
