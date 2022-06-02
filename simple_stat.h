#ifndef SIMPLE_STAT_H
#define SIMPLE_STAT_H

// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "list.h"
#include "utilities.h"
#include <cmath>
#include <vector>
#include <utility>

template <typename E> // Array-based list implementation
class Simple_stat : public List<E> {
private:
  int maxSize; // Maximum size of list
  int listSize; // Number of list items now
  int curr; // Position of current element
  E* listArray; // Array holding list elements

public:

   Simple_stat() {
    maxSize = 0;
    listSize = 0;
  }

   Simple_stat(int size = 20) { // Constructor. Replace defaultSize (now 20) with the default you want otherwise leave empty
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize]; // Fized size array inside.
  }

template <typename D>
  Simple_stat(const E& datastruct) { // Constructor parameter using general datastructor that allows iteration
    for (auto i : datastruct) {
      append(i);
      maxSize++;
    }
  }

  ~Simple_stat() { delete [] listArray; } // Destructor
  void clear() { // Reinitialize the list
    delete [] listArray; // Remove the array
    listSize = curr = 0; // Reset the size
    listArray = new E[maxSize]; // Recreate array
  }

  //return list size
  int length_total() {
    return listSize;
  }

  //return listArray pointer
  int* getListPtr() {
    return listArray;
  }

  //operator[] to use indecies as expected
  //template <typename T>
  int& operator[] (int index) {
    if (index >= length_total()) {
      std::cout << "Index out of range" << std::endl;
    } else {
      return listArray[index];
    }
  }


  //bubble sort array
  void sort_data()
  {
    int temp;
      for (int i=0; i < length_total() - 1; i++)
      {
        for (int j=0; j < (length_total() - i - 1); j++)
        {
          if (listArray[j] > listArray[j + 1])
            {
              temp = listArray[j];
              listArray[j] = listArray[j+1];
              listArray[j+1] = temp;
            }
        }
      }
  }
  
  //unique elements, must be called on sorted array
  int length_unique(E arr[], int n) {
     int count = 0;
     for (int i = 0; i < n; i++){
        while (i < n - 1 && arr[i] == arr[i + 1]){
           i++;
        }
        count++;
     }
     return count;
  }
  
  // unique_set function to list an array of unique numbers
  void unique_set(E arr[])
  {
      std::cout << "A set of unique numbers in the array: " << std::endl;
  
      int j=0;    // index for unique set
      for (int i=0; i<listSize; ++i)
      {
        if(arr[i]==arr[i+1])
        {
          continue;   // go back to for loop to continue
        }
        else
        {
          std::cout << "unique_set[" <<j << "]" << arr[i]<< std::endl;
          j++;
        }
      }
  }
  
  //search and count
  void search (E arr[], int element) {
    std::cout << "Searching for: " << element << std::endl;
    E value;
    int count = 0;
    int index;
    bool found;
    for (int i = 0; i < length_total(); i++) {
      if (arr[i] == element) {
        value = arr[i];
        index = i;
        found = true;
        break;
        }
      else {found = false;}
      }
      if (found) {
        for (int i = 0; i < length_total(); i++) {
          if (arr[i] == value) {
            count++;
          }
        }  
      } 
    
    if (found) {
      std::cout << "First occurence of " << value << " found at index: " << index << std::endl;
      std::cout << "Number of occurences of " << value << ": "<< count << std::endl;
  } else {
      std::cout << value << " not found" << std::endl;
    }
  }
  
  //stat methods
  
  //Square root
  float squarert (int * arrayPtr, int arraySize) {
    float sum = 0;
    for (int i = 0; i < arraySize; i++) {
      sum += *(arrayPtr + i);
    }
    return sqrt(sum);
  }
  
  //Get max element
  E get_max() {
    E max = 0;
    for (int i = 0; i < length_total(); i++) {
      if (listArray[i] >= max) {
        max = listArray[i];
      }
    }
    return max;
  }
  
  //Get min element
  E get_min() {
    E min = listArray[0];
    for (int i = 0; i < length_total(); i++) {
      if (listArray[i] <= min) {
        min = listArray[i];
      }
    }
    return min;
  }
  
  //Get average
  E get_mean() {
    E sum = 0;
    for (int i = 0; i < length_total(); i++) {
      sum += listArray[i];
    }
    return sum / length_total();
  }
  
  //get standard deviation
  E get_SD() {
    E sum_of_sq = 0;
    for (int i = 0; i < length_total(); i++) {
      sum_of_sq = sum_of_sq + (listArray[i] - get_mean()) * (listArray[i] -     get_mean());
    }
    E var = sum_of_sq / length_total();
    E SD = sqrt(var);
    return SD;
  }
  
  // Feed function
  template <typename D> // general data structure that allows interation
  void feed(const D& datastruct)
  {
    for (auto i : datastruct)
    {
      append(i);
    }
  }
  
  // removem function 
  
  void removem(const E& it, const int m) {
    int n = 0;
    for (int i = 0; i < listSize; i++)
      if (listArray[i] == it)
        n++;
    
  
    int counter = m;
    if (m <= n) {
      for (int q = 0; q < listSize-1; q++) {
        if (listArray[q] == it && counter > 0) {
          for (int curr = q; curr < listSize-1; curr++) {
            listArray[curr] = listArray[curr+1];
          }
          listSize--;
          counter--;
          q--;
        }
      }
      std::cout << "deleted " << m << " " << it  << "'s" << std::endl;
    }
    else
      std::cout << "There are less than " << m << " repititions of " << it << " in       the list Array." << std::endl;
  }
  
  
  // empty function WORK IN PROGRESS
  void empty() {
    for (int i = 0; i < listSize; i++)
      listArray[i] = NULL;
    listSize = 0;
    maxSize = 0;
  }
  
  
  //methods after this point from original alist.h document


  // Insert "it" at current position
  void insert(const E& it) {
    Assert(listSize < maxSize, "List capacity exceeded");
    for(int i=listSize; i>curr; i--) // Shift elements up
      listArray[i] = listArray[i-1]; // to make room
    listArray[curr] = it;
    listSize++; // Increment list size
  }
  void append(const E& it) { // Append "it"
    Assert(listSize < maxSize, "List capacity exceeded");
    listArray[listSize++] = it;
  }
  // Remove and return the current element.
  E remove() {
    Assert((curr>=0) && (curr < listSize), "No element");
    E it = listArray[curr]; // Copy the element
    for(int i=curr; i<listSize-1; i++) // Shift them down
      listArray[i] = listArray[i+1];
    listSize--; // Decrement size
    return it;
  }
  void moveToStart() {
    curr = 0;
  } // Reset position
  void moveToEnd() {
    curr = listSize; // Set at end
  }
  void prev() {
    if (curr != 0) curr--; // Back up
  }
  void next() {
    if (curr < listSize) curr++; // Next
  }
  // Return list size
  int length() const {
    return listSize;
  }
  // Return current position
  int currPos() const {
    return curr;
  }
  // Set current list position to "pos"
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
    curr = pos;
  }
  const E& getValue() const { // Return current element
    Assert((curr>=0)&&(curr<listSize),"No current element");
    return listArray[curr];
  }
  bool isAtEnd() { return curr == listSize; }

  bool ssearch(const E& it)
  {
    for (auto an_element : listArray)
      {
        if (an_element == it)
          return true;
      }
    return false;
  }
  // Iteraive binary search
  bool ibsearch(const E& search_this)
  {
    int right = listSize - 1;
    int left = 0;
    while (left <= right) // Left and right can't cross
      {
        int mid = left + (right - left)/2;

        if (listArray[mid] == search_this)
          return true; // Found it
        if (listArray[mid] > search_this)
          {
            right = mid - 1; // Search key is in frirst half. So leave the right half by moving right to mid - 1
          }
        else
          {
            left = mid + 1; // Search key is in second half. So leave the left half by moving left to mid + 1
          }
      }
    return false;
  }
// recusive binary search
  bool rbsearch(const E& search_this, int left, int right)
  {
    int mid = left + (right - left)/2;

    if (listArray[mid] == search_this)
      return true; // Found it
    if (listArray[mid] > search_this)
      {
        right =mid - 1; // Search key is in frirst half. So leave the right half by moving right to mid - 1
      }
    else
      {
        left = mid + 1; // Search key is in second half. So leave the left half by moving left to mid + 1
      }
    return rbsearch(search_this, left, right);
  }
};
#endif // SIMPLE_STAT_H
