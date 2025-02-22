#include <iostream>

using namespace std;

int myArray[30];
int numElem = 0;
int maxElem = 20;

void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i = 0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(myArray[j] > myArray[j+1]){
                swap(myArray[j], myArray[j+1]);
                swapped = true;
            }
        }
        
        if(swapped == false){
            break;
        }
    }
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + ((highest - 1) /2);
        
        if(myArray[middle] == num){
            return middle;
        }
        
        if(myArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
    return -1;
}

void traverseArray(){
    cout << "Showing elements in my array \n";
    for (int i = 0; i< numElem; i++) {
        cout << to_string(myArray[i]) + " | ";
        }
    cout << "\n";
    }
    
string insertAtTheEnd (int num){
    if(numElem != maxElem){
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtTheBeginning (int num){
    if(numElem != maxElem){
        for(int i = numElem; i >= 0; i--){
            myArray[i+1] = myArray[i];
        }
        
        myArray[0] = num;
        numElem++;
        return "An Element is successfully inserted at the beginning! \n";
    }
    
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtTheGivenPosition(int num, int ElementAfter){
    if(numElem != maxElem){
        int position = binarySearch(ElementAfter, 0, numElem);
        
       /*for(int i = 0; i <= maxElem; i++){
            if(myArray[i] == ElementAfter){
                position = i;
                break;
            }
        }*/
        
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray[i];
        }
        myArray[position + 1] = num;
        numElem++;
        return "An element is successfully inserted at the specified location! \n";
    }
    
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < myArray[i]){
                position = 1;
                break;
            }
        }
        
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray[i];
        }
        
        myArray[position] = num;
        numElem++;
        return "An element is successfully inserted at a sorted array! \n";
    }
    
    return "The array is full. PLease remove elements before inserting new one. \n";
}

string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been deleted from the end!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromTheBeginning(){
    if(numElem != 0){
        for(int i = 0; i <= numElem; i++ ){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return "An element has been deleted from the beginning!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromGivenElement(int element){
    if(numElem != 0){
        int index = binarySearch(element, 0, numElem);

        /*for(int i = 0; i <= numElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        }*/
        
        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return to_string(element) + " has been deleted!";
    }
    return "The array is underflow! Delete is not possible";
}

int main(){
    
    cout << insertAtTheBeginning(3);
    cout << insertAtTheEnd(7);
    cout << insertAtTheEnd(9);
    cout << insertAtTheBeginning(20);
    cout << insertAtTheGivenPosition(37, 7);
    cout << insertAtTheBeginning(256);
    cout << insertAtTheGivenPosition(128, 9);
    cout << insertAtTheBeginning(19);
    
    traverseArray();
    
    cout << insertAtSortedArray(3);
    cout << insertAtSortedArray(30);
    cout << insertAtSortedArray(38);
    cout << insertAtSortedArray(19);
    
    bubbleSort();
    traverseArray();
    
    cout << deleteFromTheEnd() << endl;
    traverseArray();
    cout << deleteFromTheEnd() << endl;
    traverseArray();
    cout << deleteFromTheBeginning() << endl;
    traverseArray();
    cout << deleteFromTheBeginning() << endl;
    traverseArray();
    cout << deleteFromGivenElement(7) << endl;
    traverseArray();
    cout << deleteFromGivenElement(19) << endl;
    traverseArray();

    cout << binarySearch(20, 0, numElem) << endl;
    cout << binarySearch(38, 0, numElem) << endl;
    
    return 0;
}




