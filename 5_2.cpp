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
        list.first->next = NULL;
        list.first->prev = NULL;
        list.last = list.first;
    }else{
        TListItem* newItem = new TListItem;
        newItem->value = value;
        newItem->next = NULL;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
    }
    
}

void destroyList(TList &list){
    TListItem* itemToDelete = list.first;
    TListItem* tmp;
    while( itemToDelete != NULL){
        tmp = itemToDelete->next;
        delete itemToDelete;
        itemToDelete = tmp;
    }
    list.first = NULL;
    list.last = NULL;
}

void printList(TList list){
    TListItem* tmp = list.first;
    while(tmp != NULL){
        cout << " " << tmp->value;
        tmp = tmp->next;
    }
    cout<<endl;
}

int main()
{
    TList first_list = initList();
    TList second_list = initList();
    int n, m;
    cout << "Enter the number of elements first_list: " << endl;
    cin >> n;

    cout << "Enter the number of elements second_list: " << endl;
    cin >> m;

    int number;
    cout << "Enter elements of first_list: "<< endl;
    for (int i = 0; i < n; i++){
        cin >> number;
        addListItem(first_list, number);
    }
    
    cout << "Enter elements of second_list: " << endl;
    for (int i = 0; i < m; i++){
        cin >> number;
        addListItem(second_list, number);
    }

    cout << "list first_list: " << endl;
    printList(first_list); 
    cout << "list second_list: " << endl;
    printList(second_list);
    
    TListIterator it_first_list = getBegin(first_list);
    
    cout << "Elements :  " <<endl;
    while (isValid(it_first_list)){

        TListIterator it_second_list = getBegin(second_list);
        int flag = 0;
        while(isValid(it_second_list)){
            if(getValue(it_first_list) == getValue(it_second_list)){
                flag = 1;
                break;
            }
            moveNext(it_second_list);
        }
        if(!flag){

            cout << getValue(it_first_list) << " ";
        }
        moveNext(it_first_list);
    }
    cout << endl;
    

    destroyList(first_list);
    destroyList(second_list);
    
    return 0;
}