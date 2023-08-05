from math import floor
import time
import sys
import random
import os

def Read_A(archivo_n):
    Lista = []
    archivo=open(archivo_n,'r')
    leer_fila= archivo.readlines()
    archivo.close()
    for lista in leer_fila:
        if lista[-1]=="\n": dato=lista[:-1]
        else: dato=lista
        Lista.append(int(dato))
    return Lista

def bubbleSort(arr):
    n = len(arr)
    swapped = False
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        if not swapped:
            return
    return arr

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * (n1)
    R = [0] * (n2)
    for i in range(0, n1):
        L[i] = arr[l + i]
 
    for j in range(0, n2):
        R[j] = arr[m + 1 + j]
    i = 0     # Initial index of first subarray
    j = 0     # Initial index of second subarray
    k = l     # Initial index of merged subarray
 
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
    if l < r:
        m = l+(r-l)//2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)

def mergeSort_sort(archivo_n):
    Lista_n = Read_A(archivo_n)
    inicio = time.time()
    mergeSort(Lista_n,0,len(Lista_n)-1)
    fin = time.time()
    return float(fin-inicio)

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1

def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)

def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2
    if l < n and arr[i] < arr[l]:
        largest = l
    if r < n and arr[largest] < arr[r]:
        largest = r
    if largest != i:
        (arr[i], arr[largest]) = (arr[largest], arr[i])  # swap
        heapify(arr, n, largest)
 
def heapSort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        (arr[i], arr[0]) = (arr[0], arr[i])  # swap
        heapify(arr, i, 0)

def printList(arr): 
    for i in range(len(arr)):         
        print(arr[i])


Path = "C:/Users/luzma/Desktop/MAESTRIA/AED/PRACTICA1/"
PathArchivos = Path + "data/"
Archivos = ["n100.txt","n1000.txt","n2000.txt","n3000.txt","n4000.txt","n5000.txt","n6000.txt","n7000.txt","n8000.txt","n9000.txt","n10000.txt","n20000.txt","n30000.txt","n40000.txt","n50000.txt"]
Tam = [100,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,20000,30000,40000,50000]

file = open(Path + "algoritmospython/BSpy.txt", "w")
for i in Archivos:
    Lista_n = Read_A(PathArchivos + i)
    inicio = time.time()
    bubbleSort(Lista_n)
    fin = time.time()
    time_aux =  float(fin-inicio) * 1000
    file.write(str(len(Lista_n)+1) + "," + str(time_aux) + "\n")
file.close()

file1 = open(Path + "algoritmospython/MSpy.txt", "w")
for i in Archivos:
    Lista_n = Read_A(PathArchivos + i)
    inicio = time.time()
    mergeSort(Lista_n,0,len(Lista_n)-1)
    fin = time.time()
    time_aux =  float(fin-inicio)  * 1000
    file1.write(str(len(Lista_n)+1) + "," + str(time_aux) + "\n")
file1.close()

file2 = open(Path + "algoritmospython/QSpy.txt", "w")
for i in Archivos:
    Lista_n = Read_A(PathArchivos + i)
    inicio = time.time()
    quickSort(Lista_n,0,len(Lista_n)-1)
    fin = time.time()
    time_aux =  float(fin-inicio) * 1000
    file2.write(str(len(Lista_n)+1) + "," + str(time_aux) + "\n")
file2.close()

file3 = open(Path + "algoritmospython/HSpy.txt", "w")
for i in Archivos:
    Lista_n = Read_A(PathArchivos + i)
    inicio = time.time()
    heapSort(Lista_n)
    fin = time.time()
    time_aux =  float(fin-inicio) * 1000
    file3.write(str(len(Lista_n)+1) + "," + str(time_aux) + "\n")
file3.close()
