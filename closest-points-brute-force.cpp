#include <bits/stdc++.h>
using namespace std;
struct Point 
{
    int x, y; 
};

float dist(Point p1, Point p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                (p1.y - p2.y)*(p1.y - p2.y) 
            ); 
} 

float min(float x, float y) 
{ 
    return (x < y)? x : y; 
} 

float bruteForce(Point P[], int n) 
{ 
    float min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 
int main() 
{ 
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]); 
    cout << "The smallest distance is " << bruteForce(P, n); 
    return 0; 
} 
