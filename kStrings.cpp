#include <string>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int kSimilarity(string, string);       
    
    void swap(string&, int, int);
    
    bool getScore(string, string, std::vector<int>&, int&);
};


// That's actually string b!
void
Solution::swap(string &a, int i, int j)
{
    a[i] = a[i] xor a[j];
    a[j] = a[j] xor a[i];
    a[i] = a[i] xor a[j];
}


int
Solution::kSimilarity(string a, string b)
{
    cout << "Testing" << endl;
    int wrongCnt = 0;
    
    std::vector<int> mask;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            mask.push_back(i);
            wrongCnt++;
        }
    }
        
    int counter = 0;

    while (true) {
        cout << "We're in the while loop" << endl;
        if (getScore(a, b, mask, wrongCnt)) {
            break;
        } else {
            continue;
        }
    }
    
    return counter;
}


bool 
Solution::getScore(string a, string b, std::vector<int>& mask, int &wrongCnt)
{

    cout << "We're inside the getScore() function" << endl;

    int current;
    int currentBest = 0;
    cout << "Line 1" << endl;
    int bestIndices[2];
    cout << "Line 2" << endl;
    bool indicesMask[2];
    cout << "Line 3" << endl;

    for (int i = 0; i < wrongCnt; i++) {
        for (int j = i+1; j < wrongCnt; j++) {
            current = 0;
            if (a[mask[i]] == b[mask[j]]) {
                current++;
                indicesMask[0] = true;
                if (a[mask[j] == b[mask[i]]]) {
                    current++;
                    indicesMask[1] = true;
                } else {
                    indicesMask[1] = false;
                }
            } else {
                indicesMask[0] = false;
                if (a[mask[j]] == b[mask[i]]) {
                    current++;
                    indicesMask[1] = true;
                } else {
                    indicesMask[1] = false;
                }
            }
            if (current > currentBest) {
                currentBest = current;
                bestIndices[0] = i;
                bestIndices[1] = j;
            }
        }
    }

    swap(b, mask[bestIndices[0]], mask[bestIndices[1]]);

    if (currentBest == 1) {
        if (indicesMask[0]) {
            mask.erase(mask.begin() + bestIndices[0]);
        } else {
            mask.erase(mask.begin() + bestIndices[1]);
        }
    } else {
        mask.erase(mask.begin() + bestIndices[1]);
        mask.erase(mask.begin() + bestIndices[0]);
    }

    return (wrongCnt==0) ? true : false;
}

int main() {

    return 0;
}