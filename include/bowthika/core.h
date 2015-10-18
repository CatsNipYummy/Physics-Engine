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
            real magnitudeValue = magnitude();
            if (magnitudeValue > 0) {
                (*this) *= ((real)1)/magnitudeValue;
            }
		}
        
        /* Operator overload to allow scalar multiplication across the vector
           aV = a*V (a being the scalar)
         */
        
        void operator*=(const real value) {
            x *= value;
            y *= value;
            z *= value;
        }
        
        // Returns the copy of the scaled vector value
        Vector3 operator*(const real value) const {
            return Vector3(x*value, y*value, z*value);
        }
        
        // Vector3 Addition
        void operator += (const Vector3& vector) {
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }
        
        // Returns the value of the given vector added to this vector
        Vector3 operator + (const Vector3& vector) const {
            return Vector3(x + vector.x, y + vector.y, z + vector.z);
        }
        
        // Vector3 Subtraction
        void operator -= (const Vector3& vector){
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;
        }
        
        // Returns the value of the given vector subtracted from this vector
        Vector3 operator - (const Vector3& vector) const {
            return Vector3(x - vector.x, y - vector.y, z - vector.z);
        }
        
        // Adds the given vector scaled by the given about to this vector (A + cB)
        void addScaledVector(const Vector3& vector, real scale) {
            x += scale * vector.x;
            y += scale * vector.y;
            z += scale * vector.z;
        }
	};
}