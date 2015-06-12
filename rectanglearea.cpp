#include <iostream>
#include <algorithm>

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int width_1 = C - A;
		int height_1 = D - B;
		int width_2 = G - E;
		int height_2 = H - F;
		int overlap = computeOverlap(A, B, C, D, E, F, G, H);

		return width_1*height_1 + width_2*height_2 - overlap;
	}

	int computeOverlap(int A, int B, int C, int D, int E, int F, int G, int H) {
		int overlap = 0;
		// Complete the code!!!!!!!!!!!
		overlap = std::max(std::min(C, G) - std::max(A, E), 0) * std::max(std::min(D, H) - std::max(B, F), 0); 
		return overlap;
	}

};


int main(int argc, char** argv) {
	// insert your code here
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	Solution s;
	int area = s.computeArea(A, B, C, D, E, F, G, H);
	std::cout << "The total area is " << area << std::endl;
	return 0;
}
