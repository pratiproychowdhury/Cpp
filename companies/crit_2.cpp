/*
 * Implement a custom MyVector class that acts similarly to std::vector<T>
 * - has a default constructor
 * - has a constructor that receives the capacity
 * - provides a method to add new elements
 * - provides a method to get an element by index and returns an std::optional<T>
 *    -- std::optional<T> filled with the value if index is valid
 *    -- std::nullopt if the index is invalid
 * - provides a method to query the used size (not current capacity)
 */


Is this class copiable/movable?

  

template<typename Type>
class MyVector {

public:
    MyVector() {
     	tail = 0;
        capacity = 1;
        buffer = make_unique<Type[]>(capacity);
    }

    explicit MyVector(std::size_t _capacity) : capacity(capacity) {
    	buffer = make_unique<Type[]>(capacity);
    	tail = 0;
    }

    virtual ~MyVector() noexcept {}

    void push_back(const Type& c) {
    
    	if (tail == capacity) {
        	capacity *= 2;
            std::unique_ptr<Type[]> temp = make_unique<Type[]>(capacity);
            std::copy(std::begin(buffer), std::end(buffer), temp);
        	std::swap(buffer, temp);
        }
    
    	buffer[tail] = c;
        tail++;
    }

    [[nodiscard]] std::optional<Type> operator[](std::size_t index) const {
    
    	if (index >= tail)
        	return std::nullopt;
        else
        	return buffer[index];
    }

    [[nodiscard]] std::size_t size() const noexcept {
    
    	return tail;
    }

private:
    std::unique_ptr<Type[]> buffer;
    int tail; 
    size_t capacity;
    
};

int main() {
    {
        MyVector<char> vec{10};

        vec.push_back('5');
        vec.push_back('6');
        vec.push_back('7');

        std::cout << "[0]: " << vec[0].value_or('0') << "\n";
        std::cout << "[1]: " << vec[1].value_or('0') << "\n";
        std::cout << "[20]: " << vec[20].value_or('_') << "\n";
    }

    return 0;
}
