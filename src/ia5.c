#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char** argv)
{
	int tmp;
	int min = INT_MAX;
	int max = INT_MIN;

	if(argc == 1) {
		printf("No argument provided\n");
		return 0;
	}
	
	for(int i = 1; i < argc; i++) {
		if(!check_string_numeric(argv[i])) {
			continue;
		}

		tmp = atoi(argv[i]);
		if (tmp < min) {
			min = tmp;
		}
		if (tmp > max) {
			max = tmp;
		}

	}

	if (min == INT_MAX && max == INT_MIN) {
		perror("Arguments are invalid!");
		return 1;
	}

	printf("Maximum element is %d\nMinimum element is %d\n", max, min);

	return 0;
}