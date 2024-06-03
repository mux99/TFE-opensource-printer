#include <stdio.h>
#include <pigpio.h>

#define m1_step 2
#define m1_dir 3
#define m2_step 4
#define m2_dir 17
#define m3_step 27
#define m3_dir 22

#define d1 25
#define d2 8
#define d3 7
#define csync 1

#define s1 9
#define s2 11
#define s3 0
#define s4 5
#define s5 6
#define f3 13
#define f5 19
#define dclk 26

#define stepper_angle

int setup()
{
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return -1;
    }

    gpioSetMode(m1_step, PI_OUTPUT);
    gpioWrite(m1_step, 0);
    gpioSetMode(m1_dir, PI_OUTPUT);
    gpioWrite(m1_dir, 0);
    gpioSetMode(m2_step, PI_OUTPUT);
    gpioWrite(m2_step, 0);
    gpioSetMode(m2_dir, PI_OUTPUT);
    gpioWrite(m2_dir, 0);
    gpioSetMode(m3_step, PI_OUTPUT);
    gpioWrite(m3_step, 0);
    gpioSetMode(m3_dir, PI_OUTPUT);
    gpioWrite(m3_dir, 0);

    gpioSetMode(d1, PI_OUTPUT);
    gpioWrite(d1, 0);
    gpioSetMode(d2, PI_OUTPUT);
    gpioWrite(d2, 0);
    gpioSetMode(d3, PI_OUTPUT);
    gpioWrite(d3, 0);
    gpioSetMode(csync, PI_OUTPUT);
    gpioWrite(csync, 0);

    gpioSetMode(s1, PI_OUTPUT);
    gpioWrite(s1,0);
    gpioSetMode(s2, PI_OUTPUT);
    gpioWrite(s2,0);
    gpioSetMode(s3, PI_OUTPUT);
    gpioWrite(s3,0);
    gpioSetMode(s4, PI_OUTPUT);
    gpioWrite(s4,0);
    gpioSetMode(s5, PI_OUTPUT);
    gpioWrite(s5,0);
    gpioSetMode(f3, PI_OUTPUT);
    gpioWrite(f3,0);
    gpioSetMode(f5, PI_OUTPUT);
    gpioWrite(f5,0);
    gpioSetMode(dclk, PI_OUTPUT);
    gpioWrite(dclk,0);
    
}

int test()
{

}

int print()
{

}

int main(int argc, char *argv[])
{

}