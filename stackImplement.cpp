#include <iostream>
using namespace std;
#define max 100
int stack[max];
int top = -1;


void push(int n){
    if(top == max - 1){
        cout << "Stack is full." ;        
    }
    else{
        stack[++top] = n;
    }
}


void peek(){
    if(top == -1){
        cout << "Stack is empty.";
    }
    else{
        cout << stack[top];
    }
}


void pop(){
    if(top == -1){
        cout << "Stack is empty.";
    }
    else{
        cout << stack[top--];
    }
}
void isempty(){
    if(top == -1){
        cout << "\nStack is empty" << endl;
    }
    else{
        cout << "\nStack is not empty" << endl;
    }
}


int main(){
    push(50);
    push(35);
    push(39);
    push(45);
    cout << "\nThe element on the top of the stack is: ";
    peek();
    cout << "\nThe popped  element is: ";
    pop();
    cout << "\nThe top element after popping is: ";
    peek();
    isempty();
    return 0;
}