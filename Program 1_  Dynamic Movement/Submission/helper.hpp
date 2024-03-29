#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <vector>
#include <math.h>
//define global variables
#define PI  3.1416
#define MIN_VEL 0.02

using namespace std;

typedef float rad;
//define coordinate structure with x and z
//this will serve as vector
//also has a function for normalize
struct Coord{
    float x, z;
    void normalize(){
        float mod = sqrt(abs(x*x) + abs(z*z)); 

        if (mod == 0){
            x = 0;
            z = 0;
            return;
        }

        x = x/mod;
        z = z/mod;
    }
};
//function to find the length of a vector
float mod(Coord &a){
    return sqrt(a.x*a.x + a.z*a.z);
}
//redefine operators to make operations easier to perform
inline Coord operator+(Coord const &a, Coord const &b){
    Coord res;
    res.x = a.x + b.x;
    res.z = a.z + b.z;

    return res;
}

inline Coord operator-(Coord const &a, Coord const &b){
    Coord res;
    res.x = a.x - b.x;
    res.z = a.z - b.z;

    return res;
}

inline Coord operator*(Coord const &a, float scalar){
    Coord res;
    res.x = a.x * scalar;
    res.z = a.z * scalar;

    return res;
}

inline Coord operator/(Coord const &a, float scalar){
    Coord res;
    res.x = a.x / scalar;
    res.z = a.z / scalar;

    return res;
}

//collection of behaviors
enum SteeringBehavior {
    CONTINUE = 1,
    SEEK = 6,
    FLEE = 7,
    ARRIVE = 8
};

float distancePointPoint(Coord A, Coord B){
    float a2, b2;
    a2 = (B.x - A.x) * (B.x - A.x);
    b2 = (B.z - A.z) * (B.z - A.z);
    return sqrt(a2 + b2);
}


struct Path{
    int id;
    vector<Coord> points;
    vector<float> distance;
    vector<float> param;
    float segments;
};
/*
Path assemblePath(vector<Coord> p, int i){
    Path path;
    path.id = i;
    path.points = p;
    path.segments = path.points.size() - 1;
    
    path.distance.push_back(0);
    path.param.push_back(0);

    for(int i = 1; i < path.segments + 1; i++){
        float dis = distancePointPoint(path.points[i - 1], path.points[i]);
        path.distance.push_back(dis + path.distance[i - 1]); 
    }


    return path;
}*/

#endif