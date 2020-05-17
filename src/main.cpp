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
const int LIFT2_MOTOR_PORT = 7;

ControllerButton btnUp(ControllerDigital::R1);
ControllerButton btnDown(ControllerDigital::R2);
Motor lift(LIFT_MOTOR_PORT);
Motor lift2(LIFT2_MOTOR_PORT);

//LIFT2 POSITIONS
const int NUM_HEIGHTS_LIFT2 = 4;
const int height1_LIFT2 = 2000;
const int height2_LIFT2 = 4000;
const int height3_LIFT2 = 6000;
const int height4_LIFT2 = 8000;

const int HEIGHTS_LIFT2[NUM_HEIGHTS_LIFT2] = {height1_LIFT2, height2_LIFT2, height3_LIFT2, height4_LIFT2};
ControllerButton btnLIFT2up(ControllerDigital::L1);
ControllerButton btnLIFT2down(ControllerDigital::L2);
std::shared_ptr<AsyncPositionController<double, double>> liftControl =
	AsyncPosControllerBuilder().withMotor(LIFT2_MOTOR_PORT).build();

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
	int goalHeight = 0;

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

		if (btnLIFT2up.changedToPressed() && goalHeight < NUM_HEIGHTS_LIFT2 - 1) {
      // If the goal height is not at maximum and the up button is pressed, increase the setpoint
      goalHeight++;
      liftControl->setTarget(HEIGHTS_LIFT2[goalHeight]);
    } else if (btnLIFT2down.changedToPressed() && goalHeight > 0) {
      goalHeight--;
      liftControl->setTarget(HEIGHTS_LIFT2[goalHeight]);
    }

		pros::delay(10);
	}
}
