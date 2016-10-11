#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cctype>

#include <set>
using std::set;

class Solution {
	public:
		bool isNumber(string s);

	private:
		bool isInteger(string, int start, int end, bool lead_ws, bool trail_ws);
		bool isDecimal(string, int start, int end, bool lead_ws, bool trail_ws);
		bool isExponent(string);
		bool isDecimalExponent(string);
};

typedef enum {
	has_exponent,
	has_alphabet,	
	has_decimal,
	has_digits,
	has_unknown,
} c_types ;


bool Solution::isInteger(string s, int start, int end, bool lead_ws, bool trail_ws) {

	int i = start;
	bool found_digit = false;

	// Skip leading white-space.
	for ( ; i < end; i++) {
		char c = s[i];

		if (isspace(c)) {
			// continue skipping.
			//
		} else if (isdigit(c)) {
			break;

		} else {
			// Not expecting any other character. Return false.
			return false;
		}
	}

	// If leading whitespace is NOT allowed and whitespace exists, return
	// false.
	if (!lead_ws && (i != start)) {
		return false;
	}

	// Make sure that next set of characters is an integer.
	for ( ; i < end; i++) {
		char c = s[i];
	
		if (isdigit(c)) {
			// Check succeded. Skip.
			found_digit = true;

		} else if (isspace(c)) {
			// Encountered space. Might be part of trailing whitespace. 
			// Break out.
			break;

		} else {
			// Not expecting anything other than a digit. Return false;
			return false;
		}
	}

	// If trailing whitespace is NOT allowed and we encountered white-space,
	// return false
	if (!trail_ws && (i != end)) {
		return false;
	}

	// Check trailing white-space.
	for ( ; i < end; i++) {
		char c = s[i];

		if (isspace(c)) {
			// continue skipping.

		} else {
			// Not expecting any other character. Return false.
			return false;
		}
	}

	// Note that this is an integer ONLY if we found atleast one digit.
	return found_digit;
}

bool Solution::isDecimal(string s, int start, int end, bool lead_ws, bool trail_ws) {

	int dec_pos = s.find_first_of('.', start);

	// If decimal position is after end, return false;
	if (dec_pos >= end) {
		return false;
	}

	// Verify first part is an integer.
	// Note that we allow leading space, but NOT trailing space.
	bool full_int = isInteger(s, start, dec_pos, lead_ws, false);

	// Verify second part is an integer.
	// TODO: Is this condition right?? Is just whitespace ok??
	// NOTE that we disallow both leading and trailing space.
	bool fraction_int = isInteger(s, (dec_pos+1), end, false, trail_ws);

	return (full_int && fraction_int);
}

bool Solution::isExponent(string s) {
	int exponent_pos = s.find_first_of("eE", 0);
	
	// No exponent found. Return false.
	if (exponent_pos == string::npos) {
		return false;
	}

	bool mantissa_int = isInteger(s, 0, exponent_pos, true, false);
	bool exponent_int = isInteger(s, (exponent_pos + 1) , s.size(), false, true);

	return (mantissa_int && exponent_int);
}

bool Solution::isDecimalExponent(string s) {
	int exponent_pos = s.find_first_of("eE", 0);
	
	// No exponent found. Return false.
	if (exponent_pos == string::npos) {
		return false;
	}

	bool mantissa_decimal = isDecimal(s, 0, exponent_pos, true, false);
	bool exponent_int = isInteger(s, (exponent_pos + 1) , s.size(), false, true);

	return (mantissa_decimal && exponent_int);
}

