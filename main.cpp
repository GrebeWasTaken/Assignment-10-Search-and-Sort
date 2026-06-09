#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Region.h"

using namespace std;

//prints 1 region
void printRegion(const Region& r){
  cout << "ID: " << r.id << ", City: " << r.city << ", State: " << r.state << endl;
}

//helper prints 1st 5 regions
void printFirstFiveRegions(vector<Region>& regions){
  int amountToPrint = 5;

  if (regions.size() < 5){
    amountToPrint = regions.size();
  }

  for (int i = 0; i < amountToPrint; i++){
    printRegion(regions[i]);
  }
}


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

  inputFile.close();
}

int main()
{
  vector<Region> regions;

  cout << "-----------------------------Part 1----------------------------"
       << endl;
  
  readRegions(regions);

  cout << "First five regions:" << endl;
  printFirstFiveRegions(regions);

  cout << endl;
  cout << "-----------------------------Part 2----------------------------"
       << endl;
}
