#ifndef __KAMERA_H__
#define __KAMERA_H__

#include <iostream>
#include "../math/math.hpp"

class Kamera
{
private:
  int phase;
  int aMax;
  int vMax;
  double v;
  double phase2Len;
  double position[3];
  double aktuellesZiel[3];
  double naechstesZiel[3];
  double richtung[3];

public:
  Kamera(int position[3], int aMax, int vMax);
  ~Kamera();

  void setZiel(double ziel[3]);
  void abbrechen();
  void schritt(double t);
  double* getPos();
  double s(double t);

};

#endif
