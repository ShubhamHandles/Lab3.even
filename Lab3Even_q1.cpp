/*
Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
1. insert(int data) - Adds a new element to the end of the linked list. 
2. insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
3. delete() - Deletes the element at the end of the list. 
4. deleteAt(int pos) - Deletes the element(or node) at the position pos)
5. countItems() - Returns the number of items in the linked list. 
6. display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/

#include<iostream>
using namespace std;

//define node
class Node{
	public:
	//data
	int data;
	//pointers
	Node* next;
	Node* prev;
	//constructor for the default pointers
	Node(int value){
		next=NULL;
		prev=NULL;
		data=value;
	}	
};

class DLL{
	//chain of nodes
	public:
	//head and tail
	Node* head;
	Node* tail;
	//constructor for default head and tail
	DLL(){
		head=NULL; tail=NULL;
	}
	//insert
	void insert(int data){
		//Node with value
		Node* temp = new Node(data);
		//update head and tail
		//for first node
		if(head==NULL){
			head=temp;
		}
		//for others
		else{
			tail->next=temp;
			temp->prev=tail;
		}
		tail=temp;
	}
	//insertAt
	void insertAt(int pos, int data){
		//if pos exists
		int check=countItems();
		if(pos<=check+1){
			//reach one place before the pos
			Node* current=head;
			for(int i=1;i<pos-1;i++){
				current=current->next;
			}
			//create the node
			Node* temp = new Node(data);
			//join the node to successor
			temp->next=current->next;
			if(current!=tail){
				current->next->prev=temp;
			}
			//join predecessor
			temp->prev=current;
			current->next=temp;
			//update head and tail
			if(pos==check+1) tail=temp;
			if(pos==1) head=temp; 
		}
		//if not
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//delete
	void delet(){
		//store tail in temp
		Node* temp=tail;
		//cout << tail->data << endl;
		//reach before tail
		Node* current = head;
		while(current->next!=tail){
			current=current->next;
		}
		//break tail
		current->next=NULL;
		//update tail
		tail= current;
		//delete tail
		delete temp;
	}
	//deleteAt
	void deleteAt(int pos){
		//if pos exists
		int check = countItems();
		if(pos<=check){
			//reach before the pos
			Node* current = head;
			for(int i=1;i<pos-1;i++){
				current=current->next;
			}
			//store next into temp
			Node* temp=current->next;
			if(pos!=1 and pos!=check){
				//join current next to temp next
				current->next = temp->next;
				//join temp next prev to current
				if(current->next!=tail){
					temp->next->prev = current;
				}
			}
			//update tail and head
			else if(pos==check) {
				tail=current; 
				tail->next=NULL;
			}
			else if(pos==1) head=temp->next;
			//delete temp
			delete temp;
		}
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//countItems
	int countItems(){
		int count=1;
		Node* current=head;
		if(head==NULL){
			return 0;
		}
		else{
			while(current!=tail){
				count++;
				current=current->next;
			}
			return count;
		}
	}
	//display
	void display(){
		displayR(head); //print from head
		cout << endl;
		cout << "Number of nodes = " << countItems() << endl;
	}
	void displayR(Node* current){
		if(current!=NULL){
			cout << current->data << "->";
			displayR(current->next); //next node
		}	
	}
	void revDisplay(){
		revDisplay2(head);
		cout << endl;
		cout << "Number of nodes = " << countItems() << endl;
	}
	void revDisplay2(Node* current){
		if(current!=NULL){
			revDisplay2(current->next);
			cout << current->data << "->";
		}
	}
};

int main(){
	DLL l1;

	l1.insert(1);
	l1.insert(7);
	l1.insert(2);
	l1.insert(3);
	l1.insert(5);
	l1.display();
	
	l1.insertAt(6,6);
	l1.display();
	l1.insertAt(5,4);
	l1.display();
	
	l1.deleteAt(2);
	l1.display();
	l1.deleteAt(6);
	l1.display();
	
	l1.delet();
	
	l1.display();
	l1.revDisplay();
	
	return 0;
}
