#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motor.h"

//function for initialization of the PWM ports
void initPWMPorts(){
	
	//defining the PWM  pins for outputs
	DATA_DIRECTION_MOTOR_PWM |= (1 << DDB1);
	DATA_DIRECTION_MOTOR_PWM |= (1 << DDB2);

	// set PWM for 50% duty cycle @ 10bit
	OCR1A = 0x4FFF;
	OCR1B =	0x4FFF;
	
	// set none-inverting mode
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
	
	// set 10bit phase corrected PWM Mode
	TCCR1A |= (1 << WGM11) | (1 << WGM10);
	TCCR1B |= (1 << WGM11) | (1 << WGM10);
	
	// set prescaler to 8 and starts PWM
	TCCR1B |= (1 << CS11);
}

//function for initialization of the motor control ports
void initControlPorts(){
	//defining the ports to be output control of the motor
	DATA_DIRECTION_MOTOR_CONTROL |= 0x35;
	
	//initially making the motor disabled 
	DATA_OUTPUT_MOTOR_CONTROL |= (1<<PIND2) | (1<<PIND5); 
	
	//and two control pins output low
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<<PIND0);
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<<PIND4);
}


void enableMotor(){
	DATA_OUTPUT_MOTOR_CONTROL |= (1<<PIND2) | (1<<PIND5);
}
void disableMotor(){
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<< PIND2);
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<< PIND5);
}



//funcion to stop both the motors
void staySteady(){
	//just disable the motors 
	disableMotor();
}

void turnLeft(){
	//to turn left the motor just disable one and enable other
	DATA_OUTPUT_MOTOR_CONTROL |= (1<<PIND2);
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<< PIND5);
	
}
void turnRight(){
	//to turn left the motor just disable one and enable other
	DATA_OUTPUT_MOTOR_CONTROL |= (1<<PIND5);
	DATA_OUTPUT_MOTOR_CONTROL &= ~(1<< PIND2);
}
//function to rotate both the motors
void goAhead(){
	enableMotor();
}
