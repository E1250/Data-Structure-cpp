#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

class BST{
public:
    Node *root;
    BST(){
        root = NULL;
    }

    Node* Insert(Node *root , int item){
        if(root == NULL){
            Node* newNode = new Node(item);
            root = newNode;
        }else if(item < root->data){
            root->left = Insert(root->left,item);
        }else{
            root->right = Insert(root->right,item);
        }
        return root;
    }

    void Insert(int item){
        root = Insert(root,item);
    }

    void Preorder(Node*root){ // root - left - right
        if(root == NULL){
            return;
        }
        cout<<root->data << "\t";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(Node*root){ // left - root - right
        if(root == NULL){
            return;
        }
        Inorder(root->left);
        cout<<root->data << "\t";
        Inorder(root->right);
    }

    void Postorder(Node*root){ // left - right - root
        if(root == NULL){
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data << "\t";

    }

    Node* Search(Node *root,int key){
        if(root == NULL){
            return NULL;
        }else if(root->data == key){
            return root;
        }else if(key<root->data){
            return Search(root->left,key);
        }else{
            return Search(root->right,key);
        }
    }

    bool Search(int key){
        Node * result = Search(root,key);
        if(result == NULL){
            return false;
        }else{
            return true;
        }
    }

    Node* Findmin(Node* root){
        if(root ==NULL){
            return NULL;
        }else if(root->left == NULL){
            return root;
        }else{
            Findmin(root->left);
        }
    }

    Node* Findmax(Node* root){
         if(root ==NULL){
            return NULL;
        }else if(root->right == NULL){
            return root;
        }else{
            return Findmax(root->right);
        }
    }

    Node* Delete(Node * root , int key){
        if(root==NULL)
            return NULL;
        if(key < root->data){
            root->left = Delete(root->left , key);
        }else if(key > root->data)
            root ->right =Delete(root->right,key);
        else{
            if(root->left==NULL&&root->right==NULL) //leaf node
                root=NULL;
            else if(root->left!=NULL && root->right==NULL){ // one child on the left
                root->data = root -> left ->data;
                delete root->left;
                root->left =NULL;
            } else if(root->left==NULL && root->right!=NULL){ // one child on the right
                root->data = root -> right ->data;
                delete root->right;
                root->right =NULL;
            }else{ // node has two children
                Node * max=Findmax(root->left);
                root->data = max ->data;
               root->left = Delete(root->left , max->data);
            }

        }
        return root;

    }













};


int main(){

    BST bTree;
    bTree.Insert(45);
    bTree.Insert(15);
    bTree.Insert(79);
    bTree.Insert(90);
    bTree.Insert(10);
    bTree.Insert(55);
    bTree.Insert(12);
    bTree.Insert(20);
    bTree.Insert(50);

    cout<<"display the tree contenent \n";
    bTree.Preorder(bTree.root);
    cout<<"****************************** \n";
    bTree.Inorder(bTree.root);
    cout<<"****************************** \n";
    bTree.Postorder(bTree.root);
    cout<<"****************************** \n";

    cout<<"enter item to search for \n";
    int key;
    cin>>key;
    if(bTree.Search(key))
        cout <<"item found";
    else
        cout<<"item not found";


    cout<<"find minimum \n";
    cout<<bTree.Findmin(bTree.root)->data;
    cout<<"find max \n";
    cout<<bTree.Findmax(bTree.root)->data;

    cout<<"\n Delete items \n";
    cout<<bTree.Delete(bTree.root,12)->data;
    cout<<endl;
    bTree.Preorder(bTree.root);

    }