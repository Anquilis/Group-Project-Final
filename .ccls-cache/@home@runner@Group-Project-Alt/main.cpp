// Group: Zion
// Members: Damond Fang, Andrew Grant, Angelo Bolos, Cheng Kuong
// CS 110C, Spring 2022
// Group Project 1: Simple_stat class design and implementation
//
// This program takes an array of numbers and returns a sorted 
// array, unique numbers in array and their count, minimum, 
// maximum, mean and standard deviation, count of the occurrence 
// of a number and remove numbers.
//  
// See UML diagram for algorithm.
//
#include "simple_stat.h"
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>


// --------------- Main Function ---------------

int main() {
  //not exact testing criteria
  //creating random vector
  std::vector<int> randomVec100;
  for (int i = 0; i < 100; i++) {
    int num;
    num = (rand() % 100) + 1; 
    randomVec100.push_back(num);
  }

  //creating object
  Simple_stat<int> intArrayList(100);
  //appending values from random vector to our object

  for (int i = 0; i < 100; i++) {
    intArrayList.append(randomVec100[i]);
  }

  //sort list
  intArrayList.sort_data();

  //search for a number
  intArrayList.search(intArrayList.getListPtr(), 77);

  //variable storing count of unique elements
  int unique = intArrayList.length_unique(intArrayList.getListPtr(), intArrayList.length_total());

  // find a set of unique numbers within the array
  intArrayList.unique_set(intArrayList.getListPtr());

  std::cout << "Length: " << intArrayList.length_total() << std::endl;
  std::cout << "Max: " << intArrayList.get_max() << std::endl;
  std::cout << "Min: " << intArrayList.get_min() << std::endl;
  std::cout << "Unique elements: " << unique << std::endl;
  std::cout << "Mean: " << intArrayList.get_mean() << std::endl;
  std::cout << "Standard Deviation: " << intArrayList.get_SD() << std::endl;

  //printing out array based list
  std::cout << "Printing (Before): " << std::endl; 
  for (int i = 0; i < intArrayList.length(); i++) {
    std::cout << "intArrayList[" << i << "]: " << intArrayList[i] << std::endl;
  }
  
  intArrayList.removem(27,3);
  
  //printing out array based list
  std::cout << "Printing (After): " << std::endl; 
  for (int i = 0; i < intArrayList.length(); i++) {
    std::cout << "intArrayList[" << i << "]: " << intArrayList[i] << std::endl;
  }

  intArrayList.empty();

  std::cout << "Printing (emptied): " << std::endl; 
  for (int i = 0; i < intArrayList.length(); i++) {
    std::cout << "intArrayList[" << i << "]: " << intArrayList[i] << std::endl;
  }


}