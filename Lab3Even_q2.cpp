/*
Implement Circular Linked List using C++. Make sure the following functions are implemented: 
1. insert(int data) - Adds a new element to the end of the linked list. 
2. insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
3. delete() - Deletes the element at the end of the list. 
4. deleteAt(int pos) - Deletes the element(or node) at the position pos)
5. countItems() - Returns the number of items in the linked list. 
6. display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. 
*/

#include<iostream>
using namespace std;

//define node
class Node{
	public:
	//data
	int data;
	//pointer to the next
	Node* next;
	//default pointer
	Node(int data){
		this->data=data;
		next=NULL;
	}
};
//define a circular linklist
class CSLL{
	
	//circular chain of nodes
	public:
	//head
	Node* head;
	//default constructor for head
	CSLL(){
		head=NULL;
	}
	
	//insert
	void insert(int data){
		//Create a new node
        Node* temp = new Node(data);
        //Check if list is empty
        if(head == NULL){
            head = temp;
        }  
        //If not empty 
        else{ 
            Node* current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
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
			if(pos!=1){
				temp->next=current->next;
				current->next=temp;
			}
			//for 1st position 
			if(pos==1){
					for(int i=1;i<check;i++){
					current=current->next;
				}
				temp->next=current->next;
				current->next=temp;
				head=temp;
			} 
		}
		//if not
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//delete
	void delet(){
		//reach before last
		Node* current = head;
		while(current->next->next!=head){
			current=current->next;
		}
		//store in temp
		Node* temp=current->next; 
		//break
		current->next=head;
		//delete temp
		delete temp;
	}
	//deleteAt
	void deleteAt(int pos){
		//if pos exists
		int check = countItems();
		if(pos<=check){
			//reach before the pos
			Node* current = head;
			if(pos!=1){
				for(int i=1;i<pos-1;i++){
					current=current->next;
				}
			}
			//for head
			else if(pos==1){
				for(int i=1;i<check;i++){
					current=current->next;
				}
				//update head
				head=head->next;
			}
			//store next into temp
			Node* temp=current->next;
			//join current next to temp next
			current->next = temp->next;
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
			while(current->next!=head){
				count++;
				current=current->next;
			}
			return count;
		}
	}
	//display
	void display(){
        Node* current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        // Stopping at head
        while(current->next != head){ 
            cout << current->data << "->";
            current = current->next;
        }
        // Printing the last element
        cout << current->data ;
        cout << endl;
        cout << "Number of nodes = " << countItems() << endl;
    }

};

int main(){
	CSLL l1;
	
	l1.insert(1);
	l1.insert(7);
	l1.insert(2);
	l1.insert(3);
	l1.insert(5);
	l1.display();
	
	l1.insertAt(1,0);
	l1.display();
	l1.insertAt(6,4);
	l1.display();
	
	l1.deleteAt(1);
	l1.display();
	l1.deleteAt(2);
	l1.display();
	
	l1.delet();
	l1.display();
	
	return 0;
}
