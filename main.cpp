#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Region.h"

using namespace std;




//part 1
void readRegions(vector<Region>& regions){
  ifstream inputFile("ZILLOW_REGIONS.csv");

  string line;

  while (getline(inputFile, line)){
    if (line != ""){
      Region r = parseRegion(line);
      regions.push_back(r);
    }
  }
}

int main()
{
  vector<Region> regions;

  cout << "-----------------------------Part 1----------------------------"
       << endl;
  
  readRegions(regions);



}
