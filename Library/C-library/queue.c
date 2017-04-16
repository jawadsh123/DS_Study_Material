#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX =  6   //Queue size
int intArray[MAX];  //Queue
int front = 0;  //front position of queue
int rear = -1;  //rear position of queue
int itemCount = 0;

//check the element in the front of queue.
int peek() {
   return intArray[front];
}

//checks if queue is empty.
bool isEmpty() {
   return itemCount == 0;
}

//checks if queue is full.
bool isFull() {
   return itemCount == MAX;
}

//returns no of items in the queue
int size() {
   return itemCount;
}  

//insert one element from rear.
void insert(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

//remove one element from front.
int remove() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}

int main() {
    //your code goes here.
   
    //display queue item.
    while(!isEmpty()) {
        int n = removeData();           
        printf("%d ",n);
    }   
}