bool Solution::isNumber(string s) {

	if (s.empty()) {
		return false;
	}

	bool result = false;
	set<c_types> type_set;
	
	// Space is not allowed. No character other than numbers e/E/.
	for(int i=0; i < s.size(); i++) {
		char c = s[i];

		if (isdigit(c))	{
			type_set.insert(has_digits);

		} else if (( c == 'e') || (c == 'E')) {
			// Note that this check must be before generic alphabet check.
			type_set.insert(has_exponent);

		} else if (isalpha(c)) {
			type_set.insert(has_alphabet);

		} else if (c == '.') {
			type_set.insert(has_decimal);

		} else if (isspace(c)) {
			// Skip whitespace (since leading and trailing whitespace are ok)

		} else {
			type_set.insert(has_unknown);
		}
	}

	// Perform checks for things that are not allowed.
	if (	type_set.count(has_alphabet) || 
			type_set.count(has_unknown) || 
			(type_set.count(has_digits) == 0)
		) {
		return false;
	}

	if (type_set.count(has_exponent) && type_set.count(has_decimal)) {
		result = isDecimalExponent(s);

	} else if (type_set.count(has_exponent)) {
		result = isExponent(s);

	} else if (type_set.count(has_decimal)) {
		result = isDecimal(s, 0, s.size(), true, true);

	} else {
		// Must be an integer;
		result = isInteger(s, 0, s.size(), true, true);
	}

	// Determine type of number and perform checks based on type
	// - Integer
	// - Non-Exponent Floating Point
	// - Exponent Floating Point without decimal
	// - Exponent Floating Point with Decimal
	
	return result;
}

int main(int argc, const char **argv) {

	Solution ans;

	// Integer checks.
	cout << endl << "Integer checks" << endl;
	cout << "isNumber(1) = " << ans.isNumber("1") << endl;
	cout << "isNumber(11) = " << ans.isNumber("11") << endl;
	cout << "isNumber( 11) = " << ans.isNumber(" 11") << endl;
	cout << "isNumber(11 ) = " << ans.isNumber("11 ") << endl;
	cout << "isNumber( 11 ) = " << ans.isNumber(" 11 ") << endl;
	cout << "isNumber( 1 1 ) = " << ans.isNumber(" 1 1 ") << endl;
	cout << "isNumber( 1x1 ) = " << ans.isNumber(" 1x1 ") << endl;
	cout << "isNumber( 11 x ) = " << ans.isNumber(" 11 x ") << endl;
	cout << "isNumber( x 11 ) = " << ans.isNumber(" x 11 ") << endl;

	// Decimal checks
	cout << endl << "Decimal Checks" << endl;
	cout << "isNumber(1.0) = " << ans.isNumber("1.0") << endl;
	cout << "isNumber(11.0) = " << ans.isNumber("11.0") << endl;
	cout << "isNumber(11.00) = " << ans.isNumber("11.00") << endl;
	cout << "isNumber( 11.00 ) = " << ans.isNumber(" 11.00 ") << endl;
	cout << "isNumber(.1100) = " << ans.isNumber(".1100") << endl;
	cout << "isNumber(11.) = " << ans.isNumber("11.") << endl;
	cout << "isNumber(11.00.) = " << ans.isNumber("11.00.") << endl;
	cout << "isNumber(x11.00) = " << ans.isNumber("x11.00") << endl;
	cout << "isNumber(11.0x0) = " << ans.isNumber("11.0x0") << endl;
	cout << "isNumber(11 .00) = " << ans.isNumber("11 .00") << endl;
	cout << "isNumber(11. 00) = " << ans.isNumber("11. 00") << endl;

	// Exponent checks.
	cout << endl << "Exponent Checks" << endl;
	cout << "isNumber(1E1) = " << ans.isNumber("1E1") << endl;
	cout << "isNumber(1e1) = " << ans.isNumber("1e1") << endl;
	cout << "isNumber(11e1) = " << ans.isNumber("11e1") << endl;
	cout << "isNumber(11e11) = " << ans.isNumber("11e11") << endl;
	cout << "isNumber( 11e11 ) = " << ans.isNumber(" 11e11 ") << endl;
	cout << "isNumber( 11 e11 ) = " << ans.isNumber(" 11 e11 ") << endl;
	cout << "isNumber( 11e 11 ) = " << ans.isNumber(" 11e 11 ") << endl;
	cout << "isNumber( 11e1x1 ) = " << ans.isNumber(" 11e1x1 ") << endl;
	cout << "isNumber( x 11e11 ) = " << ans.isNumber(" x 11e11 ") << endl;
	
	
	// TODO: Decimal exponent checks.
	cout << endl << "Decimal Exponent Checks" << endl;
	cout << "isNumber(1.0E1) = " << ans.isNumber("1.0E1") << endl;
}
