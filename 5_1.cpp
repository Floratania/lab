#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};

struct TList{
    TListItem *first, *last;

};

struct TListIterator{
    TListItem* pointer;
};

TListIterator initTListIterator(){
    TListIterator tmp;
    tmp.pointer = NULL;
    return tmp;
}

int isValid(TListIterator it){
    return it.pointer != NULL;
}

void moveNext(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->next;
    }
    return;
}

void movePrev(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->prev;
    }
    return;
}

int getValue(const TListIterator &it){
    if(isValid(it)){
        return it.pointer->value;
    }
    return 0;
}
void setValue(const TListIterator &it, int newValue){
    if(isValid(it)){
        it.pointer->value = newValue;
    }
    return;
}

TListIterator getBegin(TList l){
    TListIterator tmp;
    tmp.pointer = l.first;
    return tmp;
}

TListIterator getEnd(TList l){
    TListIterator tmp;
    tmp.pointer = l.last;
    return tmp;
}




void deleteListItem(TList &l, TListIterator &it){
    if(!isValid(it)){
        return;
    }
    if(it.pointer == l.first){
        l.first = it.pointer->next;
    }
    if(it.pointer == l.last){
        l.last = it.pointer->prev;
    }
    TListItem* next = it.pointer->next;
    TListItem* prev = it.pointer->prev;
    delete it.pointer;
    it.pointer = next;
    if (prev != NULL)
    {
        prev->next = next;
    }
    if(next != NULL){
        next->prev = prev;
    }
    if(l.first == NULL){
        l.last = NULL;
    }
    if (l.last == NULL){
        l.first = NULL;
    }
    return;
    
}

TList initList(){
    TList l;
    l.first = NULL;
    l.last = NULL;
    return l;
}

void addListItem(TList &list, int value){
    if(list.first == NULL){
        list.first = new TListItem;
        list.first->value = value;
        list.first->next = list.last;
        list.first->prev = list.last;
        list.last = list.first;
    }else{
        TListItem* newItem = new TListItem;
        newItem->value = value;
        newItem->next = list.first;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
    }
    
}

void destroyList(TList &list){
    TListItem* itemToDelete = list.first;
    TListItem* tmp;
    do{
        tmp = itemToDelete->next;
        delete itemToDelete;
        itemToDelete = tmp;
    }while(itemToDelete != list.first);

    list.first = NULL;
    list.last = NULL;
}

void printList(TList list){
    TListItem* tmp = list.first;
    do {
        cout<<" "<< tmp->value;
        tmp = tmp->next;
    } while (list.first != tmp);
    
    cout<<endl;
}



int main()
{
    TList list = initList();
    int n, m;
    cout << "Enter the number of elements list: " << endl;
    cin >> n;

    int number;
    cout << "Enter elements of list: " << endl;
    for (int i = 0; i < n; i++){
        cin >> number;
        addListItem(list, number);
    }
    
    cout << "List: "<< endl;
    printList(list);

    TListIterator it = getBegin(list);
    int minim = getValue(it);

    do {
        if(minim > getValue(it)){
            minim = getValue(it);
        }
        moveNext(it);
    }while (it.pointer != list.first);

    cout << "Minimum element list: " << minim << endl; 

    destroyList(list);
    
    return 0;
}