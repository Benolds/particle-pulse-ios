#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "Particle.h"

class ofApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    
    private:
        ofVec2f mousePos;
        std::vector<Particle *>particles;
        void wrapOnScreenBounds(Particle* p);
        void countNeighbors(Particle* p, float threshold);
        ofVec2f getWindowCenter();
        ofVec2f getMouseToCenter();
        //        ofVec2f getPerpendicularVector(ofVec2f startVec);
        //        ofVec2f addNoiseToVec(ofVec2f baseVec, float dMult, float dAdd);
        void spawnRandomParticles(int numToSpawn);
        void spawnVolumeBasedParticles();
        void mergeIfNeeded(Particle* p, float mergeThreshold);
        
        //audio
        ofSoundStream soundStream;
//        void audioReceived(float *input, int bufferSize, int nChannels);
        
        float rawVolume;
        float volumePercent;
        std::vector<float> lastInput;
        std::vector<float> last2Input;
        
        ofSoundPlayer soundPlayer;
        
        float neighborThresholdAdjustment;
        
        int counter;
        std::vector<float>volumeHistory;
        
        float maxVol;
        float scaleFactor;
        
        void drawSnowflakeHistogram(float baseHeight);
        void drawHistogram(float baseHeight, bool leftToRight, bool bottomToTop);
        


};


