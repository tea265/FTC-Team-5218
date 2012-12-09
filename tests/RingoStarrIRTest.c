#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C2_1,     driveRight,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     driveLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     driveSide,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    gravityShelf,         tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    IRArm,                tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../library/sensors/drivers/hitechnic-irseeker-v2.h"

task main()
{
  	int dir;
	int strength1, strength2, strength3, strength4, strength5;

	// the default DSP mode is 1200 Hz.
  	tHTIRS2DSPMode mode = DSP_1200;

    // You can switch between the two different DSP modes by pressing the
    // orange enter button

    while (true)
    {
      	// set the DSP to the new mode
      	if (HTIRS2setDSPMode(IRSeeker, mode))
			break; // Sensor initialized

      	PlaySound(soundShortBlip);
      	nxtDisplayCenteredTextLine(6, "Connect Sensor");
      	nxtDisplayCenteredTextLine(7, "to Port S2");
      	wait1Msec(100);
    }

    eraseDisplay();

    while (true)
    {
      	// read the current modulated signal direction
      	dir = HTIRS2readACDir(IRSeeker);
      	if (dir < 0)
        	break; // I2C read error occurred

      	if (!HTIRS2readAllACStrength(IRSeeker, strength1, strength2, strength3, strength4, strength5 ))
        	break; // I2C read error occurred

      	string tmpStr;

		StringFormat(tmpStr, "Direction: %d", dir);
		nxtDisplayTextLine(3, tmpStr);
		StringFormat(tmpStr, "Strength 2: %d", strength2);
		nxtDisplayTextLine(4, tmpStr);
		StringFormat(tmpStr, "Strength 3: %d", strength3);
		nxtDisplayTextLine(5, tmpStr);
		StringFormat(tmpStr, "Strength 4: %d", strength4);
		nxtDisplayTextLine(6, tmpStr);

    }
}
