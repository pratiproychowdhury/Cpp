#include <memory>
#include <iostream>
#include <cassert>


// Basic linked list
// Does not provide iterators, keeps internal position state
template <typename T>
class LinkedList {
public:

  typedef T item_t;
  typedef typename std::shared_ptr<item_t> ptr_t;
  
  struct Node {
    item_t item;
    Node* next;
    Node* prev;
  };
    
  size_t items;
  Node* head;
  Node* tail;
  Node* currptr;
  
  LinkedList() {
      items = 0;
      head = NULL;
      tail = NULL;
      currptr = NULL;
  }
  
  ~LinkedList() {
    clear();
  }
  
  static const ptr_t empty_ptr() {
    static ptr_t empty{};
    return empty;
  }

  // Function to check if a list is empty
  bool empty() const {
    if (items)
      return false;
    else
      return true;
  }

  // Return number of elements in the list
  size_t size() const {
    return items;
  }

  // Clear all elements from list
  void clear() {
    while (head) {
      Node* next = head->next;
      delete head;
      head = next;
    }
    items = 0;
    tail = NULL;
    currptr = NULL;
  }

  // Get reference to the current item in the list
  // Behavior is undefined for empty list
  item_t& current() {
    return currptr->item;
  }

  // Returns pointer to first item in list
  //     or empty_ptr
  // Relocates current to beginning of list
  const ptr_t first() {
    if (!head)
      return empty_ptr();
    else {
      std::shared_ptr<item_t> ptr = std::make_shared<item_t>(head->item);
      currptr = head;
      return ptr;
    }
  }

  // Returns pointer to last item in list
  //     or empty_ptr
  // Relocates current to end of list
  const ptr_t last() {
    if (!tail)
      return empty_ptr();
    else {
      std::shared_ptr<item_t> ptr = std::make_shared<item_t>(tail->item);
      currptr = tail;
      return ptr;
    }
  }

  // Get the next / previous item from the list and set as current
  // Returns pointer to current item
  //   or empty_ptr if operation be invalid
  const ptr_t next() {
    if ((!currptr) || (!currptr->next))
      return empty_ptr();
    currptr = currptr->next;
    return std::make_shared<item_t>(currptr->item);
  }

  const ptr_t prev() {
    if ((!currptr) || (!currptr->prev))
      return empty_ptr();
    currptr = currptr->prev;
    return std::make_shared<item_t>(currptr->item);
  }

  // Append an item to the end of the list
  // Does not modify current position
  void push_back(const item_t& item) {
    if (!items) {
      Node* new_item = new Node;
      new_item->item = item;
      head = new_item;
      tail = new_item;
      items++;
      currptr = new_item;
      return;       
    }
    
    Node* new_item = new Node;
    new_item->item = item;
    new_item->prev = tail;
    tail->next = new_item;
    tail = new_item;
    items++;
  }

  // Prepend an item to the beginning of the list
  // Does not modify current position
  void push_front(const item_t& item) {
    if (!items) {
      Node* new_item = new Node;
      new_item->item = item;
      head = new_item;
      tail = new_item;
      items++; 
      currptr = new_item; 
      return;     
    }
    
    Node* new_item = new Node;
    new_item->item = item;
    new_item->next = head;
    head->prev = new_item;
    head = new_item;
    items++;
  }

  // Insert item before current item and set to current
  // Returns pointer to previous current item
  //     or empty_ptr if empty list
  const ptr_t insert(const item_t& item) {
    if (!items) {
      Node* new_item = new Node;
      new_item->item = item;
      head = new_item;
      tail = new_item;
      items++;
      currptr = new_item;
      return empty_ptr();       
    }
    
    Node* new_item = new Node;
    new_item->item = item;
    new_item->next = currptr;
    Node* before = currptr->prev;
    
    if (before) {
      before->next = new_item;
      new_item->prev = before;
    }
    else { // It was the head
      head = new_item;
    }  
    currptr->prev = new_item;
    items++;
    currptr = new_item;
    return std::make_shared<item_t>((new_item->next)->item);
  }

  // Append item after current item and set to current
  // Returns pointer to previous current item
  //     or empty_ptr if empty list
  const ptr_t append(const item_t& item) {
    if (!items) {
      Node* new_item = new Node;
      new_item->item = item;
      head = new_item;
      tail = new_item;
      items++;
      currptr = new_item;
      return empty_ptr();       
    }
    
    Node* new_item = new Node;
    new_item->item = item;
    new_item->prev = currptr;
    Node* after = currptr->next;
    
    if (after) {
      after->prev = new_item;
      new_item->next = after;
    }
    else { // It was the tail
      tail = new_item;
    }  
    currptr->next = new_item;
    items++;
    currptr = new_item;
    return std::make_shared<item_t>((new_item->prev)->item);
  }

