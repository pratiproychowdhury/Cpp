// For binary data (i.e. not null terminated); should not overwrite data but write up to all available space

class Queue {
  
  public:
    Queue(int n);
    ~Queue();
  
    int enqueue(const char* data, int size);  
    int dequeue(char* data, int size);

  private:
    char* buffer;
    int size;
    int first; // Position of first character
    int last; // Position of last character
}

Queue::Queue(int n): size(n), buffer(new char[n]) {

  first = 0;
  last = 0;
}

Queue::~Queue() {

  delete[] buffer;  
}

int Queue::enqueue(const char* data, int size) {
  
  if (!first) {
    buffer = new char[this.size];
    memcpy(data, buffer, min(size, this.size));
    first = 0;
    last = min(size, this.size)-1;
  }
  else {
    
    
    
  }
}

int Queue::dequeue(char* data, int size) {
  
  
}
