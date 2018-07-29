#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H);
};


int
Solution::minEatingSpeed(vector <int>& piles, int H)
{
    int size, offset, magic_number, i, speed;

    // sort the piles. max-heap might be a good idea too, but i'm lazy.
    std::sort(piles.begin(), piles.end());

    size = piles.size();
    offset = H - size;

    // we want the magic number to become zero.
    i = size - offset - 1;
    speed = piles[i];

    while (i < size) {
        
    }    


}




int
main()
{

    vector <int> test;
    int testarr[] = {30,11,23,4,20};

    for (int i = 0; i < 5; i++) {
        test.push_back(testarr[i]);
    }

    Solution sol;
    int bandana = sol.minEatingSpeed(test, 6);

    cout << "Bandanas per hour: " << bandana << endl;

}