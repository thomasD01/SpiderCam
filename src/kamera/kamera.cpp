#include "kamera.hpp"

Kamera::Kamera(int pos[3], int amax, int vmax)
  :position(), aMax(amax), vMax(vmax), aktuellesZiel(), naechstesZiel(), richtung()
{
  position[0] = (double) pos[0];
  position[1] = (double) pos[1];
  position[2] = (double) pos[2];
}

Kamera::~Kamera()
{

}

void Kamera::setZiel(double ziel[3])
{
  // Kamera steht still
  if(phase == 0)
  {
    aktuellesZiel[0] = ziel[0];
    aktuellesZiel[1] = ziel[1];
    aktuellesZiel[2] = ziel[2];

    richtung[0] = ziel[0] - position[0];
    richtung[1] = ziel[1] - position[1];
    richtung[2] = ziel[2] - position[2];

    double len = Math::laenge(richtung);

    richtung[0] /= len;
    richtung[1] /= len;
    richtung[2] /= len;
  }
  // Kamera bewegt sich
  else 
  {
    naechstesZiel[0] = ziel[0];
    naechstesZiel[1] = ziel[1];
    naechstesZiel[2] = ziel[2];
    abbrechen();
  }
}
void Kamera::abbrechen()
{
  phase = 3;
}
void Kamera::schritt(double t)
{
  double deltaS = s(t);
  position[0] += deltaS*richtung[0]; 
  position[1] += deltaS*richtung[1]; 
  position[2] += deltaS*richtung[2]; 
}
double* Kamera::getPos()
{
  return position;
}

double Kamera::s(double t)
{

}