# Assignment2: Animation

## Description:


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


Video:

https://user-images.githubusercontent.com/25387553/165071962-3abc7c2d-6cd6-43c5-9c04-ad0886ab5d53.mov

