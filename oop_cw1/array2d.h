#ifndef __ARRAY2D__
#define __ARRAY2D__

// ******************************************************************************************************************
// Includes - I only used two!
// ******************************************************************************************************************
#include <cstring>
#include <algorithm>
// ******************************************************************************************************************
// Class Definition
// ******************************************************************************************************************
template<typename T>
class array2d {
    private:
	    // Member Variables
	    size_t width;
	    size_t height;
	    T *data;
    public:
	    // Construction / Destruction
	    array2d<T>();

	    array2d<T>(const size_t &width, const size_t &height);
	    array2d<T>(const size_t &width, const size_t &height, const T &value);

	    ~array2d<T>();

	    // Width / Height Accessors
	    size_t get_height() const;
	    size_t get_width() const;

	    // 1D Index Operators
	    T& operator [](const size_t index);
	    const T& operator [](const size_t index) const;

	    // 2D Index Operators
	    T& operator ()(const size_t y, const size_t x);
	    const T& operator ()(const size_t y, const size_t x) const;

	    // Copy Constructor / Assignment Operator
	    array2d<T>(const array2d<T> &array);
	    array2d<T>& operator=(const array2d<T> &array);

	    // Move Constructor / Assignment Operator
	    array2d<T>(array2d<T> &&array);
	    array2d<T>& operator=(array2d<T> &&rhs);

	    // Scalar Assignment Operator
	    array2d<T>& operator=(const T &num);

	    // Negation Operator
	    array2d<T> operator-() const;

	    // Element-wise Operators
	    array2d<T> operator*(const array2d<T> &rhs) const;
	    array2d<T> operator/(const array2d<T> &rhs) const;
	    array2d<T> operator+(const array2d<T> &rhs) const;
	    array2d<T> operator-(const array2d<T> &rhs) const;

	    // Self Element-wise Operators
	    array2d<T>& operator*=(const array2d<T> &rhs);
	    array2d<T>& operator/=(const array2d<T> &rhs);
	    array2d<T>& operator+=(const array2d<T> &rhs);
	    array2d<T>& operator-=(const array2d<T> &rhs);

	    // Scalar Operators i.e. (x / 1)
	    array2d<T> operator*(const T &rhs) const;
	    array2d<T> operator/(const T &rhs) const;
	    array2d<T> operator+(const T &rhs) const;
	    array2d<T> operator-(const T &rhs) const;

	    // Self Scalar Operators i.e. (x /= 1) equiv to (x = x / 1)
	    array2d<T>& operator*=(const T &rhs);
	    array2d<T>& operator/=(const T &rhs);
	    array2d<T>& operator+=(const T &rhs);
	    array2d<T>& operator-=(const T &rhs);

	    // Friend Scalar Operators i.e. (1 / x) as opposed to (x / 1)
	    template<typename E>
	    friend array2d<E> operator*(const E &lhs, const array2d<E> &rhs);
	    template<typename E>
	    friend array2d<E> operator/(const E &lhs, const array2d<E> &rhs);
	    template<typename E>
	    friend array2d<E> operator+(const E &lhs, const array2d<E> &rhs);
	    template<typename E>
	    friend array2d<E> operator-(const E &lhs, const array2d<E> &rhs);

	    // Cast Operator
	    template<typename E>
	    operator array2d<E>() const;

	    // std::ostream << Operator
	    template<typename E>
	    friend std::ostream& operator<<(std::ostream &os, const array2d<E> &rhs);
};

// ******************************************************************************************************************
// Construction / Destruction
// ******************************************************************************************************************
//default constructor
template<typename T>
array2d<T>::array2d(): width(0), height(0), data(nullptr) {}

//overloaded constructors
template<typename T>
array2d<T>::array2d(const size_t& _width, const size_t& _height): width(_width), height(_height){
    if (height == 0 && width == 0){
        data = nullptr;
    }else{
        data = new T[height * width];
    }
}

