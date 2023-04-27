#include <iostream>

#ifndef COMPLEX
#define COMPLEX

class complex {
	float real;
	float img;

public:
	complex() noexcept;

	explicit complex(float real, float img) noexcept;

	explicit complex(float real) noexcept;

	complex(complex &other) noexcept;

	complex(complex const &other) noexcept;

	friend void print(complex& number) noexcept;

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

	float modul() const noexcept;
};

#endif // !COMPLEX

