#include <stdio.h>
#include "./sprite/sprite.h"

int main() {

	struct Sprite shaeSprite = createSprite("Shae", 0.0, 0.0);
	printf("Name: %s\n", shaeSprite.name);
	printf("XValue: %f\n", shaeSprite.xValue);
    printf("Yvalue: %f\n", shaeSprite.yValue);


	//Listener
	// while (1) {
    // look into Ncruses for key mapping
    // }

    return 0;
}
