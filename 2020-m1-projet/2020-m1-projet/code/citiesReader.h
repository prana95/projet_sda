#ifndef CITIES_READER
#define CITIES_READER

typedef struct ListOfCities ListOfCities;

struct ListOfCities
{
  int    number;
  char** name;
  int*   pop;
  float* lon;
  float* lat;
};

ListOfCities* citiesReader(int popMin);
void freeListOfCities(ListOfCities * cities);
double longueur_ville(double lon_a, double lat_a,double lon_b, double lat_b);

#endif
