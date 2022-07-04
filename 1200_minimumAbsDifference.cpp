#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        const int size = arr.size();
        int min_gap = INT_MAX;
        for(int i=0; i+1<size; ++i){
            int gap = arr[i+1]-arr[i];
            if(gap<=min_gap){
                if(gap<min_gap){
                    min_gap = gap;
                    result.clear();
                }
                vector<int> temp;
                result.push_back({arr[i],arr[i+1]});
            }
        }
        return result;
    }
};