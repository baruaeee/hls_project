#include <stdio.h>
#include "fir_filter.h"

int main(){
	// averaging filter (low pass)
	data_t h[N_TAPS] = {0.25, 0.25, 0.25, 0.25};
	data_t x, y;

	// Send a "Pulse": 0, 0, 1, 0, 0, 0 ....
	for (int i = 0; i<10; i++){
		if (i==3)
			x = 1.0;
		else
			x = 0.0;
		fir_filter(&y, x, h);
		printf("Input: %f, Output: %f\n", (float)x, (float)y);
		fflush(stdout);
	}
	return 0;
}
