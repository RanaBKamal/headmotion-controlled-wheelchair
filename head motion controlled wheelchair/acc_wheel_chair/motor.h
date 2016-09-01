#ifndef motor
#define motor
//your header code goes here

//define MACROS
#define DATA_DIRECTION_MOTOR_CONTROL DDRD
#define DATA_OUTPUT_MOTOR_CONTROL PORTD
#define	DATA_DIRECTION_MOTOR_PWM DDRB
#define DATA_OUPUT_MOTOR_PWM PORTB

extern void initPWMPorts();
extern void initControlPorts();

extern void enableMotor();
extern void disableMotor();
extern void staySteady();
extern void goAhead();
extern void turnLeft();
extern void turnRight();

//define functions




#endif