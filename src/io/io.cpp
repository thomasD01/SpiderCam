#include "io.hpp"

IO::IO(const char* d1, const char* d2)
  :datei1(d1), datei2(d2), r1(), r2(), r3(), r4(), t(), x(), y(), z()
{

}

IO::~IO()
{
  datei1.close();
  datei2.close();
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
void IO::writeBuffer()
{
  for(auto _x:r1)
  {
    datei1 << _x;
  }
  datei1 << '\n';

  for(auto _x:r2)
  {
    datei1 << _x;
  }
  datei1 << '\n';

  for(auto _x:r3)
  {
    datei1 << _x;
  }
  datei1 << '\n';

  for(auto _x:r4)
  {
    datei1 << _x;
  }
  datei1 << '\n';

  for(auto _x:t)
  {
    datei2 << _x;
  }
  datei2 << '\n';

  for(auto _x:x)
  {
    datei2 << _x;
  }
  datei2 << '\n';

  for(auto _x:y)
  {
    datei2 << _x;
  }
  datei2 << '\n';

  for(auto _x:z)
  {
    datei2 << _x;
  }
  datei2 << '\n';
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
void IO::schreibeDaten(double time, double laengen[4], double position[3])
{
  t.push_back(time);

  r1.push_back(laengen[0]);
  r2.push_back(laengen[1]);
  r3.push_back(laengen[2]);
  r4.push_back(laengen[3]);

  x.push_back(position[0]);
  x.push_back(position[1]);
  x.push_back(position[2]);
}
void IO::init(int dimension[3], double laengen[4], int position[3])
{
  r1.push_back(laengen[0]);
  r2.push_back(laengen[1]);
  r3.push_back(laengen[2]);
  r4.push_back(laengen[3]);

  t.push_back(0);
  x.push_back(position[0]);
  y.push_back(position[1]);
  z.push_back(position[2]);

  datei2 << dimension[0] << ',' << dimension[1] << ',' << dimension[2] << '\n';
}
