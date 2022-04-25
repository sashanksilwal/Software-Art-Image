# Assignment2: Animation

## Description:

For this assignment, I wanted to create an animation that is also a form of audio visualizer. To understand how sound is played on openFrameworks, I followed this tutorial: https://www.youtube.com/watch?v=SSEnu6mp7y8. Once, I understood about the the sound spectrum and getting the bands of sound from the spectrum. 

For the sound I chose a claming music and chose pastel colors that go along the sound to give a calming, peaceful effect. The concept of the art piece came from the fact that students get more stressted as we approach the finals week so this art piece was my approach to a motion work that would envoke peaceful emotions on the audience.


## Code:


Class Particle 
```C++


class particle{
public:
    float size;
    glm::vec2 force, position, direction;
    
    void update();
    void draw();
    ofColor color;
    
    particle(int x, int y, int hue);
    ~particle();
};

```

Condition to create a particle object 
```C++


if (fft[i] > 0.06){

    particle newParticles(ofGetWindowWidth()/2, ofGetWindowHeight()/2, hue);
    particles.push_back(newParticles);
}

```

Condition to remove particles from the vector

```c++

for (int i=0; i<particles.size(); i++){
    particles[i].update();

    if (particles[i].size <= 0){

        particles.erase( particles.begin(), particles.begin()+i);
    }
}

```


### Video:

https://user-images.githubusercontent.com/25387553/165071962-3abc7c2d-6cd6-43c5-9c04-ad0886ab5d53.mov


## Reflection

I am satisfied with the work that I could come up with, however, I would like to also incorporate audio input from the viewer and also let the viewer choose their own audio.

