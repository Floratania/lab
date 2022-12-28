#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>


using namespace std;

struct Node{
    int value;
    Node *left,*right;
};

void preorder(Node* root){
    if(root){
        cout << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->value << endl;
    }
    return;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->value << endl;
        inorder(root->right);
    }
    return;
}

void addElement(Node* &root,int newValue){
    if(!root){
        root = new Node;
        root->value = newValue;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(root->value < newValue)
        addElement(root->right, newValue);
    else
        addElement(root->left, newValue);
}

void printTree(Node* root){
    if(root){
        printTree(root->left);
        printTree(root->right);
        std::cout<<"Node value: "<<root->value<<std::endl;
    }
}


void printByLevels(Node* root){
    queue<Node*> queueOfLeafes;
    queueOfLeafes.push(root);
    while(queueOfLeafes.size() > 1){
        Node* leaf = queueOfLeafes.front();
        queueOfLeafes.pop();
        std::cout<<"Node value: "<<leaf->value<<std::endl;
        if(leaf->left)
            queueOfLeafes.push(leaf->left);
        if(leaf->right)
            queueOfLeafes.push(leaf->right);
    }
    return;
}

int countElementInTree(Node* root, int element){
    if(!root){
        return 0;
    }
    if(root->value == element){
        return 1 + countElementInTree(root->left, element) + countElementInTree(root->right, element);
    }else if(root->value > element){
        return countElementInTree(root->left, element);
    }else{
        return countElementInTree(root->right, element);
    }
}

int countSumElementInTree(Node* root){
    int sum_l = 0, sum_r = 0;
    if(root){
        sum_l = (root->left != nullptr) ? countSumElementInTree(root->left) : 0;
        sum_r = (root->right != nullptr) ? countSumElementInTree(root->right) : 0;
        return sum_l + sum_r + root->value;
    }
    return 0;
}



int main()
{
    Node* root = nullptr;
    int n = 0;
    srand(time(NULL));
    cout << "Enter the number of elements of tree: " <<endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        addElement(root,  rand() % 50 );
    }
    printTree(root);


    cout << "Sum: " << countSumElementInTree(root) << endl;
    return 0;
}