template<typename T>
array2d<T>::array2d(const size_t& _width, const size_t& _height, const T& value): array2d<T>(_width, _height) {
    for (size_t i=0; i<width*height; i++){
        data[i] = value;
    }
}

//destructor
template<typename T>
array2d<T>::~array2d() {

    if(data != nullptr){
        delete [] data;
        data = nullptr;
    }

    height = 0;
    width = 0;
}

// ******************************************************************************************************************
// Width / Height Accessors
// ******************************************************************************************************************
template<typename T>
size_t array2d<T>::get_height() const{
    return height;
}

template<typename T>
size_t array2d<T>::get_width() const{
    return width;
}

// ******************************************************************************************************************
// 1D Index Operators
// ******************************************************************************************************************
template<typename T>
T& array2d<T>::operator[](const size_t index) {
    return data[index];
}

template<typename T>
const T& array2d<T>::operator[](const size_t index) const{
    return data[index];
}
// ******************************************************************************************************************
// 2D Index Operators
// ******************************************************************************************************************
template<typename T>
T& array2d<T>::operator()(const size_t y, const size_t x) {
    return data[x + (y * width)];
}

template<typename T>
const T& array2d<T>::operator()(const size_t y, const size_t x) const{
    return data[x + (y * width)];
}

// ******************************************************************************************************************
// Copy Constructor / Assignment Operator
// ******************************************************************************************************************
template<typename T>
array2d<T>::array2d(const array2d<T> &array): array2d<T>(array.width, array.height) {
    for(size_t i=0; i<(height*width); i++){
        data[i] = array.data[i];
    }
}

template<typename T>
array2d<T>& array2d<T>::operator=(const array2d<T> &rhs) {
    //if array sizes aren't equal, perform a few extra steps before assigning array values
    if(width != rhs.width && height != rhs.height){
        width = rhs.width;
        height = rhs.height;

        if(data != nullptr){
            delete [] data;
            data = nullptr;
        }

        data = new T[width * height];
    }

    for(size_t i=0; i<(height*width); i++){
        data[i] = rhs.data[i];
    }

    return *this;
}

// ******************************************************************************************************************
// Move Constructor / Assignment Operator
// ******************************************************************************************************************
template<typename T>
array2d<T>::array2d(array2d<T> &&array): width(array.width), height(array.height) {
    data = array.data;
    array.width = 0;
    array.height = 0;
    array.data = nullptr;
}

template<typename T>
array2d<T>& array2d<T>::operator=(array2d<T> &&rhs) {
    if (data != nullptr){
        delete [] data;
        data = nullptr;
    }

    width = rhs.width;
    height = rhs.height;
    data = rhs.data;

    rhs.width = 0;
    rhs.height = 0;
    rhs.data = nullptr;

    return *this;
}

// ******************************************************************************************************************
// Scalar Assignment Operator
// ******************************************************************************************************************
template<typename T>
array2d<T>& array2d<T>::operator=(const T &num) {
    for (size_t i = 0; i<width*height; i++){
        data[i] = num;
    }

    return *this;
}

// ******************************************************************************************************************
// Negation Operator
// ******************************************************************************************************************
template<typename T>
array2d<T> array2d<T>::operator-() const{
    array2d<T> result(width, height);
    for (size_t i = 0; i<width*height; i++){
        result.data[i] = -data[i];
    }

    return result;
}

