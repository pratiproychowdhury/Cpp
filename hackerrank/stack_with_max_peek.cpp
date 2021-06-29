template <class T>
  
class Data {
  T a;
  Data* previous;
}
  
class DataStack {
  
    stack<Data> stk;
    Data* endptr;
  
 public:
   T pop() {
     
   }
  
  
  void push(T t) {
    
  }
  
  T peek() {
    return max_element(stk.begin(), stk.end());
  }
  
};
