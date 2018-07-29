#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:

    int getChunkSize(vector <int>& arr, int idx, const int total);

    int maxChunksToSorted(vector<int>& arr);


private:
    int numPossible;
};


int
Solution::getChunkSize(vector <int>& arr, int idx, const int total)
{
    // we start with chunk_size 2 and we want the magic number to be 0.
    int chunk_size = 2;
    int magic_number = chunk_size;
    int counter = idx, limit = idx+chunk_size;

    // we assume max(arr) < len(arr)
    while (counter < chunk_size) {
        if (arr[idx]>limit) {
            chunk_size++;
            limit++;
            continue;
        }
        counter++;
        magic_number--;
    }
    // assert(magic_number==0);
    return chunk_size;
}



int
Solution::maxChunksToSorted(vector <int>& arr)
{

    // idx will go out of bounds.
    const int total = arr.size()-1;
    // stupid counter since we don't need to store the chunks.
    int idx = 0, count = 0;
    // whatever the current chunk_size is, if > 1.
    int chunk_size;
    
    while (idx <= total) {
        if (arr[idx] == idx) {
            idx++;
            count++;
            continue;
        }
        chunk_size = getChunkSize(arr, idx, total);
        idx += chunk_size;
        count++;
    }
    // assert(count <= total+1);
    return count;
}



int main() {

    Solution sol;
    vector <int> arr;
    int crap[] = {1,0,2,3,4};

    for (int i = 0; i < 5; i++) {
        arr.push_back(crap[i]);
    }

    cout << sol.maxChunksToSorted(arr);    
    
    return 0;
}