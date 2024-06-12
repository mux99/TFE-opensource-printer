#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <math.h>
#include <wiringPi.h>


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

#define steps_per_revolution 200

struct Stepper {
    int gpio_step;      //gpio pin 'step'
    int gpio_direction; //gpio pin 'dir'
    pid_t move_pid;
};

void servo_move(struct Stepper stepper, int speed_dps, int angle)
{
    int steps = (int)((abs(angle) / 360.0) * steps_per_revolution);
    digitalWrite(stepper.gpio_direction, angle > 0);

    // Calculate the step delay in microseconds
    // Speed is given in degrees per second
    float step_delay = (1.0 / ((speed_dps / 360.0) * steps_per_revolution)) * 1e6;

    // Generate the pulses to move the stepper motor
    for (int i = 0; i < steps; i++) {
        digitalWrite(stepper.gpio_step, 1);
        usleep(step_delay / 2);
        digitalWrite(stepper.gpio_step, 0);
        usleep(step_delay / 2);
    }
}

int setup()
{
    if (wiringPiSetupGpio() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return -1;
    }

    pinMode(m1_step, OUTPUT);
    digitalWrite(m1_step, 0);
    pinMode(m1_dir, OUTPUT);
    digitalWrite(m1_dir, 0);
    pinMode(m2_step, OUTPUT);
    digitalWrite(m2_step, 0);
    pinMode(m2_dir, OUTPUT);
    digitalWrite(m2_dir, 0);
    pinMode(m3_step, OUTPUT);
    digitalWrite(m3_step, 0);
    pinMode(m3_dir, OUTPUT);
    digitalWrite(m3_dir, 0);

    pinMode(d1, OUTPUT);
    digitalWrite(d1, 0);
    pinMode(d2, OUTPUT);
    digitalWrite(d2, 0);
    pinMode(d3, OUTPUT);
    digitalWrite(d3, 0);
    pinMode(csync, OUTPUT);
    digitalWrite(csync, 0);

    pinMode(s1, OUTPUT);
    digitalWrite(s1,0);
    pinMode(s2, OUTPUT);
    digitalWrite(s2,0);
    pinMode(s3, OUTPUT);
    digitalWrite(s3,0);
    pinMode(s4, OUTPUT);
    digitalWrite(s4,0);
    pinMode(s5, OUTPUT);
    digitalWrite(s5,0);
    pinMode(f3, OUTPUT);
    digitalWrite(f3,0);
    pinMode(f5, OUTPUT);
    digitalWrite(f5,0);
    pinMode(dclk, OUTPUT);
    digitalWrite(dclk,0);
    
}

int main(int argc, char *argv[])
{
    if (setup() < 0) {
        return 1;
    }
    
    struct Stepper motor_picker;
    motor_picker.gpio_direction = m1_dir;
    motor_picker.gpio_step = m1_step;

    struct Stepper motor_feeder;
    motor_feeder.gpio_direction = m2_dir;
    motor_feeder.gpio_step = m2_step;

    struct Stepper motor_head;
    motor_head.gpio_direction = m3_dir;
    motor_head.gpio_step = m3_step;


}
