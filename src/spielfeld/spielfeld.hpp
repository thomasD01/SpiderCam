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
  int befestigungen[4][3];
  Kamera kamera;

public:
  Spielfeld(int dimension[3], int position[3], int amax, int vmax);
  ~Spielfeld();

  void schritt(double t);
  void bewegeKamera(int position[4]);
  double* getLaengen();
  double* getPos();
  bool done();
};

#endif
