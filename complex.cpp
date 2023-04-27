#include <iostream>
#include <math.h>
#include "complex.h"


complex::complex()
	: real{ 0 }, img{ 0 } {}

complex::complex(float real, float img) noexcept {
	this->real = real;
	this->img = img;
}

complex::complex(float real) noexcept 
	: img{ 0 } {
	this->real = real;
}

complex::complex(complex& other) noexcept {
	this->real = other.get_real();
	this->img = other.get_img();
}

complex::complex(complex const& other) noexcept {
	this->real = other.get_real();
	this->img = other.get_img();
}

void print(complex& number) noexcept {
	std::cout << number.get_real();
	if (number.get_img() > 0)
		std::cout << "+";
	else if (number.get_img() == 0) return;
	std::cout << number.get_img() << "i\n";
}

float complex::get_real() const noexcept {
	return this->real;
}

float complex::get_img() const noexcept {
	return this->img;
}

complex complex::operator+(complex& other) const{
	return complex(this->real + other.get_real(), this->img + other.get_img());
}

complex complex::operator-(complex& other) const {
	return complex(this->real - other.get_real(), this->img - other.get_img());
}

complex complex::operator+(const complex& other) const {
	complex _new(other.get_real(), other.get_img());
	return *this + _new;
}

complex complex::operator-(const complex& other) const {
	complex _new(other.get_real(), other.get_img());
	return *this - _new;
}

complex& complex::operator+=(complex& other) {
	*this = *this + other;
	return *this;
}

complex& complex::operator-=(complex& other) {
	*this = *this - other;
	return *this;
}

complex complex::operator*(complex& other) const {
	float real = this->real * other.get_real() - this->img * other.get_img();
	float img = this->real * other.get_real() + this->img * other.get_img();
	return complex(real, img);
}

complex complex::operator/(complex& other) const {
	float a1 = this->real;
	float a2 = other.get_real();
	float b1 = this->img;
	float b2 = other.get_img();

	float real = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2);
	float img = (a1 * a2 - b1 * b2) / (a2 * a2 + b2 * b2);
	return complex(real, img);
}

complex complex::operator*(const complex& other) const {
	complex _new(other.get_real(), other.get_img());
	return *this * _new;
}

complex complex::operator/(const complex& other) const {
	complex _new(other.get_real(), other.get_img());
	return *this / _new;
}

float complex::modul() const noexcept {
	return sqrt(pow(this->real, 2) + pow(this->img, 2));
}