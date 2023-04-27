#include <iostream>
#include <math.h>
#include "complex.h"


complex::complex() noexcept
	: real{ 0 }, img{ 0 } {}

complex::complex(float real, float img) noexcept
	:real{ real }, img{ img } {}

complex::complex(float real) noexcept
	: real{ real }, img{ 0 } {}

complex::complex(complex& other) noexcept
	: real{ other.get_real() }, img{ other.get_img()} {}

complex::complex(const complex& other) noexcept
	: real{ other.get_real() }, img{ other.get_img() } {}

std::ostream& operator<<(std::ostream& os, const complex& number) {
	os << number.real;
	if (number.img > 0)
		os << "+";
	else if (number.img == 0) return os;
	os << number.img << "i";
	return os;
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
	float img = this->img * other.get_real() + this->real * other.get_img();
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