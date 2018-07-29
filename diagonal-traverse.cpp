#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
};


vector<int>
Solution::findDiagonalOrder(vector<vector<int>>& matrix)
{
 
    // go up if flip_bit is true or down if false
    bool flip_bit = true;
    int x = 0, y = 0, i = 0;
    int y_max = matrix.size();
    if (y_max==0) {
        vector <int> temp;
        return temp;
    }
    int x_max = matrix[0].size();
    
    // int should be safe as the total number of elements won't exceed 10000
    int size_flat = x_max*y_max;
    vector <int> flat(size_flat);

    while (i < size_flat) {
        
        if (flip_bit) {
                flat[i] = matrix[y][x];
                if (x==x_max-1 || y==0) {
                    (x==x_max-1)?y++:x++;i++;
                    flip_bit = !flip_bit;
                    continue;
                }
                x++; y--; i++;

        } else {    

                flat[i] = matrix[y][x];

                if (y==y_max-1 || x==0) {
                    (y==y_max-1)?x++:y++;i++;
                    flip_bit = !flip_bit;
                    continue;
                }
                x--; y++; i++;
        }   
    }
    return flat;
}





int
main()
{
    int y = 5, x = 5;

    vector < vector <int> > mat(y);
    vector <int> out;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            mat[i].push_back(i+j+1);
            cout << i+j+1 << " ";
        }
        cout << endl;
    }

    Solution sol;
    out = sol.findDiagonalOrder(mat);

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}