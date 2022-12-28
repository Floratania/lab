#include <iostream>

using namespace std;

struct Node {
    char value;
    Node *next;
};

bool isEmpty(Node *stack){
    return (stack == NULL);
}

void push(Node **stack, char value){
    Node *stack_1 = new Node();
    stack_1->value = value;
    stack_1->next = (*stack);
    (*stack) = stack_1;
}
char pop(Node *&stack){
    if(isEmpty(stack)){
        return '\0';
    }else{
        char tmp = stack->value;
        Node *next = stack->next;
        delete stack;
        stack = next;
        return tmp;
    }
}

void printLinkedList(const Node *stac) {
    
    while (stac) 
    {
        cout << stac->value;
        stac = stac->next;
    }
    cout << endl;
}

void destroy_stack(Node *stack){
    if(!isEmpty(stack)){
        destroy_stack(stack->next);
        delete stack;
        stack = NULL;
    }
}
int main(){
    Node *s = NULL;

    char ch;
    char testString[50];

    cout << "Enter a string to be reversed (50 characters max): "<< endl;

	cin.get(testString, 50);

    int i = 0;
    while(testString[i] != '\0')
	{
		push(&s, testString[i]);
		i++;
	}
    
    cout << "Your string printed in reverse is" <<endl;
    
    while(!isEmpty(s)) {
        cout << pop(s);
    }

    printLinkedList(s);
    destroy_stack(s);
	return 0;
    


}
