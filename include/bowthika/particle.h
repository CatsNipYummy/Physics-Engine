#include "precision.h"

namespace bowthika {
    class Particle {
    protected:
        
        // Holds the linear position of the particle in world space
        Vector3 position;
        
        // Holds the linear velocity of the particle in world space
        Vector3 velocity;
        
        // Holds the acceleration of the particle (can be the acceleration due to gravity or any other constant acceleration
        Vector3 acceleration;
        
        // Damping is used to reduce the inaccurate increase in the energy due to integrators
        real damping;
        
        // Holds the inverse of the mass (1/mass). Easier during integration
        real inverseMass;
    };
}