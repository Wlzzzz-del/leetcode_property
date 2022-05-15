// https://leetcode.cn/problems/largest-triangle-area/
/*
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
已知三角形的三边，可以使用海伦公式直接计算出三角形的面积，公式中三角形的面积S=√p(p-a)(p-b)(p-c)，其中p=（a+b+c），
a，b，c是三角形的三条边。
*/
#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

    double largestTriangleArea(std::vector<std::vector<int>>& points) {
        const int size = points.size();
        double ret=INT_MIN;
        for(int i=0; i<size; ++i){
            for(int j=i+1; j<size; ++j){
                for(int k=j+1; k<size; ++k){
                    ret= std::max(ret,triangleArea(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
                }
            }
        }
        return ret;
    }
};