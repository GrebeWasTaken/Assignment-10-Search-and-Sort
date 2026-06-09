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

//part 2
void selectionSort(vector<Region>& regions){
  for (int i = 0; i < static_cast<int>(regions.size()) - 1; i++){
    int minIndex = i;

    for (int j = i + 1; j < static_cast<int>(regions.size()); j++){
      if (regions[j].id < regions[minIndex].id){
        minIndex = j;
      }
    }
    swap(regions[i], regions[minIndex]);
  }
}

//part 3 helpers
bool comesBeforeByCity(const Region& a, const Region& b){
  if (a.city < b.city){
    return true;
  } else if(a.city > b.city){
    return false;
  }

  //tie breaker
  if (a.state < b.state){
    return true;
  } else if(a.state > b.state){
    return false;
  }

  return a.id < b.id;
}

void mergeByCity(vector<Region>& regions, int start, int mid, int end){
  vector<Region> temp;

  int left = start;
  int right = mid + 1;

  while (left <= mid&& right <= end){
    if (comesBeforeByCity(regions[left], regions[right])){
      temp.push_back(regions[left]);
      left++;
    } else{
      temp.push_back(regions[right]);
      right++;
    }
  }

  while (left <= mid){
    temp.push_back(regions[left]);
    left++;
  }

  while (right <= end){
    temp.push_back(regions[right]);
    right++;
  }

  for (int i = 0; i < static_cast<int>(temp.size()); i++){
    regions[start + i] = temp[i];
  }
}

//part 3
void mergeSortByCity(vector<Region>& regions, int start, int end){
  if (start >= end){
    return;
  }

  int mid = (start + end) / 2;

  mergeSortByCity(regions, start, mid);
  mergeSortByCity(regions, mid + 1, end);

  mergeByCity(regions, start, mid, end);
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

  clock_t startPt2 = clock();

  selectionSort(regions);

  clock_t endPt2 = clock();

  cout << "Selection sort took " << static_cast<double>(endPt2 - startPt2) / CLOCKS_PER_SEC << " seconds." << endl;

  cout << "First five regions after sort:" << endl;
  printFirstFiveRegions(regions);

  cout << endl;
  cout << "-----------------------------Part 3----------------------------"
       << endl;

  vector<Region> regionsByName = regions;

  clock_t startPt3 = clock();

  if (!regionsByName.empty())
}
