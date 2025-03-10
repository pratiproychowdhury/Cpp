/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
*/


int walk(Node* root, int level) {
    
    if (root->left==NULL) {
        if (root->right==NULL)
            return level;
        else return walk(root->right, level+1);
    }
    if (root->right==NULL)
        return walk(root->left, ++level);
    
    int leftlevel = walk(root->left, level+1);
    int rightlevel = walk(root->right, level+1);
    
    return (leftlevel>rightlevel) ? leftlevel : rightlevel; 
}

    int height(Node* root) {
        // Write your code here.
        return walk(root, 0);    
       
    }
  
