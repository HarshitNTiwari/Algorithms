#include <iostream> 

#define MAX 100  //maximum size of the stack

// Creating a Stack class
class StackUsingArray{
public:
	int top;         //to track the index of the topmost key
	int stack[MAX];  //array to store stack elements

	// constructor
	StackUsingArray(){
		top = -1;   //initializing the index of the topmost key as -1, since there are no keys yet
	}

	~StackUsingArray();
	
	// Member functions for various Stack operations:
	void push(int key);
	void pop();
	int peek();
	bool isEmpty();
};

// function to push key in the stack : O(1)
void StackUsingArray::push(int key){
	// if stack is full
	if (top >= (MAX-1)){
		std::cout<<"Error: Stack Overflow"<<std::endl;
		return;
	}
	top++;
	stack[top] = val;
	return;
}

// function to remove top key from the stack : O(1)
void StackUsingArray::pop(){
	// if stack is empty
	if(top < 0){
		std::cout<<"Error: Stack Underflow"<<std::endl;
		return;
	}
	top--;
	return;
}

// function to get top key from the stack : O(1)
int StackUsingArray::peek(){
	// if stack is empty
	if(top < 0){
		std::cout<<"Error: Stack is empty"<<std::endl;
		return -1;
	}
	return stack[top];
}

// function to check if the stack is empty : O(1)
bool StackUsingArray::isEmpty(){
	return top < 0;
}

int main(){
	// creating an object od StackUsingArray class
	StackUsingArray st;
	
	st.push(10);
	st.push(20);
	int top = st.peek();
	st.pop();

	if(!st.isEmpty())
		std::cout<<st.peek()<<std::endl;

	return 0;
}