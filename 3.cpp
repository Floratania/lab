#include <iostream> 

using namespace std; 
 
struct TQueueItem{ 
    int value; 
    TQueueItem *next; 
}; 
 
struct TQueue{ 
    TQueueItem *head; 
    TQueueItem *tail; 
}; 
 
TQueue initQueue(){ 
    TQueue q; 
    q.head = NULL; 
    q.tail = NULL; 
    return q; 
} 
 
int isEmpty(const TQueue&q ){ 
    return q.head == NULL; 
} 
 
void enQueue(TQueue &q, int value){ 
    if (isEmpty(q)){ 
        q.head = new TQueueItem(); 
        q.head->value = value; 
        q.head->next = NULL; 
        q.tail = q.head; 
    }else{ 
        q.tail->next = new TQueueItem; 
        q.tail->next->value = value; 
        q.tail->next->next = NULL; 
        q.tail = q.tail->next; 
    } 
} 
int deQueue(TQueue &q){ 
    if (isEmpty(q)){ 
        return 0; 
    }else{ 
        int result = q.head->value; 
        TQueueItem *item = q.head; 
        q.head = q.head->next; 
        delete item; 
        if (q.head == NULL) q.tail = q.head; 
        return result; 
    } 
} 
void destroyQueue(TQueueItem *&item){ 
    if(item != NULL){ 
        destroyQueue(item->next); 
        delete item; 
        item = NULL; 
    } 
} 
 
void destroyQueue(TQueue* &q) 
{ 
    destroyQueue(q->head); 
    q->tail = NULL; 
} 
 
int main(){ 
 
    TQueue q; 
    q = initQueue(); 
    char testString[50]; 
    char l; 
 
    cout << "Enter a string (50 characters max): "<< endl; 
 
    cin.get(testString, 50); 
    for(int i = 0; i < 50; ++i){ 
        enQueue(q, testString[i]); 
    } 
     
    cout << "Enter letter: " << endl; 
    cin >> l; 
    int count = 0; 
    while(!isEmpty(q)){ 
        if (l == deQueue(q)){ 
            count++; 
        } 
 
    } 
    cout << "Number of " << l << " is " << count << endl; 
    return 0; 
}