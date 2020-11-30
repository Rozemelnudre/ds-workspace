#include <iostream>
#include <sstream>
#include <string>
#include "Sorting.cpp"
#include "TreeNode.h"


using namespace std;
using namespace ds_workspace;

Node* rightRotate(Node* y);
Node* leftRotate(Node* y);
Node* bstInsert(string key, Node* root, int mode);
int max(int first, int second);
int height(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
void inOrderTraversal(Node* root);
Node * minValueNode(Node* node);
int get(string key, Node* root, int mode);
Node* deleteNode(Node* root, string key,int mode);
string locate(string key, Node* root, int mode);


int main(){

    string line;
    string command;
    string word;
    string modeCom;
    int mode;
    Node* root = NULL;
    getline(cin, line);
    istringstream inputLine(line);
    inputLine >> modeCom;
    if(modeCom == "COLEX"){
        mode = 2;
    }else if(modeCom == "LEX"){
        mode = 0;
    }else if(modeCom == "SHORTLEX"){
        mode = 1;
    }

    cout << "the mode is " << modeCom << endl;

    while(getline(cin, line)){
        istringstream inputLine(line);

        
        

        inputLine >> command;
        //cout << "right now doing " << command << endl;

        if(command == "I"){

            /*insert all words on the line*/
            while(inputLine >> word){
                cout << "inserting word " << word << endl;
                if(root == NULL){

                    root = new Node(word);
                }else{
                  root = bstInsert(word,root, mode);
                }

                //cout << "root is " << root->key << " balance is " << getBalance(root)<< endl;
                //cout << "root left is " << root->left->key << endl;
                //cout << "root right is " << root->right->key << endl;

                inOrderTraversal(root);
                
            }
           
        }else if(command == "E"){
            


        }else if(command == "G"){
          
         

        }else if(command == "L"){
            inputLine >> word;
            cout << locate(word, root, mode) << endl;
           
          
           
        }else if (command == "D"){
            
        }

    }
     //cout << "root is " << root->key << " balance is " << getBalance(root)<< endl;
     inOrderTraversal(root);
    return 0;
}

Node* bstInsert(string key, Node* root, int mode){
    if(root == NULL){
        return new Node(key);
    }else if( compare(key, root->key, mode) == key){
        //cout << "adding left child " << endl;
        /*if the key is less than root move left or add left child if it is empty*/
        root->left = bstInsert(key, root->left,mode);
        

    }else if(compare(key, root->key, mode) == root->key){
        //cout << "adding right child " << endl;
        /*if the key is larger than root move right or add right child if it is empty*/

        root->right = bstInsert(key, root->right,mode);
        
    }else{
        //cout << "inserting the same" << endl;
        return root;
    }

    /*update the height*/
    root->height = 1 + max(height(root->left),height(root->right)); 
    int balance;
    balance = getBalance(root);
     //cout << "node is " << root->key << " balance is " << getBalance(root)<< endl;

    /*check the balance factor for the currrent node or root. because of recursion this should be also checked for
    all nodes up to the root*/ 
   // cout << "key is " << endl;
        if (balance > 1 && compare(key,root->left->key,mode) == key){
            //cout << "doing rightRotate" << endl;
           return rightRotate(root);   
        } 
        
  
    // Right Right Case  
    if (balance < -1 && compare(key,root->right->key,mode) == root->right->key)  
        return leftRotate(root);  
  
    // Left Right Case  
    if (balance > 1 && compare(key,root->left->key,mode) == root->left->key)  
    {  
        //cout << "doing leftRotate" << endl;
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Left Case  
    if (balance < -1 && compare(key,root->right->key,mode) == key)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  

    /*if necessary do rotation*/
    return root;
}


int max(int first, int second){
    if(first > second){
        return first;
    }
    return second;
}

int height(Node* node){
    if(node == NULL){
        return 0;
    }else{
        return node->height;
    }
}
/*balancing functions*/

int getBalance(Node* node){
    if(node == NULL){
        return 0;
    }else{
        return height(node->left) - height(node->right); 
    }

}

/*rotations*/
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node* rightRotate(Node* y)  
{  
    Node* x = y->left;  
    Node* T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left),height(y->right)) + 1;  
    x->height = max(height(x->left),height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node* leftRotate(Node* x)  
{  
    Node* y = x->right;  
    Node* T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),height(x->right)) + 1;  
    y->height = max(height(y->left),height(y->right)) + 1;  
  
    // Return new root  
    return y;  
} 


/*print inorder*/

void inOrderTraversal(Node* root){
    if(root->left != NULL){
        inOrderTraversal(root->left);
    }
    cout << "(" << root->key << ", " << root->baddness << ")" << endl;
    if(root->right != NULL){
        inOrderTraversal(root->right);
    }

}

/*deleting function*/
Node * minValueNode(Node* node){  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
} 

Node* deleteNode(Node* root, string key,int mode)  {  
      
    // delete node as in bst
    if (root == NULL)  
        return root;  
  
    // If the key is smaller than the root key move left 
    if (compare(key,root->key,mode) ==  key)  
        root->left = deleteNode(root->left, key, mode);  
  
    // If the key is larger than the root key, then move right
    else if( compare(key,root->key,mode) == root->key )  
        root->right = deleteNode(root->right, key, mode);  
  
    // if key is the same this is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp;
            if(root->left != NULL){
                temp = root->left;
            }else{
                temp = root->right;
            } 
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,temp->key, mode);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // update node height 
    root->height = 1 + max(height(root->left),height(root->right));  
  
    // check balance
    int balance = getBalance(root);  
  
    // If this node is unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 && getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 && getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 && getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
} 

/*get*/

int get(string key, Node* root, int mode){
    if (root->key == key){
        return root->baddness;
    }else if(compare(root->key,key,mode) == key){
        return get(key,root->left,mode);
    }else{
        return get(key, root->right,mode);
    }
    return 0;
}

/*locate*/
string locate(string key, Node* root, int mode){
    string path = "*";  
    Node* current = root;
    int found = 0;
    while(current != NULL && found == 0){
        if (current->key == key){
            found = 1;
            return path;
        }else if(compare(current->key,key,mode) == key){
            cout << "moving left, key is and root is " << key << " " << current->key << endl;
            cout << "path before " << path << endl;
            path += "L";
            cout << "path after " << path << endl;
            current = current->left;
        }else{
            cout << "moving right, key is and root is " << key << " " << current->key << endl;
            cout << "path before " << path << endl;
            path += "R";
            cout << "path after " << path << endl;
            current = current->right;
        }
    }
   
   
    path = "N";
    return path;
}

/*dump*/

/*finding function */