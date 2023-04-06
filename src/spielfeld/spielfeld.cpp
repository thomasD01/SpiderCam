#include "spielfeld.hpp"

Spielfeld::Spielfeld(int dim[3], int position[3], int amax, int vmax)
  :dimension(), befestigungen(), kamera(position, amax, vmax)
{

  dimension[0] = dim[0];
  dimension[1] = dim[1];
  dimension[2] = dim[2];

  befestigungen[0][0] = 0;
  befestigungen[0][1] = 0;
  befestigungen[0][2] = dimension[2];
  befestigungen[1][0] = 0;
  befestigungen[1][1] = dimension[1];
  befestigungen[1][2] = dimension[2];
  befestigungen[2][0] = dimension[0];
  befestigungen[2][1] = 0;
  befestigungen[2][2] = dimension[2];
  befestigungen[3][0] = dimension[0];
  befestigungen[3][1] = dimension[1];
  befestigungen[3][2] = dimension[2];
}
Spielfeld::~Spielfeld()
{

}
void Spielfeld::schritt(double t)
{
  kamera.schritt(t);
}
void Spielfeld::bewegeKamera(double position[3])
{
  kamera.setZiel(position);
}
double* Spielfeld::getLaengen()
{
  double* position = kamera.getPos();

  static double laengen[4]{};

  for(size_t i=0;i<4; ++i)
  {
    laengen[i] = Math::berechneAbstand(befestigungen[i], position);
  }

  return laengen;
}
