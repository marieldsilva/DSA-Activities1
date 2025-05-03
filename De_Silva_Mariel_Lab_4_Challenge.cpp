// circular queue po try lang, hindi ko po alam pano priority.. yung simple queue po i-upload ko nalang separately

#include <iostream>
using namespace std;

string karaoke_queue[100];

int front = -1;
int rear = -1;
int max_queue = 10;

bool isFull(){
    return (front == (rear + 1) % max_queue);
    
}

bool isEmpty(){
    return (front == -1);
}

string enqueue (string song){
    if (isFull()){
        return "The queue is full. Try again later";
    }
    if (isEmpty()){
        front = 0;
    }
    rear = (rear + 1) % max_queue;
    karaoke_queue [rear] = song;
    return "A new song has been added in the queue";
}

string dequeue(){
    if (isEmpty()){
        cout << "There is no song in the queue. Try adding first\n" << endl;
    }
    string karaoke_queues = karaoke_queue [front];
    
    if (front == rear){
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max_queue;
    }
    
    return karaoke_queues;
}

int main(){
    
    cout << enqueue ("Bring Me To Life by Evanescence") << endl;
    cout << enqueue ("Labis Na Nasaktan by Jennilyn Yabu") << endl;
    cout << enqueue ("Kahit Ayaw Mo Na by This Band") << endl;
    
    cout << dequeue () << endl;
    cout << dequeue () << endl;
    
    
    return 0;
}
