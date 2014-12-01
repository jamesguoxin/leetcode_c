#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:
	    bool wordBreak(std::string s, std::unordered_set<std::string> &dict) {
		    int length = s.size();
		    int record[length][length];
		    for (size_t i = 0; i < length; i++) {
			    for (size_t j = 0; j < length; j++) {
				    record[i][j] = 0;
			    }
		    }

		    for (size_t i = 0; i < length; i++) {
			    for (size_t len = 1; len <= length; len++) {
				    std::string tmp = s.substr(i, len);
				    if (dict.find(tmp) != dict.end()) {
					    record[i][len - 1] = 1;
				            if (i > 0 && record[0][i - 1]) {
                                                    record[0][i + len - 1] = 1;
				            } 
				    }
			    }
		    }
            }
}
