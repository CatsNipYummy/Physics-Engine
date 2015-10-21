#include "precision.h"
#include "core.h"

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
        
        // Kinectic Energy;
        real kinecticEnergy;
        
    public:
        
        // Setters & Getters
        
        // Mass
        void setMass (const real mass);
        real getMass () const;
        
        // Position
        void setPosition (const Vector3 &position);
        Vector3 getPosition () const;
        
        //Velocity
        void setVelocity (const Vector3 &velocity);
        Vector3 getVelocity () const;
        
        // Acceleration
        void setAcceleration (const Vector3 &position);
        Vector3 getAcceleration () const;
        
        // Damping
        void setDamping (const real damping);
        real getDamping () const;
        
        // Integrates the particle forward in time by the given amount (Using Newton-Euler integration method)
        void integrate(real duration);
        
        // Find the kinetic energy of the particle
        void findKineticEnergy ();
    };
}