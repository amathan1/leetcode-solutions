#include <iostream>
#include <cstdlib>

using namespace std;

class Solution 
{
public:
    int primePalindrome(int N);

    bool isPalindrome(int N);

    bool isPrime(int N);

    int binomialCoefficient(int n, int r);
};

bool
Solution::isPalindrome(int N)
{
    string n = to_string(N);
    size_t leng = n.length();

    for (size_t i = 0; i < leng/2; i++) {
        if (n[i] == n[leng-i-1])
            return false;
    }

    return true;
}


bool 
Solution::isPrime(int N)
{
    /*
     * Using the AKS test for primes (https://www.youtube.com/watch?v=HvMSRWTE2mI)  
     * Tests can be done on-the-fly to constrain memory usage
     * Just test whether the co-efficients are divisible by the prime number and we're set.
     */

    int powerOfA, powerOfB, nCr; // Power of B doesn't matter.
    for (int k = 1; k < N; k++) {
        nCr = binomialCoefficient(N, k);
        powerOfA = (N-k);
        if (nCr % N != 0) return false;
    }
    return true;
}


int
Solution::binomialCoefficient(int n, int r)
{
    if (r == 0 || n == r)
       return 1;

    return binomialCoefficient(n-1, r-1) + binomialCoefficient(n-1, r);   
}



int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().primePalindrome(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}