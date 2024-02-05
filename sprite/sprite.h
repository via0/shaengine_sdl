#ifndef SPRITE_H
#define SPRITE_H

// Define your struct
struct Sprite {
    char *name;
    float xValue;
    float yValue;
    // Add more members as needed
};

struct Sprite createSprite(const char *str, float xValue, float yValue);

#endif