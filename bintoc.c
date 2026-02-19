#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("No argument supplied.\n");
		exit(1);
	} else if (argc > 2) {
		printf("Too many arguments supplied.\n");
		exit(1);
	}

	int value = 0;

	int i = 0; // Count bits in the binary data
	while(argv[1][i] != '\0') {
		if (argv[1][i] != '1' && argv[1][i] != '0') {
			printf("Argument must only contain bits\n");
			exit(1);
		}
		i++;
	}
	i--; // adjust i to correspond with bit position, e.g. 0 through 7
	int j = 0;
	while (argv[1][j] != '\0') {
		if (argv[1][j] == '1') 
			value += 1 << i;
		i--;
		j++;
	}

	printf("%c\n", value);
	return 0;
}
