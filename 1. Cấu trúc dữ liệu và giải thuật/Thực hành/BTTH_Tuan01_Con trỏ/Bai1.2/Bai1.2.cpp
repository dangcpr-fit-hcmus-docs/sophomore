#include <iostream>
#include <memory.h>
using namespace std;

int* initialize(int maxsize) {
    int* p = NULL;
    p = (int*)malloc(maxsize * sizeof(int));
    return p;
}

int* growSize(int* array, int size, int& maxsize) {
    if (size == 0) array == NULL;
    else {
        array = (int*)realloc(array, sizeof(int) * size);
        maxsize = size;
    }
    return array;
}

void addElement(int*& array, int data, int& size, int& maxSize) {
    size++;
    if (size > maxSize) {
        array = growSize(array, size, maxSize);
    }
    array[size - 1] = data;
}

void addElementAtIndex(int*& array, int index, int data, int& size, int& maxSize) {
    size++;
    if (size > maxSize) {
        array = growSize(array, size, maxSize);
    }
    for (int i = size - 1; i >= index + 1; i--) {
        array[i] = array[i - 1];
    }
    array[index] = data;
}

void removeElement(int* array, int& size, int maxSize) {
    array = (int*)realloc(array, sizeof(int) * (size - 1));
    size--;
    array = (int*)realloc(array, sizeof(int) * maxSize);
}

void removeElementAtIndex(int* array, int index, int& size, int maxSize) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array = (int*)realloc(array, sizeof(int) * (size - 1));
    size--;
    array = (int*)realloc(array, sizeof(int) * maxSize);
}

int* shrinkArray(int* array, int size, int& maxSize) {
    if (maxSize > size) {
        array = (int*)realloc(array, sizeof(int) * size);
        maxSize = size;
    }
    return array;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
}

int maxElement(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int searchElement(int* array, int key, int size) {
    for (int i = 0; i < size; i++) {
        if (key == array[i])
            return i;
    }
    return -1;
}

int* merge2Arrays(int* a, int* b, int na, int nb) {
    int* mer = initialize(na + nb);
    int size = na + nb;
    int i = 0, j = 0, k = 0;
    while (i != na && j != nb) {
        if (a[i] < b[j]) {
            mer[k] = a[i];
            i++; k++;
        }
        else {
            mer[k] = b[j];
            j++; k++;
        }
    }
    if (i <= na) {
        for (int t = i; t < na; t++) {
            mer[k] = a[t];
            k++;
        }
    }
    else {
        for (int t = i + 1; t < nb; t++) {
            mer[k] = b[t];
            k++;
        }
    }
    return mer;
}

int main()
{
    int maxSize = 4;
    int size = 0;
    int* p = initialize(maxSize);
    addElement(p, 4, size, maxSize);
    addElement(p, 6, size, maxSize);
    addElement(p, 13, size, maxSize);
    addElement(p, 5, size, maxSize);
    addElement(p, 9, size, maxSize);
    addElementAtIndex(p, 1, 7, size, maxSize);
    cout << "Mang da tao: ";
    printArray(p, size);
    cout << endl;
    //removeElement(p, size, maxSize);
    //removeElementAtIndex(p, 2, size, maxSize);
    /**cout << "Mang sau khi xoa: ";
    printArray(p, size);*/
    p = shrinkArray(p, size, maxSize);

    int x = searchElement(p, 4, size);
    if (x == -1) cout << "Khong thay phan tu ban can tim trong mang";
    else cout << "Phan tu can tim co chi so la: " << x;

    int* a = initialize(maxSize);
    int sizea = 0, maxSizea = 0;
    addElement(a, 4, sizea, maxSizea);
    addElement(a, 5, sizea, maxSizea);
    addElement(a, 6, sizea, maxSizea);
    addElement(a, 9, sizea, maxSizea);
    addElement(a, 13, sizea, maxSizea);
    int* b = initialize(maxSize);
    int sizeb = 0, maxSizeb = 0;
    addElement(b, 1, sizeb, maxSizeb);
    addElement(b, 2, sizeb, maxSizeb);
    addElement(b, 8, sizeb, maxSizeb);
    addElement(b, 10, sizeb, maxSizeb);
    addElement(b, 11, sizeb, maxSizeb);
    int* mer = merge2Arrays(a, b, sizea, sizeb);
    cout << "\nMang da tao: ";
    printArray(mer, sizea + sizeb);
    free(p);
    free(a); free(b);
    return 0;
}