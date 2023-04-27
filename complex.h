#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

class complex {
	float real;
	float img;

public:
	complex() noexcept;

	explicit complex(float real, float img) noexcept;

	explicit complex(float real) noexcept;

	complex(complex &other) noexcept;

	complex(complex const &other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const complex& number);

	float get_real() const noexcept;

	float get_img() const noexcept;

	complex operator+(complex& other) const;

	complex operator-(complex& other) const;

	complex operator+(const complex& other) const;

	complex operator-(const complex& other) const;

	complex& operator+=(complex& other);

	complex& operator-=(complex& other);

	complex operator*(complex& other) const;

	complex operator/(complex& other) const;

	complex operator*(const complex& other) const;

	complex operator/(const complex& other) const;

	float modul() const noexcept; // TODO name may be changed
};

#endif // !COMPLEX_H

