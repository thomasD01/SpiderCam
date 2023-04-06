#include <iostream>
#include <vector>

#include "io/io.hpp"
#include "spielfeld/spielfeld.hpp"

#define OUTPUT1 "../data/out1.csv"
#define OUTPUT2 "../data/out2.csv"
#define INPUT   "../data/input.dat"

int main(int argc, char **argv)
{
  int vmax;
  int amax;
  int freq;
  int dim[3];
  int start[3];
  std::vector<int*> positionen{};

  IO io{OUTPUT1, OUTPUT2};

  try
  {
    io.leseDaten(INPUT, dim, start, &vmax, &amax, &freq, positionen);

    Spielfeld spielfeld{dim, start, amax, vmax};

    double* laengen = spielfeld.getLaengen();

    std::cout << "laengen: ";

    for(size_t i=0; i<4; ++i)
    {
      std::cout << laengen[i] << " ";
    }
    std::cout << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "error: " << e.what() << '\n';
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
