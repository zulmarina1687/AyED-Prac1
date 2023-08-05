package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func main() {
	var files = []string{"n100.txt", "n1000.txt", "n2000.txt", "n3000.txt", "n4000.txt", "n5000.txt",
		"n6000.txt", "n7000.txt", "n8000.txt", "n9000.txt", "n10000.txt",
		"n20000.txt", "n30000.txt", "n40000.txt", "n50000.txt"}

	Path := "C:\\Users\\luzma\\Desktop\\MAESTRIA\\AED\\PRACTICA1\\"
	PathFile := Path + "data\\"

	outputfile, err := os.OpenFile(Path+"algoritmosgo\\BSgo.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Fatalf("failed creating file: %s", err)
	}
	datawriter := bufio.NewWriter(outputfile)
	for _, filename := range files {
		file, err := os.Open(PathFile + filename)
		if err != nil {
			log.Fatalf("Error al abrir el archivo: %s", err)
		}
		scanner := bufio.NewScanner(file)
		scanner.Split(bufio.ScanLines)
		var arr []int
		for scanner.Scan() {
			num, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatalf("Error escanear data: %s", err)
			}
			arr = append(arr, num)
		}
		file.Close()
		slice := arr
		start := time.Now()
		bubbleSort(slice)
		duration := time.Since(start) //.Nanoseconds()
		fmt.Println("\n-BubbleSort\n", "size: ", len(arr)+1, " time: ", duration.Milliseconds())
		str1 := fmt.Sprintf("%d", len(arr)+1)
		str2 := fmt.Sprintf("%d", duration.Milliseconds())
		datawriter.WriteString(str1 + "," + str2 + "\n")
	}
	datawriter.Flush()
	outputfile.Close()

	outputfile1, err := os.OpenFile(Path+"\\algoritmosgo\\MSgo.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Fatalf("failed creating file: %s", err)
	}
	datawriter1 := bufio.NewWriter(outputfile1)
	for _, filename := range files {
		file, err := os.Open(PathFile + filename)
		if err != nil {
			log.Fatalf("Error al abrir el archivo: %s", err)
		}
		scanner := bufio.NewScanner(file)
		scanner.Split(bufio.ScanLines)
		var arr []int
		for scanner.Scan() {
			num, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatalf("Error escanear data: %s", err)
			}
			arr = append(arr, num)
		}
		file.Close()
		slice := arr
		start := time.Now()
		mergeSort(slice)
		duration := time.Since(start) //.Nanoseconds()
		fmt.Println("\n-MergeSort\n", "size: ", len(arr)+1, " time: ", duration.Milliseconds())
		str1 := fmt.Sprintf("%d", len(arr)+1)
		str2 := fmt.Sprintf("%d", duration.Milliseconds())
		datawriter1.WriteString(str1 + "," + str2 + "\n")
	}
	datawriter1.Flush()
	outputfile1.Close()

	outputfile2, err := os.OpenFile(Path+"\\algoritmosgo\\QSgo.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Fatalf("failed creating file: %s", err)
	}
	datawriter2 := bufio.NewWriter(outputfile2)
	for _, filename := range files {
		file, err := os.Open(PathFile + filename)
		if err != nil {
			log.Fatalf("Error al abrir el archivo: %s", err)
		}
		scanner := bufio.NewScanner(file)
		scanner.Split(bufio.ScanLines)
		var arr []int
		for scanner.Scan() {
			num, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatalf("Error escanear data: %s", err)
			}
			arr = append(arr, num)
		}
		file.Close()
		slice := arr
		start := time.Now()
		quickSort(slice)
		duration := time.Since(start) //.Nanoseconds()
		fmt.Println("\n-QuickSort\n", "size: ", len(arr)+1, " time: ", duration.Milliseconds())
		str1 := fmt.Sprintf("%d", len(arr)+1)
		str2 := fmt.Sprintf("%d", duration.Milliseconds())
		datawriter2.WriteString(str1 + "," + str2 + "\n")
	}
	datawriter2.Flush()
	outputfile2.Close()

	outputfile3, err := os.OpenFile(Path+"algoritmosgo\\HSgo.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Fatalf("failed creating file: %s", err)
	}
	datawriter3 := bufio.NewWriter(outputfile3)
	for _, filename := range files {
		file, err := os.Open(PathFile + filename)
		if err != nil {
			log.Fatalf("Error al abrir el archivo: %s", err)
		}
		scanner := bufio.NewScanner(file)
		scanner.Split(bufio.ScanLines)
		var arr []int
		for scanner.Scan() {
			num, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatalf("Error escanear data: %s", err)
			}
			arr = append(arr, num)
		}
		file.Close()
		slice := arr
		start := time.Now()
		heapSort(slice)
		duration := time.Since(start) //.Nanoseconds()
		fmt.Println("\n-HeapSort\n", "size: ", len(arr)+1, " time: ", duration.Milliseconds())
		str1 := fmt.Sprintf("%d", len(arr)+1)
		str2 := fmt.Sprintf("%d", duration.Milliseconds())
		datawriter3.WriteString(str1 + "," + str2 + "\n")
	}
	datawriter3.Flush()
	outputfile3.Close()

}

