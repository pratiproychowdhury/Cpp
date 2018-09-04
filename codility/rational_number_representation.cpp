#include <sstream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
    double result = double(A)/double(B);
    stringstream ss;
    ss << result;
    string rep = ss.str();
    
    size_t pos = rep.find('.');
    if ((pos != string::npos) && ((rep.length()-pos)>5)) {
        const char digit = rep[pos+1];
        unsigned int i;
        for (i=pos+1; i<rep.length(); i++) {
            if (rep[i] != digit)
                break;
        }

        if (i==rep.length()) {
            rep[pos+1] = '(';
            rep[pos+3] = ')';
            rep.erase(pos+4, string::npos);
        }
    } 

    return rep;
}
