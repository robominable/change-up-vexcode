#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FLdrive = motor(PORT1, ratio18_1, false);
motor FRdrive = motor(PORT2, ratio18_1, false);
motor BLdrive = motor(PORT3, ratio18_1, false);
motor BRdrive = motor(PORT4, ratio18_1, false);
motor FlywheelL = motor(PORT5, ratio6_1, false);
motor FlywheelR = motor(PORT6, ratio6_1, false);
motor IntakeL = motor(PORT7, ratio18_1, false);
motor IntakeR = motor(PORT8, ratio18_1, false);
/*vex-vision-config:begin*/
vision Vision = vision (PORT20, 50);
/*vex-vision-config:end*/
encoder Flywheel = encoder(Brain.ThreeWirePort.A);
sonar IntakeUltrasonic = sonar(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}