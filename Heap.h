//
// Created by Santiago Robles on 17/05/23.
//

#ifndef MONTICULO_HEAP_H
#define MONTICULO_HEAP_H

#include <iostream>

template<typename T>
bool minHeap(const T &a, const T &b) { return a <= b; }

template<typename T>
bool maxHeap(const T &a, const T &b) { return a >= b; }

template<typename T, bool filterFunction(const T &, const T &) = minHeap>
class Heap {
private:
    T *harr; /**< Pointer to array of elements in the heap**/
    unsigned capacity; /**< Maximum capacity of the heap**/
    unsigned heapSize; /**< Current number of elements in the heap**/
public:
    /**
     * @brief Constructor
     * @param capacity
     */
    explicit Heap(unsigned cap);

    /**
     * @brief Heapifies a subtree with the root of the given index
     * @param i Index of the root of the subtree
     */
    void Heapify(unsigned i);

    /**
     * @brief Returns the index of the parent of the child
     * @param i Index of the child
     * @return The index of the parent of the child
     */
    unsigned parent(unsigned i);

    /**
     * @brief Returns the index of the left brother
     * @param i Index of the right brother
     * @return The index of the left brother
     */
    unsigned left(unsigned i);

    /**
     * @brief Returns the index of the right brother
     * @param i Index of the left brother
     * @return The index of the right brother
     */
    unsigned right(unsigned i);

    /**
     * @brief Returns the content of the root and remove it from heap
     * @return Content of the root
     */
    T extractRoot();

    /**
     * @brief Returns the value of the root
     * @return The value of the root
     */
    T GetRoot();

    /**
     * @brief Inserts the given key to the heap
     * @param key Key to be inserted
     */
    void InsertKey(T key);

    unsigned GetSize() const;

};

#include "Heap.tpp"

#endif //MONTICULO_HEAP_H
