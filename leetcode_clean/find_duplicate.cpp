#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int findDuplicate(vector<int>& nums) {
		int size = nums.size();
		//cout << "The size is " << size << endl;
		int l = 1, h = size - 1, mid, counter;

		while(l < h){
			mid = (l + h) / 2;
			counter = 0;
			//cout << "The mid is " << mid << endl;
			for (int i=0; i < size; ++i) {
				if (nums[i] <= mid) {
					counter += 1;
				}
			}
			cout << "The counter is " << counter << endl;
			if (counter > mid){
				h = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};

int main(int argc, char ** argv) {
	vector<int> test = {2, 1, 1};
	Solution s;
	int d = s.findDuplicate(test);
	cout << d << endl;
	return d;
}
