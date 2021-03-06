#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftElevator,  tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     rightElevator, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define TARGET 360

task main()
{
    long leftVal;
    long rightVal;
    bool doneRight = false;
    bool doneLeft = false;

	nMotorEncoder[leftElevator] = 0;
	nMotorEncoder[rightElevator] = 0;

    leftVal = nMotorEncoder[leftElevator];
    rightVal = nMotorEncoder[rightElevator];

	motor[leftElevator] = 20;
	motor[rightElevator] = -20;

	while (!doneRight && !doneLeft) {
        leftVal = nMotorEncoder[leftElevator];
        rightVal = nMotorEncoder[rightElevator];

        if ((leftVal + 5) < rightVal) {
            motor[rightElevator] = 0;
        } else if (leftVal > (rightVal + 5)) {
            motor[leftElevator] = 0;
        } else {
            if (!doneLeft) {
				motor[leftElevator] = 20;
            }
            if (!doneRight) {
				motor[rightElevator] = -20;
            }
        }

        if (leftVal >= TARGET) {
            motor[leftElevator] = 0;
            doneLeft = true;
        }
        if (rightVal >= TARGET) {
            motor[rightElevator] = 0;
            doneRight = true;
        }
    }
    motor[leftElevator] = 0;
    motor[rightElevator] = 0;

}
