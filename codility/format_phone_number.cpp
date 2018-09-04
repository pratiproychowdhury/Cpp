string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    string comma = ",";
    string space = " ";
    string dash = "-";
    string output;
    
    cout << "read in " << S << endl;
    
    size_t ptr = S.find(comma);
    while (ptr != string::npos) {
        S.erase(ptr, 1);
        ptr = S.find(comma);
    }
    
    ptr = S.find(space);
    while (ptr != string::npos) {
        S.erase(ptr, 1);
        ptr = S.find(space);
    }
    
    ptr = S.find(dash);
    while (ptr != string::npos) {
        S.erase(ptr, 1);
        ptr = S.find(dash);
    }
    
    cout << "after treating " << S << endl;
    
    int length = S.length();
    int blocks = length / 3;
    int remain = length % 3; // if break == 1, two blocks of 2, if == 1, one block
    
    if (!blocks)
        return S;
    
    int i;
    if (!remain) {
        for (i=0; i<blocks-1; i++)
            output.append(S.substr(i*3,3)+"-");
        output.append(S.substr(i*3,3));    
    }
    else if (remain==1) {
        for (i=0; i<blocks-1; i++)
            output.append(S.substr(i*3,3)+"-");
        output.append(S.substr(i*3,2)+"-"+S.substr(i*3+2,2));        
    }
    else {
        for (i=0; i<blocks-1; i++)
            output.append(S.substr(i*3,3)+"-");
        output.append(S.substr(i*3,3)+"-"+S.substr((i+1)*3,2));        
    }    
    cout << "final " << output << endl;
    return output;
}
