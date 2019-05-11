/*
Given  arrays  of different sizes, find the number of distinct triplets  where  is an element of , written as , , and , satisfying the criteria: .

For example, given  and , we find four distinct triplets: .

Function Description

Complete the triplets function in the editor below. It must return the number of distinct triplets that can be formed from the given arrays.

triplets has the following parameter(s):

a, b, c: three arrays of integers .
Input Format

The first line contains  integers , the sizes of the three arrays. 
The next  lines contain space-separated integers numbering  respectively.

Constraints



Output Format

Print an integer representing the number of distinct triplets.

Sample Input 0

3 2 3
1 3 5
2 3
1 2 3
Sample Output 0

8 
Explanation 0

The special triplets are  .

Sample Input 1

3 3 3
1 4 5
2 3 3
1 2 3
Sample Output 1

5 
Explanation 1

The special triplets are 

Sample Input 2

4 3 4
1 3 5 7
5 7 9
7 9 11 13
Sample Output 2

12
Explanation 2

The special triplets are .
*/
int comparator;

bool isSmaller(int i) {

    return (i <= comparator);
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  auto ptr = unique(a.begin(), a.end());
  a.resize(distance(a.begin(), ptr));
  ptr = unique(b.begin(), b.end());
  b.resize(distance(b.begin(), ptr));
  ptr = unique(c.begin(), c.end());
  c.resize(distance(c.begin(), ptr));

  int triples = 0;
  vector<int>::const_iterator bstart = b.begin();
   for (vector<int>::const_iterator aptr = a.begin();
                               aptr != a.end(); aptr++) {

    while ((*aptr > *bstart) && (bstart != b.end()))
        bstart++;

    for (vector<int>::const_iterator bptr = bstart; bptr != b.end(); bptr++) {
        
       vector<int>::iterator cptr = c.end()-1;
       while (*cptr>*bptr)
        cptr--;
        triples += distance(c.begin(), cptr) + 1; 
    }
  }
  return triples;
}
