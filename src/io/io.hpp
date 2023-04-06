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
  std::ifstream datei1_in;
  std::ifstream datei2_in;

  std::ofstream datei1_out;
  std::ofstream datei2_out;

public:
  IO(const char* d1, const char* d2);
  ~IO();

  void leseDaten(const char* eingabe, int* dim, int* start, int* vmax, int* amax, int* freq, std::vector<int*>& positionen);
  void schreibeDaten(double t, double laengen[4], double position[3]);
  void init(int dimension[3], double laengen[4], double position[3]);
};

#endif
