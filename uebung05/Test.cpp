#include "MainWindow.hpp"
 
int main(int argc, char const *argv[])
{
    float test1[16] = { 1,2,3,4,
                        5,6,7,8,
                        9,10,11,12,
                        13,14,15,16};
    float test2[16] = { 1,2,3,4,
                        5,6,7,8,
                        9,10,11,12,
                        13,14,15,17};
 
    asteroids::Matrix tm1(test1);
    asteroids::Matrix tm2(test2);
    asteroids::Vector tv1(1,2,3);
    asteroids::Vector tv2(4,3,6);
    asteroids::Quaternion tq1(1,2,3,4);
    asteroids::Quaternion tq2(5,3,6,7);
 
    /*Matrix - Matrix Tests*/
    (tm1 + tm2).printMatrix();
    (tm1 - tm2).printMatrix();
    (tm1 * tm2).printMatrix();
    (tm1 += tm2).printMatrix();
    (tm1 -= tm2).printMatrix();
    (tm1 *= tm2).printMatrix();
    (tm1 = tm2).printMatrix();
    (tm1 * 5.0).printMatrix();
    (tm1 / 5.0).printMatrix();
    (tm1 *= 5.0).printMatrix();
    (tm1 /= 5.0).printMatrix();
 
    /*Vector - Vector Tests*/
    (tv1 * 5.0).print();
    (tv1 / 5.0).print();
    (tv1 + tv2).print();
    (tv1 - tv2).print();
    (tv1 += tv2).print();
    (tv1 -= tv2).print();
    (tv1 *= 5.0).print();
    (tv1 /= 5.0).print();
 
    /*Matrix - Vector Tests*/
    (tm1 * tv1).print();
 
    /*Quaternion Test*/
    (tq1 * tq2).print();
    (tq1 *= tq2).print();
    (tq1 * tv1).print();
    (tq1 *= tv1).print();
 
 
    return 0;
}