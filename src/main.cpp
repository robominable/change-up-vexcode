/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\trylaarsdam                                      */
/*    Created:      Sat May 09 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FLdrive              motor         1               
// FRdrive              motor         2               
// BLdrive              motor         3               
// BRdrive              motor         4               
// FlywheelL            motor         5               
// FlywheelR            motor         6               
// IntakeL              motor         7               
// IntakeR              motor         8               
// Vision               vision        20              
// Flywheel             encoder       A, B            
// IntakeUltrasonic     sonar         C, D            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.clearScreen(white);
  Brain.Screen.drawImageFromFile("loading.png", 175, 0);
  vex::task::sleep(1000);
  Brain.Screen.clearScreen(white);
  Brain.Screen.drawImageFromFile("auton-select.png", 0, 0);
}
