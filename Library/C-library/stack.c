#include <stdio.h>

int MAXSIZE = 8;     //Stack size  
int stack[8];     //Stack
int top = -1;            //Stack top


//checks if stack is empty.
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   

//checks if stack is full.
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

//checks element on stack top.
int peek() {
   return stack[top];
}

//removes one element from stack.
int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

//insert on element on top of stack.
int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
   //your code goes here.
   
   return 0;
}