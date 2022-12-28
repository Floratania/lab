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
    cout << "Enter the number of elements first_list: "<< endl;
    cin >> n;

    cout << "Enter the number of elements second_list: "<< endl;
    cin >> m;

    int number;
    cout << "Enter elements of first_list: "<< endl;
    for (int i = 0; i < n; i++){
        cin >> number;
        addListItem(first_list, number);
    }
    
    cout << "Enter elements of second_list: "<< endl;
    for (int i = 0; i < m; i++){
        cin >> number;
        addListItem(second_list, number);
    }
    cout << "list first_list: "<< endl;
    printList(first_list);
    cout << "list second_list: "<< endl;
    printList(second_list);

    cout<<"Elements :  "<<endl;
    while(first_list.first != NULL){
        TListItem* tmp = second_list.first;
        int flag = 0;
        while(second_list.first != NULL){
            if(first_list.first->value == second_list.first->value){
                flag = 1;
                break;
            }
            second_list.first = second_list.first->next;
        }
        if(!flag){
            cout<<first_list.first->value<<" ";
        }
        second_list.first = tmp;
        first_list.first = first_list.first->next;

    }
    cout<<endl;
    

    destroyList(first_list);
    destroyList(second_list);
    
    return 0;
}