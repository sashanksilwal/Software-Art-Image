# Still


## Description

Spirals in Nature: [Galaxies](https://www.google.com/url?sa=i&url=https%3A%2F%2Fpixabay.com%2Fimages%2Fsearch%2Fspiral%2520galaxy%2F&psig=AOvVaw2CjqWG3u-D5-Xn58MVfgyb&ust=1649760452165000&source=images&cd=vfe&ved=0CAcQjRxqFwoTCMCohOLqi_cCFQAAAAAdAAAAABAI), [Ocean](https://www.worldatlas.com/r/w960-q80/upload/fc/ab/9b/shutterstock-1038169048.jpg), [Thumb Print](https://thumbs.dreamstime.com/b/human-fingerprint-finger-print-biometric-scan-line-art-vector-icon-apps-websites-human-fingerprint-finger-print-162436744.jpg)

For this assignment, I took inspiration from Jan Stark's  [Vortex](https://www.jenstark.com/vortex) which was posted on the course discussion on Brightspace. I tried to replicated similar patters which can then be controlled by sliders to generate unique patterns. I figured the colors for the shapes also give rise to different emotions hence the user can select that too.

**Inspiration:** https://www.jenstark.com/vortex

## Code

I started by looking for help in the of book chapter **[Into To Graphis](http://openframeworks.kr/ofBook/chapters/intro_to_graphics.html)** which 

```

for (int i=0; i<100; i++) {
        
        int val = i;
        val = val % colorVal;
        ofColor c;
        
        c.setHsb(ofMap(val, 0, 10, 0, 255), 255, 255, 255);
        ofSetColor(c);
        ofNoFill();
        
        // Draw the smallest rectangle first and scale out to bigger ones progressively
        ofScale(1.1, 1.1);

        
        float noise = ofSignedNoise(rotation) * 20.0;
        ofRotate(noise);

        ofDrawRectangle(0, 0, 50, 50);
    }
 
 
 ```

## Reflection 

shapes: The sharp lines 

color: what feeling are your colors supposed to convey? are they deliberately dissonant or consonant? what medium did you decide to display it on?

rules: what is/are the rule/s that you decided upon to make this series? how obvious are they? what is the input? how much/little diversity does it offer?

write-up: explain your creative process, your inspirations and your decision to stop at a certain point. are you satisfied with the work (it's ok not to be)? did you achieve what you expected? did you end up somewhere unexpected?

## Screenshots

![](bin/data/s_1.png)




![](bin/data/s_2.png)



![](bin/data/s_3.png)



![](bin/data/s_4.png)