  // Remove the current item from the list
  //    and move current item to next after removed item
  // no-op if empty list
  // Returns pointer to removed (formerly current) item
  //     or empty_ptr if empty list
  const ptr_t removeCurrent() {
    if (!items) {
      return empty_ptr();
    }
    
    Node* toremove = currptr;
    Node* before = currptr->prev;
    Node* after = currptr->next;
    
    if (before) {
      before->next = currptr->next;
    }
    else { // It was the head
      head = currptr->next;
    }     

    if (after) {
      after->prev = currptr->prev;
      currptr = after;
    }
    else { // It was the tail
      tail = currptr->prev;
      currptr = NULL;
    }
        
    items--;
    return std::make_shared<item_t>(toremove->item);   
  }

};
using linked_list_t = LinkedList<int>;
using std::cout;
using std::cerr;

// NOTE - is_equal() relocates current() to end of list
bool is_equal(linked_list_t& ll, const std::initializer_list<int>& vals) {
    if (ll.size() != vals.size())
        return false;

    ll.first();
    for (auto iter: vals)
    {
        if (ll.current() != iter)
            return false;
        cout << ll.current() << ' ';
        ll.next();
    }
    
    cout << '\n';
    return true;
}

int main(int argc, char** argv) {
        linked_list_t ll;
    cerr << "Test empty...";
    assert(ll.empty());
    cerr << "done\n";

    cerr << "Test push_back...";
    ll.push_back(1);
    assert(!ll.empty());
    assert(ll.size() == 1);
    assert(ll.current() == 1);
    ll.push_back(2);
    assert(ll.size() == 2);
    assert(ll.current() == 1);
    assert(is_equal(ll, {1, 2}));
    cerr << "done\n";

    cerr << "Test push_front...";
    ll.push_front(0);
    assert(ll.size() == 3);
    assert(is_equal(ll, {0, 1, 2}));
    cerr << "done\n";

    cerr << "Test clear...";
    ll.clear();
    assert(ll.size() == 0);
    cerr << "done\n";
    
    cerr << "Test removeCurrent() on empty list...";
    auto item = ll.removeCurrent();
    assert(item == linked_list_t::empty_ptr());
    cerr << "done\n";
    
    
    cerr << "Test insert on empty list...";
    item = ll.insert(100);
    assert(item == linked_list_t::empty_ptr());
    assert(ll.size() == 1);
    assert(ll.current() == 100);
    cerr << "done\n";

    
    cerr << "Test append on empty list...";
    ll.clear();
    assert(ll.size() == 0);
    item = ll.append(0);
    assert(item == linked_list_t::empty_ptr());
    assert(ll.size() == 1);
    assert(ll.current() == 0);
    cerr << "done\n";
    
    for (int i = 1; i < 10; ++i)
        ll.push_back(i);
    
    assert(ll.size() == 10);
    assert(ll.current() == 0);

    cerr << "Test first and next...";
    item = ll.first();
    for (int i = 0; i < 5; ++i) {
        item = ll.next();
    }
    
    assert((*item) == 5);
    cerr << "done\n";

    cerr << "Test insert on non-empty list...";
    item = ll.insert(40);

    assert(ll.size() == 11);
    assert(ll.current() == 40);
    assert(is_equal(ll, {0, 1, 2, 3, 4, 40, 5, 6, 7, 8, 9}));
    cerr << "done\n";

    item = ll.first();
    for (int i = 0; i < 5; ++i) {
        item = ll.next();
    }

    cerr << "Test removeCurrent...";
    item = ll.removeCurrent();
    assert(*item == 40);
    assert(ll.size() == 10);
    assert(ll.current() == 5);
    assert(is_equal(ll, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cerr << "done\n";

    item = ll.first();
    for (int i = 0; i < 5; ++i) {
        item = ll.next();
    }

    cerr << "Test append...";
    item = ll.append(50);
    assert(*item == 5);
    assert(ll.size() == 11);
    assert(ll.current() == 50);
    assert(is_equal(ll, {0, 1, 2, 3, 4, 5, 50, 6, 7, 8, 9}));
    cerr << "done\n";

    item = ll.first();
    for (int i = 0; i < 6; ++i) {
        item = ll.next();
    }
    item = ll.removeCurrent();
    assert(*item == 50);
    assert(ll.size() == 10);
    assert(ll.current() == 6);

    cerr << "Test last and prev...";
    item = ll.last();
    assert(*item == 9);

    item = ll.prev();
    assert(*item == 8);

    cerr << "done\n";
    return 0;
}
