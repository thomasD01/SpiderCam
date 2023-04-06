#ifndef __MATH_HPP__
#define __MATH_HPP__

#include <math.h>
#include <iostream>

namespace Math
{
  inline double berechneAbstand(int pos1[3], double pos2[3])
  {
    double diff1, diff2, diff3;

    diff1 = abs(pos1[0]-pos2[0]);
    diff2 = abs(pos1[1]-pos2[1]);
    diff3 = abs(pos1[2]-pos2[2]);

    return sqrt(diff1*diff1+diff2*diff2+diff3*diff3);
  }

  inline double berechneAbstand(double pos1[3], double pos2[3])
  {
    double diff1, diff2, diff3;

    diff1 = abs(pos1[0]-pos2[0]);
    diff2 = abs(pos1[1]-pos2[1]);
    diff3 = abs(pos1[2]-pos2[2]);

    return sqrt(diff1*diff1+diff2*diff2+diff3*diff3);
  }

  inline double berechneAbstand(int pos1[3], int pos2[3])
  {
    double diff1, diff2, diff3;

    diff1 = abs(pos1[0]-pos2[0]);
    diff2 = abs(pos1[1]-pos2[1]);
    diff3 = abs(pos1[2]-pos2[2]);

    return sqrt(diff1*diff1+diff2*diff2+diff3*diff3);
  }

  inline double berechneAbstand(double pos1[3], int pos2[3])
  {
    double diff1, diff2, diff3;

    diff1 = abs(pos1[0]-pos2[0]);
    diff2 = abs(pos1[1]-pos2[1]);
    diff3 = abs(pos1[2]-pos2[2]);

    return sqrt(diff1*diff1+diff2*diff2+diff3*diff3);
  }


  inline double laenge(double vec[3])
  {
    return sqrt(vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]);
  }
}

#endif
