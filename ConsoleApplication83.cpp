#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

class Point {
private:
    int x, y;

public:
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
class Array {
private:
    int* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new int[size]();
    }

    ~Array() {
        delete[] data;
    }

    int& operator[](int index) {
        return data[index];
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Buffer {
private:
    int* data;
    int size;

public:
    Buffer(int size) : size(size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Buffer(Buffer&& other)
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    Buffer& operator=(Buffer&& other) {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Complex c1(3.0, 4.5), c2(2.0, 3.5);
    Complex c3 = c1 + c2;
    std::cout << "Sum of complex numbers: ";
    c3.display();

    Point p1(3, 4);
    Point p2(7, 8);

    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;

    Array arr(5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    std::cout << "Array contents: ";
    arr.display();

    Buffer buf1(3);
    Buffer buf2 = buf1;
    std::cout << "Buffer contents after transfer: ";
    buf2.print();

    return 0;
}
