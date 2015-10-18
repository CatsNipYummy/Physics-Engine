#include "precision.h"

namespace bowthika {
	/*
		Holds a vector in three dimensions. The fourth data member is for optimisation
	*/

	class Vector3
	{
	public:
		real x;
		real y;
		real z;

	private:
		real _pad;

	public:
		// Default constructor creates a zero vector (Vector3 without arguments)
		Vector3() : x(0), y(0), z(0) {}

		// The explicit constructor creates a vector with the given components
		Vector3(const real x, const real y, const real z)
			: x(x), y(y), z(z) {}

		// Flip all the components of the vector
		void invert() {
			x = -x;
			y = -y;
			z = -z;
		}

		// Gets the magnitude of this vector
		real magnitude() const {
			return real_sqrt(x*x + y*y + z*z);
		}

		// Gets the squared magnitude of this vector
		real squareMagnitude() const {
			return x*x + y*y + z*z;
		}

		// Turns this vector into a vector of unit length
		void normalize() {

		}
	};
}