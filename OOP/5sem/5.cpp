int* copyarr(int* a, unsigned int size) {
    int* copy = new int[size];
    std::copy(a, a + size, copy);
    return copy;
}

// in main 
// it needs to be free
// with delete[]