#include <stdio.h>
#include <string.h>
#include "sprite.h"

// Function definition
struct Sprite createSprite(const char *str, float xValue, float yValue) {
    struct Sprite result;

	result.name = strdup(str);

    result.xValue = xValue;
    result.yValue = yValue;
	
    return result;
}