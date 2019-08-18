// Coding Problem #150 - Asked by LinkedIn
/* Coded by Krishnan Parameswaran */

// Given a list of points, a central point and an integer k, find the nearest k points from central point
// Example - [(2,3), (4,5), (7,8), (8,3)], (3,2), k=2

#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

int main(){

    vector < pair < int, int > > vect;                          // Vector of pairs declaration for the given points
    int arr[] = {2, 4, 7, 8};                                   // The points can be accepted in   
    int arr1[] = {3, 5, 8, 3};                                  // an interactive manner as well
    int n = sizeof(arr)/sizeof(arr[0]);
    const int k = 2;                                            // Number of nearest points to be found

    for (int i=0; i<n; i++) 
    vect.push_back(std::make_pair(arr[i],arr1[i]) );            // Vector of pairs creation/definition

    for (int i=0; i<n; i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " "
             << vect[i].second << " " << endl; 
    } 
    
    pair <int, int> pt = std::make_pair(3, 2);                  // Pair containing coordinates of central point

    int dist[n];
    int min_dist[k];
    int id[k];

    for (int i=0; i<k; i++){
        min_dist[i] = INT_MAX;                                  // k nearest distances initialized to maximum value
    }

    for (int i=0; i<n; i++){                                    // Distance calculation
        dist[i] = sqrt(pow((vect[i].first - pt.first),2) + pow((vect[i].second - pt.second),2));
        for (int j=0; j<k; j++){
            if (dist[i] < min_dist[j]){
                id[j] = i;                                      // Tracking the index of points in the vector
                min_dist[j] = dist[i];                          // Finding k nearest distances
                break;
            } 
        }                 
    }

    cout << "The " << k << " closest points to (" << pt.first << ", " << pt.second << ") are [ " ;
    for (int i=0; i<k; i++){
        cout << "(" << vect[id[i]].first << ", " << vect[id[i]].second << ") " ;
    }
    cout << "]" << endl;

    return 0; 
}


