//
//  main.cpp
//  Bowthika
//
//  Created by Anil Unnikrishnan on 17/10/15.
//  Copyright © 2015 Anil Unnikrishnan. All rights reserved.
//

#include <iostream>
#include "particle.h"

using namespace bowthika;

int main(int argc, const char * argv[]) {
   
    Particle particleOne, particleTwo;
    particleOne.setPosition(Vector3(1, 2, 3));
    particleOne.setVelocity(Vector3(1, 2, 3));
    particleOne.setAcceleration(Vector3(1, 2, 3));
    particleOne.setDamping(0.8f);
    particleOne.setMass(8.0f);
    particleOne.integrate(10);
    
    return 0;
}
