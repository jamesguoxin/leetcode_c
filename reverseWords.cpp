#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
	void reverseWords(std::string &s) {
		size_t length = s.size();
		size_t index = 0;
		std::string tmp;
		s = reverseString(s);
		for (size_t i = 0; i < length; i++) {
			if (s[i] == ' ' || i == length - 1) {
				tmp = s.substr(index, i - index);
				tmp = reverseString(tmp);
				s.replace(index, i - index, tmp);
				index = i + 1;
			}
		}

	}

	std::string reverseString(std::string s) {
		size_t length = s.size();
		char tmp;
		if (length > 1) {
			if (length % 2 == 0) {
				for (size_t i = 0; i < length / 2; i++) {
					tmp = s[i];
					s[i] = s[length - 1 - i];
					s[length - 1 - i] = tmp;
				}
			} else {
				for (size_t i = 0; i < (length - 1) / 2; i++) {
					tmp = s[i];
					s[i] = s[length - 1 - i];
					s[length - 1 - i] = tmp;
				}
			}
		}
		return s;
	}
};
