#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        const int size = asteroids.size();
        stack<int> st;
        vector<int> vec;
        for(int i=0; i<size; ++i){
            if(asteroids[i]>0){
                // right
                st.push(asteroids[i]);
            }
            else{
                // left
                bool remain = true;
                if(st.empty()||st.top()<0 ){st.push(asteroids[i]);continue;}

                while(!st.empty()&&st.top()>0){
                    int temp = st.top();
                    if(temp>abs(asteroids[i]))
                    {remain=false;break;}
                    else if(temp==abs(asteroids[i])){
                        remain=false;
                        st.pop();
                        break;
                    }
                    else if(temp<abs(asteroids[i])){
                        st.pop();
                    }
                }
                if(remain)st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            vec.emplace(vec.begin(),st.top());
            st.pop();
        }
        return vec;
    }
};

int main(){
    vector<int> vec({-2,-2,1,-2});
    Solution s;
    vector<int> result = s.asteroidCollision(vec);
    int size = result.size();
    for(int i=0; i<size; ++i){
        cout<<result[i]<<" ";
    }
    system("pause");
    return 0;
}