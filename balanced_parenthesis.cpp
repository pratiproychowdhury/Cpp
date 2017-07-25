bool is_balanced(string expression) {

stack<char> brackets;

   for (int i=0; i<expression.size(); i++) {

        if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) {
                        brackets.push(expression[i]);
                        //cout << "Stacking " << expression[i] << "\n";
        }

        if (expression[i] == ')') {
                        if (brackets.empty())
                                return false;
                        if (brackets.top() == '(') {
                                brackets.pop();
                                //cout << "Popping (\n";
                        }
                        else {
                                //cout << "Looking for a ( in stack but not found. Found a " << brackets.top() << "\n";
                                return false;
                        }
        }

        if (expression[i] == ']') {
                        if (brackets.empty())
                                return false;
                        if (brackets.top() == '[') {
                                brackets.pop();
                                //cout << "Popping [\n";
                        }
                        else {
                                //cout << "Looking for a [ in stack but not found. Found a " << brackets.top() << "\n";
                                return false;
                        }
        }

        if (expression[i] == '}') {
                        if (brackets.empty())
                                return false;
                        if (brackets.top() == '{') {
                                brackets.pop();
                                //cout << "Popping {\n";
                        }
                        else {
                                //cout << "Looking for a { in stack but not found. Found a " << brackets.top() << "\n";
                                return false;
                        }
        }

}

if (brackets.empty())
        return true;

return false;
}


