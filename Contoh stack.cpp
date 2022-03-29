#include <iostream>

struct Node {
	int val;
	Node *next, *prev;
};
struct Stack {
	int value;
	Stack *link;
};
Stack *create(int val) {
	Stack *newStack = new Stack;
	newStack->value = val;
	newStack->link = nullptr; 
	return newStack;
}
//fungsi menambahkan stack
void push(Stack **top, int val) {
	if((*top) == nullptr) {
		(*top) = create(val);
		std::cout << "Stack Added!" << std::endl;
	}else{
		Stack *newStack = create(val);
		newStack->link = (*top);
		(*top) = newStack;
		std::cout << "Top Added!" << std::endl;
	}
}
//fungsi menghapus satu stack
void pop(Stack **top) {
	if((*top) == nullptr) std::cout << "Nothing to delete here!" << std::endl;
	else{
		if((*top)->link == nullptr) {
			delete (*top);
			(*top) = nullptr;
			std::cout << "Stack cleared!" << std::endl;
		}else{
			Stack *del = (*top);
			(*top) = (*top)->link;
			del->link = nullptr;
			delete del;
			std::cout << "Done!" << std::endl;
		}
	}
}
//Fungsi menghapus semua stack
void init(Stack **top) {
	if((*top == nullptr)) {
		std::cout << "Nothing to init" << std::endl;
	}else if((*top)->link == nullptr){
		delete(*top); (*top) = nullptr;
	}else {
		Stack *del, *cur = (*top);
		do{
			// Config
			del = cur;
			cur = cur->link;
			
			// Untied
			del->link = nullptr;
			
			//	Trashed
			delete del;		
		}while(cur != nullptr); 
		(*top) = nullptr;
	}
	std::cout << "Initialized" << std::endl;
}
// fungsi mencetak stack
void printStack(Stack **top) {
	if((*top) == nullptr){
		std::cout << "No Stack Found!" << std::endl;	
	}else{
		Stack *cur = (*top);
		while(cur != nullptr) {
			std::cout << cur->value << std::endl;
			cur = cur->link;
		}	
	}
}
int main() {
	Stack *top = nullptr;

	printStack(&top);
	push(&top, 10);
	push(&top, 9);
	push(&top, 8);
	push(&top, 7);
	push(&top, 6);
	printStack(&top);
	
	pop(&top);
	pop(&top);
	pop(&top);
	printStack(&top);	
	init(&top);
	printStack(&top);
	
	return 0;
}
