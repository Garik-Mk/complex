#include <iostream>

#ifndef COMPLEX
#define COMPLEX

#define NODISCARD [[nodiscard]]

class complex {
	float real;
	float img;

public:
	complex() noexcept
		: real{ 0 }, img{ 0 } {}

	explicit complex(float real, float img) noexcept;

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
};

#endif // !COMPLEX

