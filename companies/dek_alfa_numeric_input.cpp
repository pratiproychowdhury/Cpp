#include <iostream>
#include <string>

class TextInput
{
protected:
  std::string text;
  
public:
    virtual void add(char c) { text += c; }
    std::string getValue() { return text; }
};

class NumericInput : public TextInput { 

    void add(char c) { 
      if (('0' <= c) && (c <= '9'))
        text += c;
    }
};

int main() {
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
