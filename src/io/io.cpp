#include "io.hpp"

IO::IO(const char* d1, const char* d2)
  :datei1_in(d1), datei1_out(d1), datei2_in(d2), datei2_out(d2)
{}

IO::~IO()
{
  datei1_in.close();
  datei1_out.close();
  datei2_in.close();
  datei2_out.close();
}


void getValuesFromString(std::string data, size_t count, int *out, size_t start=1)
{
  size_t a=0, b=0;

  if(start == 0)
  {
    b = data.find(' ');

    out[0] = atoi(data.substr(a, b-a+1).c_str());
  }

  for(size_t i = start==0?1:0; i<count; ++i)
  {
    a = data.substr(b).find(' ') + b;
    b = data.substr(a+1).find(' ') + a;
    out[i] = atoi(data.substr(a, b-a+1).c_str());
  }
}


void IO::leseDaten(const char* eingabe, int* dim, int* start, int* vmax, int* amax, int* freq, std::vector<int*>& positionen)
{
  int *out = (int*) malloc(4*sizeof(int));
  size_t index = 0;
  std::string data;
  std::ifstream datei;

  datei.open(eingabe, std::ios::in);

  if(!datei)
  {
    throw std::runtime_error("Could not open file");
  }

  //erste Zeile für dim
  std::getline(datei, data);

  if(data[0] == '#')
  {
    std::getline(datei, data);
  }
  
  getValuesFromString(data, 3, dim);

  //zweite Zeile für start
  std::getline(datei, data);
  getValuesFromString(data, 3, start);

  //dritte Zeile für vmax
  std::getline(datei, data);
  getValuesFromString(data, 1, vmax);

  //vierte Zeile für amax
  std::getline(datei, data);
  getValuesFromString(data, 1, amax);

  //fünfte Zeile für freq
  std::getline(datei, data);
  getValuesFromString(data, 1, freq);

  //sechste bis letzte zeile für positionen
  while(std::getline(datei, data))
  {
    getValuesFromString(data, 4, out, 0);
    positionen.push_back(out);
  }
}
void IO::schreibeDaten(double t, double laengen[4], double position[3])
{
  
}
void IO::init(int dimension[3], double laengen[4], double position[3])
{

}
