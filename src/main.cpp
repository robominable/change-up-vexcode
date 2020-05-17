#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

}

//MOTOR INITS
const int LIFT_MOTOR_PORT = 6;

ControllerButton btnUp(ControllerDigital::R1);
ControllerButton btnDown(ControllerDigital::R2);
Motor lift(LIFT_MOTOR_PORT);

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}


void autonomous() {}

void opcontrol() {
	while (true) {
		if (btnUp.isPressed()) {
			lift.moveVoltage(12000);
		}
		else if (btnDown.isPressed()) {
			lift.moveVoltage(-12000);
		}
		else {
			lift.moveVoltage(0);
		}

		pros::delay(10);
	}
}
