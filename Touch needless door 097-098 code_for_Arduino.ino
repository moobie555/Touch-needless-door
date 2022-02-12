#include <Stepper.h>
#define STEPS 2048 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper1(STEPS, 2, 4, 3, 5);
Stepper stepper2(STEPS, 6, 8, 7, 9);
int V_Distance = 0;

int counter = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{

}

void loop() {

  V_Distance = 0.01723 * readUltrasonicDistance(11, 10);
  if(V_Distance <= 5 && counter ==0 ) 
  {
    
    stepper1.setSpeed(10);
    stepper1.step(-512);
    delay(1000);
    stepper2.setSpeed(10);
    stepper2.step(-512);
    counter++;
   }
 if(V_Distance > 5 && counter == 1) 
     {
      delay(2000);
      stepper2.setSpeed(10);
      stepper2.step(512);
      delay(1000);
      stepper1.setSpeed(10);
      stepper1.step(512);
      counter--;
     }

}
