#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int whatInt(char *c);

int whatInt(char *c) {
	int asciiCode = (int) *c;
	switch(asciiCode) {
		case 48: return 0;
		case 49: return 1;
		case 50: return 2;
		case 51: return 3;
		case 52: return 4;
		case 53: return 5;
		case 54: return 6;
		case 55: return 7;
		case 56: return 8;
		case 57: return 9;
		default: return -1;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2 && argc != 3) {
		printf("Not enough args or too many args\n");
		return 0;
	}

	char alphabet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*!@$%&";
	int n = sizeof(alphabet) - 1;
	int count = 1;

	if (argv[1][0] == '-')
		if (argv[1][1] == 'a') {
			count = 2;
			n -= 9;
		}

	char *temp;
	int accumulator = 0;

	for (temp=argv[count];*temp!='\0';temp++) {
		int j = whatInt(temp);
		if(j == -1)
			continue;
		accumulator += j;
		accumulator *= 10;
	}
	accumulator /= 10;

	if (accumulator > 1000) {
		printf("Think we might need to cut the size down a tad...\n");
		accumulator = 1000;
	}
	
	time_t t;
	srand((unsigned) time(&t));

	while(accumulator > 0) {
		printf("%c", alphabet[rand() % n]);
		accumulator--;
	}
	printf("\n");
}
