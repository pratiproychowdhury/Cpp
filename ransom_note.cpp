bool ransom_note(vector<string> magazine, vector<string> ransom) {
    
	vector<string>::iterator word;
	multiset<string> dictionary;
	multiset<string>::iterator thisword;
    
	for (word=magazine.begin(); word!=magazine.end(); ++word)
    	dictionary.insert(*word);
	cout << dictionary.size() << "\n";
	for (word=ransom.begin(); word!=ransom.end(); ++word) {
    	cout << "looking for " << *word << "\n";
    	thisword = dictionary.find(*word);
    	if (thisword == dictionary.end())
        	return false;
    	dictionary.erase(thisword);
    	cout << dictionary.size() << "\n";
	}
	return true;
}
