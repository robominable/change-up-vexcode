using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor FLdrive;
extern motor FRdrive;
extern motor BLdrive;
extern motor BRdrive;
extern motor FlywheelL;
extern motor FlywheelR;
extern motor IntakeL;
extern motor IntakeR;
extern signature Vision__SIG_1;
extern signature Vision__SIG_2;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern encoder Flywheel;
extern sonar IntakeUltrasonic;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );