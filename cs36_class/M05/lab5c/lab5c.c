#include <stdio.h>

typedef struct {
   int hour;
   int min;
   int sec;
} Time;

Time elapsedTime(Time s, Time e);

int main() {
   Time time1, time2, time3, time4;
   Time elapsed1, elapsed2;

   printf("This program calculates elapsed time between two pairs of times.\n\n");

   printf("Enter time 1 (hour min sec): ");
   scanf("%d %d %d", &time1.hour, &time1.min, &time1.sec);

   printf("Enter time 2 (hour min sec): ");
   scanf("%d %d %d", &time2.hour, &time2.min, &time2.sec);

   printf("Enter time 3 (hour min sec): ");
   scanf("%d %d %d", &time3.hour, &time3.min, &time3.sec);

   printf("Enter time 4 (hour min sec, earlier than time 3): ");
   scanf("%d %d %d", &time4.hour, &time4.min, &time4.sec);

   elapsed1 = elapsedTime(time1, time2);
   elapsed2 = elapsedTime(time4, time3);

   printf("\nResults:\n");
   printf("Elapsed time between first and second input: %02d:%02d:%02d\n", 
          elapsed1.hour, elapsed1.min, elapsed1.sec);
   printf("Elapsed time between fourth and third input: %02d:%02d:%02d\n", 
          elapsed2.hour, elapsed2.min, elapsed2.sec);
}

Time elapsedTime(Time s, Time e) {
   Time elapsed;
   int sSeconds, eSeconds, dSeconds;

   sSeconds = s.hour * 3600 + s.min * 60 + s.sec;
   eSeconds = e.hour * 3600 + e.min * 60 + e.sec;

   if (eSeconds < sSeconds) {
     eSeconds += 24 * 3600;
   }

   dSeconds = eSeconds - sSeconds;

   elapsed.hour = dSeconds / 3600;
   elapsed.min = (dSeconds % 3600) / 60;
   elapsed.sec = dSeconds % 60;

   return elapsed;
}
