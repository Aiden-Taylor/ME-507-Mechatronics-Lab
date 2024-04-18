/*
 * motor_driver.c
 *
 *  Created on: Apr 18, 2024
 *      Author: Aiden
 */
#include "motor_driver.h"
// The implementation of the motor object method should go in the .c file
void set_duty(motor_t* p_mot, int32_t duty)
{
    // Print to the console so we can see what's happening
    printf("Setting Motor Duty Cycle to %d", duty);

    // Assign the duty cycle to a field in the structure
    p_mot->duty = duty;
	if (duty>=0){
		duty = duty*265/100;
		p_mot->timer->CCR1 = duty;
		p_mot->timer->CCR2 = 0;
	}
	else{
		duty = -1*duty*265/100;
		p_mot->timer->CCR1 = 0;
		p_mot->timer->CCR2 = duty;
	}


    // The arrow operator is shorthand for
    // dereferencing and accessing struct fields
    // p_mot->duty = duty;
    // is shorthand for
    // (*p_mot).duty = duty;
}

