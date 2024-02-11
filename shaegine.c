#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "./sprite/sprite.h"

void disable_canonical_mode() {
	struct termios new_termios;
	tcgetattr(0, &new_termios);
	new_termios.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &new_termios);
}

// Function to restore canonical mode for terminal input
void enable_canonical_mode() {
	struct termios new_termios;
	tcgetattr(0, &new_termios);
	new_termios.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &new_termios);
}

int main() {

	struct Sprite shaeSprite = createSprite("Shae", 0.0, 0.0);
	printf("Name: %s\n", shaeSprite.name);
	printf("XValue: %f\n", shaeSprite.xValue);
    printf("Yvalue: %f\n", shaeSprite.yValue);

	char c;

    // Disable canonical mode
    disable_canonical_mode();

	 while (1) {
        // Read a character from stdin
        if (read(STDIN_FILENO, &c, 1) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Check if the character is 'q', then exit the loop
        if (c == 'q') {
            printf("Exiting...\n");
            break;
        }

        // Print the pressed key
        printf("You pressed: %c\n", c);
    }

    return 0;
}