func bubbleSort(items []int) {
	var (
		n      = len(items)
		sorted = false
	)
	for !sorted {
		swapped := false
		for i := 0; i < n-1; i++ {
			if items[i] > items[i+1] {
				items[i+1], items[i] = items[i], items[i+1]
				swapped = true
			}
		}
		if !swapped {
			sorted = true
		}
		n = n - 1
	}
}

func quickSort(a []int) []int {
	if len(a) < 2 {
		return a
	}
	left, right := 0, len(a)-1
	pivot := rand.Int() % len(a)
	a[pivot], a[right] = a[right], a[pivot]
	for i, _ := range a {
		if a[i] < a[right] {
			a[left], a[i] = a[i], a[left]
			left++
		}
	}
	a[left], a[right] = a[right], a[left]
	quickSort(a[:left])
	quickSort(a[left+1:])
	return a
}

func mergeSort(items []int) []int {
	var num = len(items)
	if num == 1 {
		return items
	}
	middle := int(num / 2)
	var (
		left  = make([]int, middle)
		right = make([]int, num-middle)
	)
	for i := 0; i < num; i++ {
		if i < middle {
			left[i] = items[i]
		} else {
			right[i-middle] = items[i]
		}
	}
	return merge(mergeSort(left), mergeSort(right))
}

func merge(left, right []int) (result []int) {
	result = make([]int, len(left)+len(right))
	i := 0
	for len(left) > 0 && len(right) > 0 {
		if left[0] < right[0] {
			result[i] = left[0]
			left = left[1:]
		} else {
			result[i] = right[0]
			right = right[1:]
		}
		i++
	}
	for j := 0; j < len(left); j++ {
		result[i] = left[j]
		i++
	}
	for j := 0; j < len(right); j++ {
		result[i] = right[j]
		i++
	}
	return
}

func heapSort(target []int) {
	n := len(target)
	// Construir montón máximo
	for i := n/2 - 1; i >= 0; i-- {
		heapify(target, n, i)
	}
	for i := n - 1; i > 0; i-- {
		// Swap
		target[0], target[i] = target[i], target[0]
		// Heapify elemento raiz
		heapify(target, i, 0)
	}
}

func heapify(target []int, n int, i int) {
	// Encuentra el más grande entre la raíz y los hijos
	largest := i
	left := 2*i + 1
	right := 2*i + 2
	if left < n && target[left] > target[largest] {
		largest = left
	}
	if right < n && target[right] > target[largest] {
		largest = right
	}
	// Si la raíz no es la más grande, intercambie con la más grande y continúe acumulando
	if largest != i {
		target[i], target[largest] = target[largest], target[i]
		heapify(target, n, largest)
	}
}
