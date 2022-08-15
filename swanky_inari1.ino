#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
float intervalTime = 4; // Time between each waste collection interval (in seconds)
  
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop() {
  // This motion simulates the motion of a swivel arm to collect the waste from the net on top of the water body
  // The motor will rotate 180 degrees and wait for 1s, then turn another 180 degrees in the opposite direction
  // This indicates the collection of waste by the "arm"
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                     // waits 15ms for the servo to reach the position
  }
  delay(intervalTime * 1000); // wait for (intervalTime * 1000) milliseconds before next waste collection
}
