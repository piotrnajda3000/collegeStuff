#pragma once

#include "GraphPoint.h"

void bubbleSort(int* arr, int n, GraphPoint& point);

void insertSort(int* arr, int n, GraphPoint& point);

/* Quicksort */

int partition(int arr[], int low, int high, GraphPoint& point);

void quickSort(int arr[], int low, int high, GraphPoint& point);