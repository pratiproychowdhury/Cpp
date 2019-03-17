#include <set>
#include <algorithm>

int walk(tree* root, set<int> values) {
    values.insert(root->x);
    
    if (root->l==NULL) {
        if (root->r==NULL)
            return values.size();
        else return walk(root->r, values);
    }
    
    if (root->r==NULL)
        return walk(root->l, values);
    
    return max(walk(root->l, values), walk(root->r, values));
}

int solution(tree * T) {
    set<int> val;
    if (T==NULL)
        return 0;
    
    return walk(T, val);
}
