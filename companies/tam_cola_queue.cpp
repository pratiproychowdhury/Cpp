Realice la implementación de una Cola utilizando como base la interface que se provee a continuación. Se deben implementar todos los métodos de la misma.

public interface Cola {
 // Agrega un elemento en la cola
 public void encolar(Object dato);

 // Devuelve el primer elemento disponible en la cola y reduce su tamaño en uno.
 public Object desencolar();
 
 // Verifica si la cola tiene elementos
 public boolean vacia();
}



#include <deque>

template <typename Object>
class Cola {
    
    int size;
    deque<Object>* cola;
    int capacity;
    
    public:
        Cola() : size(0), cola(new deque<Object>), capacity(0)  {
        }
        
        void encolar(Object dato) {
            if (size==capacity) {
                capacity += 1000;
                cola->reserve(capacity);
            }
            cola->push_back(dato);
            ++size;
        }
        
        Object desencolar() {
            --size;
            Object thisObject = cola->front();
            cola->pop_front();
            return thisObject;
        }
        
        bool vacia() {
            if (size)
                return false;
            else return true;
        }
        
        ~Cola() {
            delete[] cola;
        }
};
