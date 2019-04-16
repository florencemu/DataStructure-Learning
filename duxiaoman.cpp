#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run(vector<int>& path, int start, int end)
{
    for(int i = start; i < end;  i++) {
        path[i]++;
    }
}


int main(void)
{
    int times;
    
    cin >> times;
    
    vector<vector<int>> route(times, vector<int>(2, 0));
    for(int i = 0; i < times; i++) {
        cin >> route[i][0] >> route[i][1];
    }
    
    int endding = 0;
    for(auto i : route) {
        for(auto j : i) {
            endding = max(endding, j);
        }
    }
    
    vector<int> path(endding, 0);
    
    for(int i = 0; i < times; i++) {
        run(path, route[i][0], route[i][1]);
    }
    
    int max_ = 0;
    for(auto i : path) {
        max_ = max(max_, i);
    }
    
    cout << max_;
    
    return 0;
}
