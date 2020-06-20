#include "main.h"


lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style

static lv_res_t btn_click_action(lv_obj_t * btn)
{
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(myLabel, buffer);
    }

    return LV_RES_OK;
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	lv_style_copy(&myButtonStyleREL, &lv_style_plain);
  myButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0, 0);
  myButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0, 150);
  myButtonStyleREL.body.radius = 0;
  myButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&myButtonStylePR, &lv_style_plain);
  myButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
  myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
  myButtonStylePR.body.radius = 0;
  myButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

  myButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(myButton, 0); //set button is to 0
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
  lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
  lv_obj_set_size(myButton, 200, 50); //set the button size
  lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

  myButtonLabel = lv_label_create(myButton, NULL); //create label and puts it inside of the button
  lv_label_set_text(myButtonLabel, "Click the Button"); //sets label text

  myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
  lv_label_set_text(myLabel, "Button has not been clicked yet"); //sets label text
  lv_obj_align(myLabel, NULL, LV_ALIGN_LEFT_MID, 10, 0); //set the position to center

	//MOTOR INITS
	const int LIFT_MOTOR_PORT = 6;
	const int LIFT2_MOTOR_PORT = 7;

	ControllerButton btnUp(ControllerDigital::R1);
	ControllerButton btnDown(ControllerDigital::R2);
	Motor lift(LIFT_MOTOR_PORT);
	Motor lift2(LIFT2_MOTOR_PORT);


	// Chassis Controller - lets us drive the robot around with open- or closed-loop control
	std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors(1, -10)
        // Green gearset, 4 in wheel diam, 11.5 in wheel track
        .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
        .build();

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

}

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
void competition_initialize() {

}


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
