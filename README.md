**Tyler Martin - TRM32 - Churchill College**

This zip contains the edited boot.c, devMMA8451Q.c and devMMA8451Q.h from the default warp configuration. 

Boot.c has been edited to include options to call the functions myOrientation and myprintSensorDataMMA8451Q, created in devMMA8451Q.c. myOrientation is the key function for this task, outputting the board's orientation. It detects two stable orientations of a dropped board: either the correct way up (resting on its rubber feet chips facing up) or upside-down (the opposite configuration). To run this 'y' must be entered twice from the warp menu. The function myprintSensorDataMMA8451Q prints 100 readings of the MMA8451Q accelerometers' z axis. 

**Updates of code**
boot.c - Warp menu updates to call functions.

devMMA8541Q.c - The functions myOrientation and myprintSensorDataMMA8451Q, which use the z axis readings.

devMMA8541Q.h - header file updated to include new functions.
