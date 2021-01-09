#include <iostream> 
#include <queue>

using namespace std; 
  
class BST  
{ 
    int data; 
    BST *left, *right; 
  
public: 
    
    BST(); 
    BST(int); 
    BST* Insert(BST*, int); 
    BST* DeleteNode(BST*, int);
    BST* inorderSuccessor(BST*, int);
    BST* find(BST*, int);
    void Inorder(BST*); 
    void Preorder(BST*);
    void Postorder(BST*);
    void Levelorder(BST*);
    int findMax(BST*);
    int findMin(BST *);
    int height(BST *);
    bool search(BST*, int);
    bool isBST(BST *);
    bool leftBST(BST *, int);
    bool rightBST(BST *, int);
}; 
  

BST ::BST() 
    : data(0) 
    , left(NULL) 
    , right(NULL) 
{ 
} 

BST ::BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 
  

BST* BST ::Insert(BST* root, int value) 
{ 
    if (!root)  
    { 
        return new BST(value); 
    } 
  
    if (value > root->data)  
    { 
        root->right = Insert(root->right, value); 
    } 
    else 
    { 
        root->left = Insert(root->left, value); 
    } 
    return root; 
} 
  
void BST ::Inorder(BST* root) 
{ 
    if (!root) { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << " "; 
    Inorder(root->right); 
}

bool BST :: search(BST* root, int data){

    if (root==NULL) return false;
    else if(root->data == data) return true;
    else if(data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

BST* BST :: find(BST* root, int data){
    
    if(root==NULL) return NULL;
    else if(root->data == data) return root;
    else if(data < root->data) return find(root->left, data);
    else return find(root->right, data);
}

void BST :: Postorder(BST* root){

    if(!root){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void BST :: Preorder(BST* root){

    if(!root){
        return;
    }

    cout<<root->data<<" ";
    Postorder(root->left);
    Postorder(root->right);
}

int BST :: findMax(BST* root){

    if(root == NULL){
        return -1;
    }

    if(root->right == NULL){
        return root->data;
    }

    return findMax(root->right);
}

int BST :: findMin(BST* root){

    if(root == NULL){
        return -1;
    }

    if(root->left == NULL){
        return root->data;
    }

    return findMax(root->left);
}

void BST :: Levelorder(BST* root){

    if (root==NULL) return;
    queue<BST*> Q;
    Q.push(root);

    while(!Q.empty()){

        BST* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }

}

bool BST:: leftBST(BST* root, int value){

    if(root==NULL) return true;
    if(root->data <= value
            && leftBST(root->left, value)
            && leftBST(root->right, value))
        return true;
    else
        return false;
}

bool BST :: rightBST(BST* root, int value){
    if(root==NULL) return true;
    if(root->data > value
            && rightBST(root->left, value)
            && rightBST(root->right, value))
        return true;
    else
        return false;
}
// Do it yourself again
bool BST :: isBST(BST* root){

    if (root==NULL) return true;
    if(leftBST(root->left, root->data)
    && rightBST(root->right, root->data)
    && isBST(root->left)
    && isBST(root->right))
        return true;
    else
        return false;
}

int BST :: height(BST* root){

    if (root==NULL){
        return -1;
    }

    return max(height(root->left), height(root->right)) + 1;
}

BST* BST :: DeleteNode(BST* root, int data){

    if (root==NULL) return root;
    else if(data < root->data) root->left = DeleteNode(root->left, data);
    else if(data > root->data) root->right = DeleteNode(root->right, data);
    else
    {
        if (root->left == NULL and root->right==NULL){
            delete root;
            root = NULL;  
        }
        else if(root->left == NULL){
            BST* temp = root;
            root = root->right;
            delete temp; 
        }
        else if(root->left == NULL){
            BST* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            root->data = findMin(root->right);
            root->right = DeleteNode(root->right, root->data);
        }
    }

    return root;
}

BST* BST :: inorderSuccessor(BST* root, int data){

    BST* current = find(root, data);
    if(current==NULL) return NULL;

    if(current->right != NULL){

        BST* temp = current->right;
        while(temp->left != NULL) temp = temp->left;
        return temp;
    }
    else{
         
         BST* successor = NULL;
         BST* ancestor = root;

         while(ancestor != current){
             if(current->data < ancestor->data){
                 successor = ancestor;
                 ancestor = ancestor->left;
             }
             else{
                 ancestor = ancestor->right;
             }
         }
    }

}


int main(){

    BST b, *root = NULL; 
    root = b.Insert(root, 50); 
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80); 
  
    b.Inorder(root);
    cout<<endl;
    b.Postorder(root);
    cout<<endl;
    b.Preorder(root);
    cout<<endl;
    b.Levelorder(root);

    cout<<"\nWas it found? "<<b.search(root, 40)<<endl;
    cout<<"Maximum Value: "<<b.findMax(root)<<endl;
    cout<<"Minimum Value: "<<b.findMin(root)<<endl;
    cout<<"Height of Tree: "<<b.height(root)<<endl;
    cout<<"Deleting a Node: 70"<<endl;
    b.DeleteNode(root, 70);
    b.Inorder(root);

    BST* temp = b.find(root, 40);
    return 0;
}