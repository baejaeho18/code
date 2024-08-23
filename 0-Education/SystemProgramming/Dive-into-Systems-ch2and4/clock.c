#include <stdio.h>

typedef struct {
    int hr, min, sec;
} CLOCK;

void increment(CLOCK* pClock);
void show(CLOCK* pClock);

int main(void)
{
    int i = 0;

    CLOCK clock = { 14, 38, 56 };

    for (i = 0; i < 6; ++i) {
        increment(&clock);
        show(&clock);
    } // for

    return 0;
}	// main 

// This function increments the time by one second.
void increment(pClock* pClock)
{
    (pClock->sec)++;
    if (pClock->sec == 60) {
        pClock->sec = 0;
        (pClock->min)++;
        if (pClock->min == 60) {
            pClock->min = 0;
            (pClock->hr)++;
            if (pClock->hr == 24)
                pClock->hr = 0;
        } // if 60 min
    } // if 60 sec
}	// increment

// This function shows the current time in military form.
void show(pClock* pClock)
{
    printf("%02d:%02d:%02d\n",
        pClock->hr, pClock->min, pClock->sec);
}	// show
