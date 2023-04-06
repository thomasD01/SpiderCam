#ifndef __SPIELFELD_H__
#define __SPIELFELD_H__

#include <stdlib.h>
#include <iostream>

#include "../kamera/kamera.hpp"
#include "../math/math.hpp"

class Spielfeld
{
private:
  int dimension[3];
  int befestigungen[3][4];
  Kamera kamera;

public:
  Spielfeld(int dimension[3], int position[3], int amax, int vmax);
  ~Spielfeld();

  void schritt(double t);
  void bewegeKamera(double position[3]);
  double* getLaengen();
};

#endif
