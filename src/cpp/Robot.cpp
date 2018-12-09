#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include "intake.h"
#include "pressandhold.h"
#include "prematch.h"

using namespace frc;
class Robot: public IterativeRobot {
public:
     Robot() {} 
	TalonSRX *intake_talon;
	Joystick *joystick; 
    Intake  *intake;
    PressAndHold *pressandhold;
    PrematchPrep *prematch;
    TalonSRX *drive_talon_right_enc;
     ToggleMotor *drive_toggle_right_enc;
             TalonSRX *drive_talon_right_noenc;
              ToggleMotor *drive_toggle_right_noenc; 
            TalonSRX *drive_talon_left_enc;
            ToggleMotor *drive_toggle_left_enc;
             TalonSRX *drive_talon_left_noenc;
             ToggleMotor *drive_toggle_left_noenc;
             TalonSRX *intake_talon_noenc;
             ToggleMotor *intake_toggle_noenc;
             TalonSRX *flipper_talon_enc;
             ToggleMotor *flipper_toggle_enc;
    void RobotInit() { 
        std::cout<<"Intake v2 "<<std::endl;
        joystick = new  Joystick(0);
        drive_talon_right_enc = new TalonSRX (2);
        drive_toggle_right_enc = new ToggleMotor(joystick, drive_talon_right_enc);
        drive_toggle_left_enc = new ToggleMotor(joystick, drive_talon_left_enc );
        drive_talon_left_noenc = new TalonSRX (3);
        drive_toggle_left_noenc = new  ToggleMotor(joystick, drive_talon_left_noenc);
        drive_talon_right_noenc = new TalonSRX(4);
        drive_toggle_right_noenc = new ToggleMotor(joystick, drive_talon_right_noenc);
        intake_talon_noenc = new TalonSRX (5 /*not sure about this number*/);//this is the number for the intake it should be left bumber
        intake_toggle_noenc = new  ToggleMotor(joystick, intake_talon_noenc);
        flipper_talon_enc = new TalonSRX (6 /*not sure about this number*/); 
        flipper_toggle_enc = new ToggleMotor(joystick,  flipper_talon_enc);
        pressandhold = new PressAndHold(joystick,drive_talon_left_enc);
        intake = new Intake(pressandhold,intake_talon_noenc);
        prematch = new   PrematchPrep(drive_talon_right_enc, drive_toggle_right_enc, 
             drive_talon_right_noenc, drive_toggle_right_noenc, 
             drive_talon_left_enc, drive_toggle_left_enc,
             drive_talon_left_noenc, drive_toggle_left_noenc,
              intake_talon_noenc,intake_toggle_noenc,
         flipper_talon_enc, flipper_toggle_enc
              );
    
    }	

    void DisabledInit() { }
    void AutonomousInit() { }
    void TeleopInit() { }
    void TestInit() { }

    void DisabledPeriodic() { }
    void AutonomousPeriodic() { }
    void TeleopPeriodic() { 
    //drive_talon_left->Set(rControlMode::PercentOutput,1);	   
    //intake->run_intake(0.3);
    prematch->run_prematch();
    }
    void TestPeriodic() { }
};

START_ROBOT_CLASS(Robot)
/*
//left_drive talon encode =a
//right_drive talon encoder =b
left drive talon no encoder =x 
right drive talon noencoder =y
flipper talon = right button 
intake talon =  button 
hopper solenoid = end button 
5 is left 
6 is right 
back 7 
star is 8
*/