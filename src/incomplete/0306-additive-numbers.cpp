#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Solution {
	public:
    	bool isAdditiveNumber(string num);
        
	private:

};

int getNumber(string &num, int start, int num_digits) {

	int result = 0;

	for(int i=0; i < num_digits; i++) {
		char tmp = num[(start+i)];
		int val = tmp - '0';
		result = (result*10) + val;
	}	

	return result;
}

bool Solution::isAdditiveNumber(string num) {

	int i=0, j=0, k=0;
	int len1=1, len2=1, len3=1;

	int first=0, second=0, third=0, target=0;

	for (i=0; (i + len1) < num.length(); i++) { 

		first = getNumber(num, i, len1);	
		cout << "first = " << first << endl;

		j = i + len1;
		len2 = len1;
		
		for( ; (j + len2) < num.length(); len2++) {
		
			second = getNumber(num, j, len2);
			cout << "second = " << second << endl;
			target = first + second;

			k = j + len2;
			// Attempt 1:
			// We use len2 because third number cant be less than second
			len3 = len2;
			third = getNumber(num, k, len3);
			cout << "third = " << third << endl;
			if (third == target) {
				break;	
			}		

			// Attempt 2:
			// We use (len2+1) because third number cant be less than second
			len3++;
			third = getNumber(num, k, len3);
			cout << "third = " << third << endl;
			if (third == target) {
				break;	
			}		

		}

		// Check to see if we could find the third number.
		if ((j + len2) >= num.length()) {
			return false;
		}

		// preparing for the next iteration.
		// We shift forward by 1 number
		len1 = len2;	
		i = j;
	}

	// Check to see if all the numbers have been absorbed.
	if (i < num.length()) {
		return false;
	}	

	return true;
}

int main(int argc, const char **argv) {

	string input("112358");
	Solution ans;

	bool output = ans.isAdditiveNumber(input);
	cout << "func(112358) = " << output << endl;
}
