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
void gett(string key, Node* root, int mode);
Node* deleteNode(Node* root, string key,int mode);
string locate(string key, Node* root, int mode);
void dump(string start, string end, int mode);
void inOrderTraversalPrint(Node* root);

int getNode(string key, Node* root, int mode);


int inOrderCounter = 0;
Node* inOrder[10000];

Node* gotNode = NULL;


int main(){

    string line;
    string command;
    string word;
    string modeCom;
    string start;
    string end;
    int mode;
    int lineCounter = 0;
    Node* root = NULL;
    getline(cin, line);
    istringstream inputLine(line);
    inputLine >> modeCom;
    lineCounter++;
    if(modeCom == "COLEX"){
        mode = 2;
    }else if(modeCom == "LEX"){
        mode = 0;
    }else if(modeCom == "SHORTLEX"){
        mode = 1;
    }

    //cout << "the mode is " << modeCom << endl;

    while(getline(cin, line)){
        istringstream inputLine(line);
        lineCounter++;

        
        

        inputLine >> command;
        //cout << "right now doing " << command << endl;

        if(command == "I"){

            /*insert all words on the line*/
            while(inputLine >> word){

                
               
                
                
                
                if(root == NULL){

                    root = new Node(word);

                }else{
  
                    gett(word,root,mode);
                    if(gotNode == NULL){
                        root = bstInsert(word,root, mode);
                    }else{
                        gotNode->baddness++;
                    }
                }

                

                
            }
           
        }else if(command == "E"){


            while(inputLine >> word){
                //cout << "erasing word " << word << endl;
                /*if node present delete*/
                gett(word,root,mode);
                if(gotNode != NULL){
                    root = deleteNode(root,word,mode);
                }
            }
            


        }else if(command == "G"){
          inputLine >> word;
         gett(word,root,mode);
         //cout << "getting word " << word << endl;
         cout << lineCounter << " ";
         if(gotNode != NULL){
            cout << "(" <<  gotNode->key << "," << gotNode->baddness << ")" << endl;
         }else{
             cout << "(" <<  word << "," << 0 << ")" << endl;
         }
         

        }else if(command == "L"){
            inputLine >> word;
            //cout << "locating word " << word << endl;
            cout << lineCounter << " ";
            cout << locate(word, root, mode) << endl;
           
          
           
        }else if (command == "D"){
            inputLine >> start;
            inputLine>> end;
            //cout << "dumping from " << start << " to " << end << endl;
            inOrderCounter = 0;
            inOrderTraversal(root);
            cout << lineCounter;
            dump(start, end,mode);
            cout << endl;

            
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
     
        /*if the key is less than root move left or add left child if it is empty*/
        root->left = bstInsert(key, root->left,mode);
        

    }else if(compare(key, root->key, mode) == root->key){
        
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
     
    /*check the balance factor for the currrent node or root. because of recursion this should be also checked for
    all nodes up to the root*/ 
   // cout << "key is " << endl;
        if (balance > 1 && compare(key,root->left->key,mode) == key){
           
           return rightRotate(root);   
        } 
        
  
    // Right Right Case  
    if (balance < -1 && compare(key,root->right->key,mode) == root->right->key){
    
        return leftRotate(root); 
    } 
         
  
    // Left Right Case  
    if (balance > 1 && compare(key,root->left->key,mode) == root->left->key)  
    {  
       
      
        root->left = leftRotate(root->left);  
        //cout << root->left->left->key << " " << root->left->key << endl;
        return rightRotate(root);  
    }  
  
    // Right Left Case  
    if (balance < -1 && compare(key,root->right->key,mode) == key)  
    {  
   
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  

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

void inOrderTraversalPrint(Node* root){
    if(root->left != NULL){
        inOrderTraversalPrint(root->left);
    }
    cout << "(" << root->key << ", " << root->baddness << ")" << endl;
    if(root->right != NULL){
        inOrderTraversalPrint(root->right);
    }

}

void inOrderTraversal(Node* root){
    if(root->left != NULL){
        inOrderTraversal(root->left);
    }
    inOrder[inOrderCounter] = root;
    inOrderCounter++;
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
    if (compare(key,root->key,mode) ==  key && key != root->key) {
        //cout << "moving left" << endl;
        root->left = deleteNode(root->left, key, mode);  
  
    // If the key is larger than the root key, then move right
    }else if( compare(key,root->key,mode) == root->key && key != root->key){
        //cout << "moving right" << endl;
        root->right = deleteNode(root->right, key, mode);  
  
    // if key is the same this is the node to be deleted  
    }else
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
           //cout << "deletion" << endl;
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
            root->baddness = temp->baddness;
  
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

void gett(string key, Node* root, int mode){
    gotNode = NULL;
    if (root->key == key){
        gotNode = root;
    }else if(compare(root->key,key,mode) == key){
        if(root->left != NULL){
          gett(key,root->left,mode);  
        }
        
    }else{
        if(root->right != NULL){
          gett(key, root->right,mode);  
        }
        
    }
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
            path += "L";
            
            current = current->left;
        }else{
            path += "R";
           
            current = current->right;
        }
    }
   
   
    path = "N";
    return path;
}

/*dump*/

void dump(string start, string end, int mode){
    //cout << "inorder counter is " << inOrderCounter << endl;
    if(start == "_" && end == "_"){ 
        
        for (int i = 0; i < inOrderCounter; i++){
            cout << " (" << inOrder[i]->key << "," << inOrder[i]->baddness << ")";
        }
    }else if(start == "_"){
        for (int i = 0; i < inOrderCounter; i++){
            if(compare(inOrder[i]->key, end, mode) == inOrder[i]->key){
              cout << " (" << inOrder[i]->key << "," << inOrder[i]->baddness << ")";  
            }
            
        }
    }else if(end == "_"){
        for (int i = 0; i < inOrderCounter; i++){
            if(compare(inOrder[i]->key, start, mode) == start){
                //cout << "i and start and mmode  is " << i << " " << start << " " << mode << endl;
              cout << " (" << inOrder[i]->key << "," << inOrder[i]->baddness << ")";  
            }
            
        }
    }else{
        /*start and end are both normal*/
         for (int i = 0; i < inOrderCounter; i++){
            if(compare(inOrder[i]->key, start, mode) == start && compare(inOrder[i]->key, end, mode) == inOrder[i]->key){
              cout << " (" << inOrder[i]->key << "," << inOrder[i]->baddness << ")";  
            }
            
        }

    }
}

/*finding function */