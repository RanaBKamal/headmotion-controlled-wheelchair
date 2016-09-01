/*
 * acc_wheel_chair.c
 *
 * Created: 8/20/2016 10:00:25 AM
 *  Author: fthkrch
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "motor.h"
#include "accelerometer.h"
#define F_CPU 1000000

int main(void)
{
	
	
	initPWMPorts();
	initControlPorts();
	initAccelerometerPorts();
	staySteady();
	_delay_ms(2000);
	uint16_t x,y,z;
    while(1)
    {
		x = readAdc(0);
		y = readAdc(1);
		z = readAdc(2);
		
		
        if (x > 350)
        {
			turnRight();	
        }else if (x < 333)
        {
			turnLeft();
        }else if(y < 333){
			goAhead();
		}else{
			staySteady();
		}
		
    }
}