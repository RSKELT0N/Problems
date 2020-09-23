#include <iostream>
#include <vector>
using namespace std;

double m = 0;
double val;
double val2;
bool checkStraightLine(vector<vector<int>>& coordinates) {
    cin.tie(0);
    //Height of slope
    val = coordinates[1][1]-coordinates[0][1];
    //width of slope
    val2 = coordinates[1][0]-coordinates[0][0];
    //calculate the slope
    m = (val/val2);
    //calculate the interception
    double c = coordinates[0][1] - (m*coordinates[0][0]);

    //check interception for remaining nodes
    for(int i = 2; i < coordinates.size(); i++) {
        if((coordinates[i][1]-(m*coordinates[i][0]))!=c)
            //return false if node doesnt have same interception as first nodes;
            return false;
    }
    return true;
}

int main() {
    vector<vector<int>> plots = {
            {1,0},
            {2,2},
            {3,3}
    };
    cout << checkStraightLine(plots);
}