// ******************************************************************************************************************
// Element-wise Operators
// ******************************************************************************************************************
template<typename T>
array2d<T> array2d<T>::operator*(const array2d<T> &rhs) const{
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i]*rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator/(const array2d<T> &rhs) const{
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i]/rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator+(const array2d<T> &rhs) const{
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i]+rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator-(const array2d<T> &rhs) const{
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i]-rhs.data[i];
    }
    return result;
}
// ******************************************************************************************************************
// Self Element-wise Operators
// ******************************************************************************************************************
template<typename T>
array2d<T>& array2d<T>::operator*=(const array2d<T> &rhs) {
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    for(size_t i = 0; i<width*height; i++){
        data[i] *= rhs.data[i];
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator/=(const array2d<T> &rhs) {
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    for(size_t i = 0; i<width*height; i++){
        data[i] /= rhs.data[i];
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator+=(const array2d<T> &rhs) {
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    for(size_t i = 0; i<width*height; i++){
        data[i] += rhs.data[i];
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator-=(const array2d<T> &rhs) {
    if(width != rhs.width || height != rhs.height){
        throw std::length_error("The widths and heights of the two operands must be the same!");
    }

    for(size_t i = 0; i<width*height; i++){
        data[i] -= rhs.data[i];
    }
    return *this;
}

// ******************************************************************************************************************
// Scalar Operators
// ******************************************************************************************************************
template<typename T>
array2d<T> array2d<T>::operator*(const T &rhs) const{
    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i] * rhs;
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator/(const T &rhs) const{
    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i] / rhs;
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator+(const T &rhs) const{
    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i] + rhs;
    }
    return result;
}

template<typename T>
array2d<T> array2d<T>::operator-(const T &rhs) const{
    array2d<T> result(width, height);
    for(size_t i = 0; i<width*height; i++){
        result.data[i] = data[i] - rhs;
    }
    return result;
}

// ******************************************************************************************************************
// Self Scalar Operators
// ******************************************************************************************************************
template<typename T>
array2d<T>& array2d<T>::operator*=(const T &rhs){
    for(size_t i = 0; i<width*height; i++){
        data[i] *= rhs;
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator/=(const T &rhs){
    for(size_t i = 0; i<width*height; i++){
        data[i] /= rhs;
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator+=(const T &rhs){
    for(size_t i = 0; i<width*height; i++){
        data[i] += rhs;
    }
    return *this;
}

template<typename T>
array2d<T>& array2d<T>::operator-=(const T &rhs){
    for(size_t i = 0; i<width*height; i++){
        data[i] -= rhs;
    }
    return *this;
}

// ******************************************************************************************************************
// Friend Scalar Operators
// ******************************************************************************************************************
template<typename T>
array2d<T> operator*(const T &lhs, const array2d<T> &rhs) {
    array2d<T> result(rhs.width, rhs.height);
    for(size_t i = 0; i<rhs.width*rhs.height; i++){
        result.data[i] = lhs * rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> operator/(const T &lhs, const array2d<T> &rhs) {
    array2d<T> result(rhs.width, rhs.height);
    for(size_t i = 0; i<rhs.width*rhs.height; i++){
        result.data[i] = lhs / rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> operator+(const T &lhs, const array2d<T> &rhs) {
    array2d<T> result(rhs.width, rhs.height);
    for(size_t i = 0; i<rhs.width*rhs.height; i++){
        result.data[i] = lhs + rhs.data[i];
    }
    return result;
}

template<typename T>
array2d<T> operator-(const T &lhs, const array2d<T> &rhs) {
    array2d<T> result(rhs.width, rhs.height);
    for(size_t i = 0; i<rhs.width*rhs.height; i++){
        result.data[i] = lhs - rhs.data[i];
    }
    return result;
}

// ******************************************************************************************************************
// Cast Operator
// ******************************************************************************************************************
template<typename T>
template<typename E>
array2d<T>::operator array2d<E>() const{
    array2d<E> result(width, height);
    for (size_t i=0; i<width*height; i++){
        result[i] = (E)data[i];
    }
    return result;
}

// ******************************************************************************************************************
// std::ostream << Operator
// ******************************************************************************************************************
template<typename T>
std::ostream& operator<<(std::ostream &os, const array2d<T> &rhs){
    os << "[";

    for (size_t y=0; y<rhs.height ; y++){
        os << " ";
        if (y != 0){
            os << " ";
        }

        os << "[ ";

        for (size_t x=0; x<rhs.width; x++){
            os << rhs(y, x);
            if (x != rhs.width - 1) {
                os << ", ";
            }
        }

        os << " ]";

        if (y != rhs.height - 1){
            os << ", " << "\n";
        }
    }
    os<< " ]";
    return os;
}

#endif
