#include <iostream>
using namespace std;

//structure
typedef struct Node{
	string songName;
	Node *link;
}Node;

//create new node
Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

//traverse
void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName << "->" << endl;
        if(temp->link == NULL){
            cout << "NULL" << endl;
        }
        
        temp = temp->link;
    }
}

//insert at the end
Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end" << endl;
    return head;
}

//insert at the beginning
Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning" << endl;
    return head;
}

//insert after a given Node
string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "A new node has been added after " + after + "\n";
}

//delete at the end
string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    
    if(head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return "A node has been deleted at the end \n";
}

//delete from beginning
Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty" << endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    cout << "A node has been deleted from the beginning" << endl;
    return head;
}

//delete from given node
Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty." << endl;
        return NULL;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + " has been deleted." << endl;
        return head;
    }
    
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;
    
    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist." << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    
    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted." << endl;
    return head;
}

int main(){

    Node *head = createNode("Sanctuary by Joji");
    traverse(head);
	cout << endl;
    
    head = insertAtEnd("Ain't It Fun by Paramore", head);
    traverse(head);
	cout << endl;
    
    head = insertAtEnd("Starkiller by Bear Ghost", head);
    traverse(head);
	cout << endl;
    
    head = insertAtEnd("Smells Like Teen Spirit by Nirvana", head);
    traverse(head);
	cout << endl;
    
    head = insertAtBeginning("FOR YOUR LOVE by Maneskin", head);
    traverse(head);
	cout << endl;
    
    head = insertAtBeginning("OWN MY MIND by Maneskin", head);
    traverse(head);
	cout << endl;
    
    head = insertAtBeginning("New Song by Maneskin", head);
    traverse(head);
	cout << endl;
    
    head = insertAtBeginning("Snap Out Of It by Arctic Monkeys", head);
    traverse(head);
	cout << endl;
	
    cout << insertAfter("FOR YOUR LOVE by Maneskin", "Pasilyo by SunKissed Lola", head);
    traverse(head);
	cout << endl;
	
    cout << insertAfter("OWN MY MIND by Maneskin", "Walang Kapalit by Rey Valera", head);
    traverse(head);
	cout << endl;
	
    cout << insertAfter("New Song by Maneskin", "Bituing Walang Ningning by Sharon Cuneta", head) << endl;
	traverse(head);
	
	cout << endl;
	cout << deleteAtEnd(head);
	traverse(head);
	
	cout << endl;
	head = deleteFromBeginning(head);
	traverse(head);
	
	cout << endl;
	head = deleteFromGivenNode("Sanctuary by Joji", head);
	traverse(head);

return 0;
}
