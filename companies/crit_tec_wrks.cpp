// exchange: 1g = 100s e 1s=100b
// sample: 0g,0s,204b -> 0g,2s,4b
void cashConverter(int g,int s, int b)
{

	long units = b + 100*s + 10000*g;
	
	cout << units / 10000 << " in gold " << (units/100)%100 << " in silver " << units%100 << " in bronze\n";
}



// imprimir o numero de vogais, .ie, AAEIOU imprime 2,1,1,1,1
void countVowels(string s)
{
	string letterstocount = "AEIOU";
	map<char,int> letters;
	for (const char & a : s)
		if (letterstocount.find(a) != string::npos)
			letters[a]++;
	for (auto& a : letterstocount)
		cout << letters[a] << ",";
}
