//
//  Particle.h
//  MAVPA
//
//  Created by Benjamin Reynolds on 10/31/14.
//
//

#ifndef __MAVPA__Particle__
#define __MAVPA__Particle__

#include <stdio.h>
#include "ofMain.h"

class Particle {
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    ofColor col;
    float radius;
    float baseRadius;
    int lifetime;
    int baseLifetime;
    bool flagForRemoval;
    float volumeScale;
    
//    Particle();
    Particle(float i_radius, ofColor i_col, ofVec2f i_pos, ofVec2f i_vel, ofVec2f i_accel, int i_lifetime);
    void update();
    void postUpdate();
    void draw();
    void drawLinesToNeighbors();
    
    std::vector<Particle *>neighbors;
    int numNeighbors;
    void clearNeighbors();
    void addNeighbor(Particle *);
    float lerpVal(float current, float destination, float percent);
    void setVolumeScale(float volume);
    
    float neighborThresholdAdjustment;
};

#endif /* defined(__MAVPA__Particle__) */
