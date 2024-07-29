#include <stdio.h>

#define PI 3.1415

#define VOLUME_OF_SPHERE(r) ((4.0 / 3.0) * PI * (r) * (r) * (r))

#define FOR_LOOP_10 for (int i = 1; i <= 10; i++)

int main() {
    printf("Radius\tVolume\n");
    printf("---------------\n");
    
    FOR_LOOP_10 {
        printf("%d\t%.4f\n", i, VOLUME_OF_SPHERE(i));
    }

    return 0;
}
