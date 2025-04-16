int parity(uint64_t input) {

  int counter = 0;
  uint64_t mask = 1;
  
  while (input) {
    if (input & mask)
      counter++;
    input >>= 1;
  }
  
  return counter & mask;
}




int fibonacci(int term) {

  int first = 0, second = 1;
  
  if (term<3)
    return term;
    
  for (int i=2; i <= term; i++) {
    int temp = first + second;
    first = second;
    second = temp;
  }
  return first;
}

1    2    3    4
0    1    1    2




template<class T>
class Node {
  public:
    Node();
    ~Node();
  T data;
  Node* left;
  Node* right;
};

template<class T>
class BST {

  private:
    Node<T>* root;
    
  public:
    BST();
    ~BST();
    int InsertNode(T data);
    int RemoveValue(T data);
    bool SearchNode(T data);
};

template<class T>
BST<T>::BST() {
  std::shared_ptr<Node<T> *> root(new Node<T>());
}

template<class T>
BST<T>::~BST() {
}


template<class T>
int BST<T>::InsertNode(T data) {
  std::shared_ptr<Node<T> *> ptr;
}


template<class T>
bool BST<T>::SearchNode(T data) {
  Node<T> * ptr = root;
  
  if (!ptr)
    return -1;
    
  if (ptr->data == data)  
    return 0;
    
  while (ptr && (ptr->data != data)) {
    if (ptr->data > data)
      ptr = ptr->left;
    else 
      ptr = ptr->left;
    }

  if (ptr && (ptr->data == data))
    return 0;
  else
    return -1;
}
