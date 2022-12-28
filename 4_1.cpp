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
    cout << "Enter the number of elements list: "<< endl;
    cin >> n;

    int number;
    cout << "Enter elements of list: "<< endl;
    for (int i = 0; i < n; i++){
        cin >> number;
        addListItem(list, number);
    }
    
    cout << "List: "<< endl;
    printList(list);

    int minim = list.first->value;
    TListItem* tmp = list.first;

    do {
        if(minim > list.first->value){
            minim = list.first->value;
        }
        list.first = list.first->next;
    }while (list.first != tmp);

    cout<<"Minimum element list: "<< minim << endl; 

    destroyList(list);
    
    return 0;
}