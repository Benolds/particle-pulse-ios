//
//  Utils.h
//  MAVPA
//
//  Created by Benjamin Reynolds on 11/1/14.
//
//

#ifndef MAVPA_Utils_h
#define MAVPA_Utils_h


//ofVec2f getWindowCenter()
//{
//    return ofVec2f(ofGetWindowWidth()*0.5f, ofGetWindowHeight()*0.5f);
//}

//ofVec2f getDistToCenter(ofVec2f vec)
//{
//    ofVec2f windowCenter = getWindowCenter();
//    return ofVec2f(vec.x - windowCenter.x, vec.y - windowCenter.y);
//}

ofVec2f getPerpendicularVector(ofVec2f startVec)
{
    return ofVec2f(startVec.y, -1 * startVec.x);
}

ofVec2f addNoiseToVec(ofVec2f baseVec, float dMult, float dAdd){
    float randMult = 1.0f + (dMult * ofRandom(-1.0f, 1.0f));
    float randAdd = dAdd * ofRandom(-1.0f, 1.0f);
    ofVec2f retVal = ofVec2f(baseVec.x * randMult + randAdd, baseVec.y * randMult + randAdd);
    return retVal;
}

float lerpVal(float current, float destination, float percent)
{
    return percent * destination + (1.0f - percent) * current;
}

#endif
