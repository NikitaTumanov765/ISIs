﻿#include <iostream>
#include <vector>

class Array {
private:
    std::vector<int> data;

public:
    int lowerBound;
    int upperBound;

    Array(int low, int upper) : lowerBound(low), upperBound(upper) {
        data.resize(upper - low + 1);
    }

    ~Array() {}

    void setValue(int index, int value) {
        if (index >= lowerBound && index <= upperBound) {
            data[index - lowerBound] = value;
        }
    }

    int getValue(int index) const {
        if (index >= lowerBound && index <= upperBound) {
            return data[index - lowerBound];
        }
        else {

            return 0;
        }
    }

    void print() const {
        for (int i = lowerBound; i <= upperBound; ++i) {
            std::cout << getValue(i) << " ";
        }
        std::cout << std::endl;
    }

    Array operator+(int constant) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result.setValue(i, getValue(i) + constant);
        }
        return result;
    }

    Array operator*(int constant) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result.setValue(i, getValue(i) * constant);
        }
        return result;
    }

    Array operator+(const Array& other) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result.setValue(i, getValue(i) + other.getValue(i));
        }
        return result;
    }

    Array operator-(const Array& other) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result.setValue(i, getValue(i) - other.getValue(i));
        }
        return result;
    }

    Array operator*(const Array& other) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result.setValue(i, getValue(i) * other.getValue(i));
        }
        return result;
    }

    Array operator/(const Array& other) const {
        Array result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            if (other.getValue(i) != 0) {
                result.setValue(i, getValue(i) / other.getValue(i));
            }
            else {
                break;
                //result.setValue(i, 0);
            }
        }
        return result;
    }
};

int main() {
    int low, upper;
    //std::cout << "Enter low and upper bounds of the array: ";
    std::cin >> low >> upper;

    Array array1(low, upper);
    Array array2(low, upper);

    //std::cout << "Enter array elements for Array1: ";
    for (int i = low; i <= upper; ++i) {
        int value;
        std::cin >> value;
        array1.setValue(i, value);
    }

    //std::cout << "Enter array elements for Array2: ";
    for (int i = low; i <= upper; ++i) {
        int value;
        std::cin >> value;
        array2.setValue(i, value);
    }

    int constant;
    //std::cout << "Enter a constant: ";
    std::cin >> constant;

    std::cout << "Array1= ";
    array1.print();
    std::cout << "Array1+const= ";
    (array1 + constant).print();
    std::cout << "Array1*const= ";
    (array1 * constant).print();
    std::cout << "Array2= ";
    array2.print();
    std::cout << "Array2+const= ";
    (array2 + constant).print();
    std::cout << "Array2*const= ";
    (array2 * constant).print();

    std::cout << "summa= ";
    (array1 + array2).print();
    std::cout << "raznost= ";
    (array1 - array2).print();
    std::cout << "proizv = ";
    (array1 * array2).print();
    //std::cout << "delenie= ";
   // (array1 / array2).print();
    int chet = 0;
    for (int i = low; i <= upper; ++i) {
        if (array2.getValue(i) == 0) {
            chet += 1;
        }
    }

    if (chet == 0) {
        std::cout << "delenie= ";
        (array1 / array2).print();
    }
    else {
        std::cout << "delenie na 0" << std::endl;
        (array1 / array2);
    }

    while (true) {
        int action, index;
        // std::cout << "Enter action and index (0 to exit): ";
        std::cin >> action;

        if (action == 0) {
            break;
        }

        std::cin >> index;

        if (action == 1) {
            if (index >= low && index <= upper)
                std::cout << "Array1[" << index << "]= " << array1.getValue(index) << std::endl;
            else {
                array1.getValue(index);
                std::cout << "Array1 wrong index " << index << std::endl;
            }
        }
        else if (action == 2) {
            if (index >= low && index <= upper)
                std::cout << "Array2[" << index << "]= " << array2.getValue(index) << std::endl;
            else {
                array1.getValue(index);
                std::cout << "Array2 wrong index " << index << std::endl;
            }
        }

    }
    return 0;
}
