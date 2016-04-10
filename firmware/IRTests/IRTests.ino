#include <Servo.h>
#include <SharpIR.h>

#define SERVO_X (0)
#define SERVO_Y (1)

#define SENSOR_FRONT (0)
#define SENSOR_BACK (1)

Servo servos[] = {Servo()};
SharpIR range_sensors[] = {SharpIR(A1, 1080), SharpIR(A2, 1080)};

void setup() {
  servos[SERVO_X].attach(A0, 1000, 2000);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  
  static int degrees = 0;
  static bool clockwise = true;
  
  servos[SERVO_X].write(degrees);
  
  degrees += (clockwise ? 1 : -1);
  if (degrees == 179) clockwise = false;
  else if (degrees == 0) clockwise = true;
  
  unsigned long before = millis();
  float distance_mm = range_sensors[SENSOR_FRONT].distance();
  unsigned long after = millis();

//  Serial.print(after - before);  
//  Serial.print("; ");
  Serial.print(degrees);
  Serial.print("; ");
  Serial.println(distance_mm);
}
