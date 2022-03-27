#include <iostream>

struct Angka {
	int value;
	Angka *next;
	Angka *prev;
}*head, *tail, *cur, *del, *newNode, *temp;

//	Buat
void createDLL(int val) {
	head = new Angka();
	head->value = val;
	head->next = NULL;
	head->prev = NULL;
	tail = head;
}
//	Tambah Awal
void addFirst(int val) {
	newNode = new Angka();
	newNode->value = val;
	newNode->prev = NULL;
	newNode->next = head;
	head = newNode;
}
//	Tambah di Tengah(Pada index ke N)
void addMid(int val, int index) {
	newNode = new Angka();
	newNode->value = val;
	cur = head;
	int count = 1;
	while(count < index-1) {
		cur = cur->next;
		count++;
	}
	newNode->prev = cur;
	newNode->next = cur->next;
	cur->next = newNode;
	
	cur = newNode->next;
	cur->prev = newNode;
}
//	Tambah di Akhir
void addLast(int val) {
	newNode = new Angka();
	newNode->value = val;
	newNode->prev = tail;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}
//	Hapus Awal
void removeFirst() {
	del = head;
	head = del->next;
	head->prev = NULL;
	delete del;
}
//	Hapus di tengah (index ke N)
void removeMid(int index) {
	cur = head;
	int count = 1;
	while(count < index) {
		cur = cur->next;
		count++;
	}
	del = cur;
	cur = cur->prev;
	temp = del->next;
	temp->prev = cur;
	cur->next = temp;
	
	delete del;
}
//	Hapus di Akhir
void removeLast() {
	del = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete del;
}
//Print DLL
void printDLL() {
	cur = head;
	int count = 1;
	while(cur != NULL) {
		std::cout << "value" << count << " : " << cur->value << std::endl;
		cur = cur->next;
		count++;
	}
	std::cout << "\n=====================================\n\n";
}
int main() {
	
	createDLL(1);
	for(int i = 2; i < 6; i++) {
		addLast(i);
	}
	printDLL();
	
	
	addMid(555, 3);
	printDLL();
	
	removeMid(3);
	printDLL();
	

	return 0;
}
