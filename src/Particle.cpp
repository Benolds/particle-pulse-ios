//
//  Particle.cpp
//  MAVPA
//
//  Created by Benjamin Reynolds on 10/31/14.
//
//

#include "Particle.h"
#include "Constants.h"
//#include "Utils.h"

//Particle::Particle()
//{
//    cout << "don't use this";
//}

Particle::Particle(float i_radius, ofColor i_col, ofVec2f i_pos, ofVec2f i_vel, ofVec2f i_accel, int i_lifetime)
{
    this->radius = i_radius;
    this->baseRadius = i_radius;
    this->col = i_col;
    this->pos = i_pos;
    this->vel = i_vel;
    this->accel = i_accel;
    this->numNeighbors = 0;
    this->lifetime = i_lifetime;
    this->baseLifetime = i_lifetime;
    this->flagForRemoval = false;
    this->volumeScale = 1.0f;
}

void Particle::update()
{
    accel *= bbAccelDamping;
    vel = ofVec2f(vel.x + accel.x, vel.y + accel.y);
    pos = ofVec2f(vel.x + pos.x, vel.y + pos.y);
    
    lifetime--;
}

void Particle::postUpdate()
{
    for (Particle* n : neighbors)
    {
        ofVec2f dPos = n->pos - pos;
        accel += (dPos * 0.01);
    }
    
    float destinationRadius = baseRadius / pow((1.0f + numNeighbors), 0.33f) * lifetime/baseLifetime;
    destinationRadius *= (volumeScale * volumeScale);
    radius = this->lerpVal(radius, destinationRadius, 0.2f);
}

void Particle::draw()
{
    this->drawLinesToNeighbors();
    ofSetColor(col, 100);
    ofCircle(pos.x, pos.y, radius);
}

void Particle::drawLinesToNeighbors()
{
    for( Particle* n : neighbors){
        float dist = (pos - n->pos).length();
        ofSetLineWidth(((bbNeighborThreshold+neighborThresholdAdjustment)-dist)/(bbNeighborThreshold+neighborThresholdAdjustment));
        ofSetColor(col, 10);
        ofLine(pos.x, pos.y, n->pos.x, n->pos.y);
    }
}

void Particle::clearNeighbors()
{
    neighbors.clear();
    numNeighbors = 0;
}

void Particle::addNeighbor(Particle* p)
{
    neighbors.push_back(p);
    numNeighbors++;
}

float Particle::lerpVal(float current, float destination, float percent)
{
    return percent * destination + (1.0f - percent) * current;
}

void Particle::setVolumeScale(float volume)
{
    volumeScale = 1.0f + MIN(1.0f, MAX(0.0f, (log2(abs(volume*1028.0f)))));
//    cout << volume << " " << volumeScale << "\n";
}


