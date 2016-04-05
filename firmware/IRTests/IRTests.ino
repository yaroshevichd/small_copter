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

//  unsigned long millis();

  servos[SERVO_X].write(degrees);
  float radians = degrees / 2.0 * PI / 180.0; // servo allows to move from 0-90 only
  degrees = degrees + (clockwise ? 1 : -1);
  if (degrees == 180) clockwise = false;
  else if (degrees == 0) clockwise = true;
  
//  int dis1 = ir1.distance();
  int distance_mm = range_sensors[SENSOR_BACK].distance();
  float x = distance_mm * sin(radians);
  float y = distance_mm * cos(radians);
  
//  Serial.print("Distance 1: ");
//  Serial.println(dis1);
  Serial.print("Distance 2: ");
  Serial.print(x);
  Serial.print("; ");
  Serial.println(y);
}
