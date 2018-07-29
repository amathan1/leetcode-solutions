#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n);
    int backtrack(int i, int j, int &m, int &n, int &paths);
};


int
Solution::uniquePaths(int m, int n) 
{
    int paths = 0;
    return backtrack(1, 1, m, n, paths);
}

// build a state space tree and parse it to find the combinations
int 
Solution::backtrack(int i, int j, int &m, int &n, int &paths)
{
    if (i==m && j==n) {
        paths++;
        return paths;
    }

    // try going right
    if (m-i>=1) {
        backtrack(i+1, j, m, n, paths);
    }

    // try going down
    if (n-j>=1) {
        backtrack(i, j+1, m, n, paths);
    }

    return paths;
}



int
main()
{
    int m = 23;
    int n = 12;
    Solution sol;
    int paths = sol.uniquePaths(m, n);
    cout << "Number of possible paths: " << paths << endl;

    return 0;
}