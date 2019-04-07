/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

        Node *lca(Node *root, int v1, int v2) {
          Node *ptr1;
          Node *ptr2;
          set<Node *> path;

          ptr1 = root;
          path.insert(ptr1);
          while (ptr1->data != v1) {
            if (ptr1->data < v1)
              ptr1 = ptr1->right;
            else
              ptr1 = ptr1->left;
            path.insert(ptr1);
          }

          Node *lca = root;
          ptr2 = root;
          while (ptr2->data != v2) {
            if (path.find(ptr2) != path.end())
                lca = ptr2;
            if (ptr2->data < v2)
                ptr2 = ptr2->right;
            else
                ptr2 = ptr2->left;
            }
        return lca;
    }
