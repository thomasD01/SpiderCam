#ifndef __IO_H__
#define __IO_H__

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


class IO
{
private:

  std::ofstream datei1;
  std::ofstream datei2;

  std::vector<double> r1, r2, r3, r4;
  std::vector<double> t, x, y, z;


public:
  IO(const char* d1, const char* d2);
  ~IO();

  void writeBuffer();
  void leseDaten(const char* eingabe, int* dim, int* start, int* vmax, int* amax, int* freq, std::vector<int*>& positionen);
  void schreibeDaten(double t, double laengen[4], double position[3]);
  void init(int dimension[3], double laengen[4], int position[3]);
};

#endif
