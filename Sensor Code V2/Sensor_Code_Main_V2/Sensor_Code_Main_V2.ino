
/* Developer notes
 * Sensor_Code_Beluga V2
 * Property of SUTD
 * Created by: Declan Ng, Javier Pey
 */

#include "definitions.h"

void setup() { 
  
  initSerial();
  initSensor();
  
}

void loop(){

  Movement();
  
}
