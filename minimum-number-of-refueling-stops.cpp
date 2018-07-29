#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// A simple override for std::sort comparison function.        
bool comparisonKey(vector <int>& a, vector <int>& b) {return a[0] < b[0];}

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int> >& stations);

};


int
Solution::minRefuelStops(int target, int startFuel, vector <vector <int> >& stations)
{

    if (target <= startFuel)
        return 0;

    int idx, dist_covered, dist_best, gallons, stops, station_size;
    idx = dist_covered = gallons = stops = 0;
    int &fuelLeft = startFuel;
    bool flag = false;
    station_size = stations.size();


    // Sort them based on distances. O(nlgn)
    std::sort(stations.begin(), stations.end(), comparisonKey);

    while (dist_covered+fuelLeft < target && idx <= station_size) {
        cout << "idx: " << idx << endl;
        if (idx < station_size && stations[idx][0]-dist_covered<=fuelLeft) {
            cout << "outer most if : dist_best : " << dist_best << " : current : " << stations[idx][1] << endl;   
            if (stations[idx][1] > gallons) {
                cout << "first of first if" << " : idx: " << idx << endl;
                dist_best = stations[idx][0];
                gallons = stations[idx][1];
                flag = true;
            }
            idx++;
        } else {
            if (!flag)
                return -1;
            dist_covered += dist_best;
            fuelLeft += gallons - dist_best;
            gallons = 0;
            flag = false;
            cout << "inside the else. dist covered: " << dist_covered << " : fuel left : " << fuelLeft << endl;  
            stops++;
        }
    }
    return stops;
}



int
main()
{
    const int input_size = 10;
    const int target = 1000;
    const int start_fuel = 299;
    vector < vector <int> > input(input_size);
    input[0].push_back(13);
    input[0].push_back(21);
    input[1].push_back(26);
    input[1].push_back(115);
    input[2].push_back(100);
    input[2].push_back(47);
    input[3].push_back(225);
    input[3].push_back(99);
    input[4].push_back(299);
    input[4].push_back(141);
    input[5].push_back(444);
    input[5].push_back(198);
    input[6].push_back(608);
    input[6].push_back(190);
    input[7].push_back(636);
    input[7].push_back(157);
    input[8].push_back(647);
    input[8].push_back(255);
    input[9].push_back(841);
    input[9].push_back(123);

    int stops;
    Solution sol;
    stops = sol.minRefuelStops(target, start_fuel, input);        

    cout << "Stops: " << stops << endl;
    return 0;
}