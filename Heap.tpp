//
// Created by Santiago Robles on 17/05/23.
//

#include "Heap.h"

template<typename T, bool filterFunction(const T &, const T &)>
Heap<T, filterFunction>::Heap(unsigned int cap) : capacity(cap) {
    heapSize = 0;
    harr = new T[cap];
}

template<typename T, bool filterFunction(const T &, const T &)>
void Heap<T, filterFunction>::InsertKey(T key) {
    if (heapSize == capacity) {
        std::cout << "\nOverflow: Could not insert Key\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    harr[i] = key;

    while (i != 0 && filterFunction(harr[parent(i)], harr[i])) {
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

template<typename T, bool filterFunction(const T &, const T &)>
unsigned int Heap<T, filterFunction>::parent(unsigned int i) {
    return (i - 1) / 2;
}

template<typename T, bool filterFunction(const T &, const T &)>
unsigned int Heap<T, filterFunction>::left(unsigned int i) {
    return (2 * i) + 1;
}

template<typename T, bool filterFunction(const T &, const T &)>
unsigned int Heap<T, filterFunction>::right(unsigned int i) {
    return (2 * i) + 2;
}

template<typename T, bool filterFunction(const T &, const T &)>
void Heap<T, filterFunction>::Heapify(unsigned int i) {
    unsigned int l = left(i);
    unsigned int r = right(i);
    unsigned int largest = i;

    if (l < heapSize && filterFunction(harr[largest], harr[l])) {
        largest = l;
    }
    if (r < heapSize && filterFunction(harr[largest], harr[r])) {
        largest = r;
    }
    if (largest != i) {
        std::swap(harr[i], harr[largest]);
        Heapify(largest);
    }
}

template<typename T, bool filterFunction(const T &, const T &)>
T Heap<T, filterFunction>::extractRoot() {
    if (heapSize <= 0) {
        throw std::runtime_error("Heap is empty");
    }
    if (heapSize == 1) {
        heapSize--;
        return harr[0];
    }

    T root = harr[0];
    harr[0] = harr[heapSize - 1];
    heapSize--;
    Heapify(0);
    return root;
}

template<typename T, bool (*filterFunction)(const T &, const T &)>
unsigned Heap<T, filterFunction>::GetSize() const {
    return heapSize;
}

template<typename T, bool (*filterFunction)(const T &, const T &)>
T Heap<T, filterFunction>::GetRoot() {
    return harr[0];
}

