#ifndef SORTABLE_H
#define SORTABLE_H
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>



int partition(vector<int> v, int start, int end)
{
 
    T pivot = v[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (v[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(v[pivotIndex], v[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (v[i] <= pivot) {
            i++;
        }
 
        while (v[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(v[i++], v[j--]);
        }
    }
 
    return pivotIndex;
}
void swap(T & a, T & b){
    T temp = a;
    a=b;
    b=temp;
}
 
void quickSort(vector<int> v, int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(v, start, end);
 
    // Sorting the left part
    quickSort(v, start, p - 1);
 
    // Sorting the right part
    quickSort(v, p + 1, end);
}
 
