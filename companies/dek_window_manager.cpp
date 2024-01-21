#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class WindowManager
{
private:
    std::vector<std::string> windows;
public:
    WindowManager() {
        windows.reserve(1000000);
    
    }
    void open(const std::string windowName)
    {
        windows.push_back(windowName);
    }

    void close(const std::string windowName)
    {
        std::vector<std::string>::iterator ptr = std::find(windows.begin(), windows.end(), windowName);
        // windows.erase(ptr);
        *ptr = "";
      
    }

    std::string getTopWindow()
    {
        while (windows.back() == "")
          windows.pop_back();
        return windows.back(); 
    }
};

#ifndef RunTests
int main()
{
    WindowManager wm;
    wm.open("Calculator");
    wm.open("Browser");
    wm.open("Player");
    wm.close("Browser");
    std::cout << wm.getTopWindow();
}
#endif
