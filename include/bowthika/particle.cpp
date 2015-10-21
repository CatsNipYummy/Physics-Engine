//
//  particle.cpp
//  Bowthika
//
//  Created by Anil Unnikrishnan on 21/10/15.
//  Copyright © 2015 Anil Unnikrishnan. All rights reserved.
//

#include "particle.h"
#include <assert.h>

using namespace bowthika;

void Particle::integrate(real duration) {
    if (inverseMass <= 0.0f) return;
    
    assert(duration > 0.0);
    
    // Update linear position
    position.addScaledVector(velocity, duration);
    
    Vector3 resultingAcceleration = acceleration;
    
    // Update linear velocity from the acceleration
    velocity.addScaledVector(resultingAcceleration, duration);
    
    // Impose Drag
    velocity *= real_pow(damping, duration);
        
    // Clear the forces
//    clearAccumulator();
}

// Kinetic Energy
void Particle::findKineticEnergy () {
    real mass = 1/inverseMass;
    
    kinecticEnergy = 0.5 * mass * real_pow((velocity.magnitude()), 2);
}

// Setters & Getters

// Mass
void Particle::setMass(const real newMass) {
    if (newMass > 0) {
        inverseMass = 1/newMass;
    }
}

real Particle::getMass() const {
    return 1/inverseMass;
}

// Position
void Particle::setPosition(const Vector3 &position) {
    Particle::position = position;
}

Vector3 Particle::getPosition() const {
    return position;
}

// Velocity
void Particle::setVelocity(const Vector3 &velocity) {
    Particle::velocity = velocity;
}

Vector3 Particle::getVelocity() const {
    return velocity;
}

// Acceleration
void Particle::setAcceleration(const Vector3 &acceleration) {
    Particle::acceleration = acceleration;
}

Vector3 Particle::getAcceleration() const {
    return acceleration;
}

// Damping
void Particle::setDamping(const real damping) {
    Particle::damping = damping;
}

real Particle::getDamping() const {
    return damping;
}
