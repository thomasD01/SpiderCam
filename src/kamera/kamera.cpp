#include "kamera.hpp"

Kamera::Kamera(int pos[3], int amax, int vmax)
  :position(), aMax(amax), vMax(vmax), aktuellesZiel(), naechstesZiel(), richtung(), ta((double)vMax/(double)aMax), tb(), tc(), deltaS(), nDeltaS(), start()
{
  position[0] = (double) pos[0];
  position[1] = (double) pos[1];
  position[2] = (double) pos[2];

  start[0] = (double) pos[0];
  start[1] = (double) pos[1];
  start[2] = (double) pos[2];
}

Kamera::~Kamera()
{

}

void Kamera::setZiel(int ziel[3])
{
  // Kamera steht still
  if(phase == 0)
  {
    phase = 1;

    aktuellesZiel[0] = ziel[0];
    aktuellesZiel[1] = ziel[1];
    aktuellesZiel[2] = ziel[2];

    deltaS = Math::berechneAbstand(position, ziel);

    start[0] = position[0];
    start[1] = position[1];
    start[2] = position[2];

    berechneZiel();
  }
  // Kamera bewegt sich
  else 
  {
    naechstesZiel[0] = ziel[0];
    naechstesZiel[1] = ziel[1];
    naechstesZiel[2] = ziel[2];

    nDeltaS = Math::berechneAbstand(position, ziel);

    abbrechen();
  }

  richtung[0] = ziel[0] - position[0];
  richtung[1] = ziel[1] - position[1];
  richtung[2] = ziel[2] - position[2];

  double len = Math::laenge(richtung);

  richtung[0] /= len;
  richtung[1] /= len;
  richtung[2] /= len;

  std::cout << "Richtung: " << richtung[0] << ", " <<richtung[1] << ", " << richtung[2] << std::endl;

}
void Kamera::abbrechen()
{
  phase = 3;
}
void Kamera::schritt(double t)
{
  double _s = s(t);
  position[0] = start[0] + _s*richtung[0];
  position[1] = start[0] + _s*richtung[1]; 
  position[2] = start[0] + _s*richtung[2]; 

  std::cout << "Positionen: " << position[0] << ", " << position[1] << ", " << position[2] << std::endl;

}
double* Kamera::getPos()
{
  return position;
}

double Kamera::s(double t)
{
  if(phase==1)
  {
    if(t>=ta)
      phase=2;
    return aMax/2*t*t;
  }
  else if(phase==2)
  {
    if(t>=tb)
      phase=3;
    return aMax/2*ta*ta + vMax*(t-ta);
  }
  else if(phase==3)
  {
    if(t>=tc)
      phase=0;
    return deltaS - aMax/2*(t-tc)*(t-tc);
  }
  else 
  {
    phase = 0;
    aktuellesZiel[0] = naechstesZiel[0];
    aktuellesZiel[1] = naechstesZiel[1];
    aktuellesZiel[2] = naechstesZiel[2];

    deltaS = nDeltaS;

    start[0] = position[0];
    start[1] = position[1];
    start[2] = position[2];

    berechneZiel();

    return 0;
  }
}

bool Kamera::done()
{
  return phase == 0;
}

void Kamera::berechneZiel()
{
  double _s = aMax/2 * ta*ta;

  if(2*_s < deltaS)
  {
    _s = deltaS/2;

    ta = sqrt(_s/aMax*2);

    tb=ta;
    tc=ta;
  }
  else 
  {
    tb = ta +(deltaS - _s)/vMax;
    tc = tb+ta;
  }
}