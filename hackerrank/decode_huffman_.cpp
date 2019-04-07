/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/

void decode_huff(node * root, string s) {
    
    node* ptr = root;
    string output;

    for (string::iterator it = s.begin(); it != s.end(); ++it) {
      if (*it == '0')
        ptr = ptr->left;
      else
        ptr = ptr->right;
      if (ptr->data) {
        output += ptr->data;
        ptr = root;
      }
    }
    cout << output << endl;
}
