Write a program to check whether a given number is even or odd.


bool isOdd(int number) {
	return number&0x01;
}




Write a function to return number of 1 bits in a positive integer.
 
Example:
 
Input:	n = 11
 
Output:	3




int num1bits(int n) {

	int acc = 0;
	while (n>0) {
		acc += n&0x01;
		n >>= 1;
	}

	return acc;
}



Given an array of integers nums and an integer target, return indices of two 
numbers such that they add up to the target.
Assumption: There is exactly one solution and not use the same element twice.
 
Example:
 
Input:	nums = [2,7,11,15] target = 9
 
Output:	[0,1]
 
Explanation:	Because nums[0] + nums[1] = 9, So we return [0,1]



pair<int,int> pairsearch(vector<int> vec, int target) {

	for (int a = 0; a<vec.length(); a++) {
		for (int b=a+1; b<vec.length();; b++) {
			if (vec[a]+vec[b] == target)
				return pair<int, int>(a, b);
		}
        }	
}





#pragma once



#ifndef HEADR_XYZ

#define  HEADR_XYZ

dsfsgdfhgf
gfdg
fgdf

#endif




#define max(a,b) (({a}<{b})?{b}:{a})

return (({x}<{y})?{y}:{z}) / 2;
