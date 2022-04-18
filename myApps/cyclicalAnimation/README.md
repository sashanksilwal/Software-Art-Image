# Cyclical Animation

## Description

For this assignment, I tried other iterations as well but stuck with my first assignment and added animation to it. I tried 2 animations, one was using the time elapsed and another was cyclical animation using the sin function. This assignmnet made me realize the power of sine function. 

**Inspiration:** https://www.jenstark.com/vortex

## Code for animation 

```C++

        float time = ofGetElapsedTimef();
        float noise = time * 2 + ofSignedNoise(rotation)  ;
        ofRotate(noise);
        ofDrawRectangle(0, 0, 50, 50);

```

## Video:

![](bin/data/canimation.gif)

## Code for cyclical animation

Here, the value of sine is used to oscillate the rotation between 0 to 90 degrees.

```C++

        float time = ofGetElapsedTimef();
        float noise = time * 2 + ofSignedNoise(rotation)  ;
        ofRotate(ofMap(sin(noise), -1, 1, 0, 90));
        ofDrawRectangle(0, 0, 50, 50);

```

## Video

![](bin/data/animaiton.gif)

