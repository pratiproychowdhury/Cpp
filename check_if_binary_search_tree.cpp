/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool checksub(Node* root, int minimum, int maximum) {
    
       bool left_side = true, right_side = true;
       
       if (root->left) {
           // cout << "comparing root " << root->data << " and left " << (root->left)->data << " min max " << minimum << " " << maximum << endl;
            if (!((root->left)->data < root->data))
                return false;
           if (!((root->left)->data > minimum))
               return false;
           left_side = checksub(root->left, minimum, min(root->data, maximum));
           if (!left_side)
               return false;
       }
       
       if (root->right) {
           // cout << "comparing root " << root->data << " and right " << (root->right)->data << " min max " << minimum << " " << maximum << endl;
            if (!((root->right)->data > root->data))
                return false;
           if (!((root->right)->data < maximum))
               return false;
           right_side = checksub(root->right, max(minimum, root->data), maximum);
           if (!right_side)
               return false;
       }      
       
      return true;    
    
}


bool checkBST(Node* root) {
       
    return checksub(root, -30000 , 30000 );   
}
