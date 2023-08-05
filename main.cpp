#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

// Implementación del algoritmo Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Implementación del algoritmo QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
                break;

            std::swap(arr[i], arr[j]);
        }

        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

// Implementación del algoritmo Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Función para obtener el tiempo de procesamiento promedio
double getAverageTime(std::vector<int>& arr, void (*sortFunction)(std::vector<int>&)) {
    const int repetitions = 5;
    double total_time = 0.0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<int> temp = arr;
        auto start = std::chrono::high_resolution_clock::now();
        sortFunction(temp);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }

    return total_time;
}
/*
// Función para obtener la desviación estándar del tiempo de procesamiento
double getStandardDeviation(std::vector<int>& arr, void (*sortFunction)(std::vector<int>&)) {
    double average_time = getAverageTime(arr, sortFunction);
    const int repetitions = 5;
    double squared_sum = 0.0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<int> temp = arr;
        auto start = std::chrono::high_resolution_clock::now();
        sortFunction(temp);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        double time_diff = duration.count() - average_time;
        squared_sum += time_diff * time_diff;
    }

    double variance = squared_sum / repetitions;
    return std::sqrt(variance);
}
*/

// Implementación del algoritmo Heap Sort
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {
    std::vector<std::string> filenames = {
        "n100.txt", "n1000.txt", "n2000.txt", "n3000.txt", "n4000.txt", "n5000.txt",
        "n6000.txt", "n7000.txt", "n8000.txt", "n9000.txt", "n10000.txt",
        "n20000.txt", "n30000.txt", "n40000.txt", "n50000.txt"
    };

    std::ofstream outputFile("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\algoritmoscpp\\BScpp.txt");
    if (!outputFile) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }
    for (const std::string& filename : filenames) {
        std::ifstream inputFile("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\data\\" + filename);
        if (!inputFile) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            continue;
        }
        std::vector<int> arr;
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }
        outputFile << arr.size()+1 << ",";
        // Bubble Sort
        double bubble_avg_time = getAverageTime(arr, bubbleSort) * 1000;
        //double bubble_std_dev = getStandardDeviation(arr, bubbleSort) * 1000;
        outputFile << bubble_avg_time << std::endl;
    }
    outputFile.close();

    std::ofstream outputFile1("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\algoritmoscpp\\QScpp.txt");
    if (!outputFile1) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }
    for (const std::string& filename : filenames) {
        std::ifstream inputFile("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\data\\" + filename);
        if (!inputFile) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            continue;
        }
        std::vector<int> arr;
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }
        outputFile1 << arr.size()+1 << ",";
        // QuickSort
        double quick_avg_time = getAverageTime(arr, [](std::vector<int>& v) { quickSort(v, 0, v.size() - 1); }) * 1000; 
        //double quick_std_dev = getStandardDeviation(arr, [](std::vector<int>& v) { quickSort(v, 0, v.size() - 1); }) * 1000; 
        outputFile1 << quick_avg_time << std::endl;
    }
    outputFile1.close();

    std::ofstream outputFile2("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\algoritmoscpp\\MScpp.txt");
    if (!outputFile2) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }
    for (const std::string& filename : filenames) {
        std::ifstream inputFile("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\data\\" + filename);
        if (!inputFile) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            continue;
        }
        std::vector<int> arr;
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }
        outputFile2 << arr.size()+1 << ",";
        // Merge Sort
        double merge_avg_time = getAverageTime(arr, [](std::vector<int>& v) { mergeSort(v, 0, v.size() - 1); }) * 1000;
        //double merge_std_dev = getStandardDeviation(arr, [](std::vector<int>& v) { mergeSort(v, 0, v.size() - 1); }) * 1000;
        outputFile2 << merge_avg_time << std::endl;
    }
    outputFile2.close();

    std::ofstream outputFile3("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\algoritmoscpp\\HScpp.txt");
    if (!outputFile3) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }
    for (const std::string& filename : filenames) {
        std::ifstream inputFile("C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\data\\" + filename);
        if (!inputFile) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            continue;
        }
        std::vector<int> arr;
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }
        outputFile3 << arr.size()+1 << ",";
        // Heap Sort
        double heap_avg_time = getAverageTime(arr, heapSort) * 1000;
        //double heap_std_dev = getStandardDeviation(arr, heapSort) * 1000;
        outputFile3 << heap_avg_time << std::endl;
    }
    outputFile3.close();
    return 0;
}