#include <iostream>
#include <vector>

#include "io/io.hpp"
#include "spielfeld/spielfeld.hpp"

#define OUTPUT1 "./data/out1.csv"
#define OUTPUT2 "./data/out2.csv"
#define INPUT   "./data/input.dat"

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

    io.init(dim, laengen, start);

    double t=0;
    size_t id=0;

    while(!(id == positionen.size() && spielfeld.done()))
    {
      if(id<positionen.size()-1 && positionen[id+1][0] == t){
        ++id;

        int _pos[3] = {positionen[id][1],positionen[id][2],positionen[id][3]};

        spielfeld.bewegeKamera(_pos);
      }
      else
      {
        t += 1.0/freq;
        spielfeld.schritt(t);
        io.schreibeDaten(t, spielfeld.getPos(), spielfeld.getLaengen());
      }
    }

    io.writeBuffer();
  }
  catch(const std::exception& e)
  {
    std::cerr << "error: " << e.what() << '\n';
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
