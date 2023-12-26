#include <Otto.h>
Otto Otto;
#include <PlayRtttl.hpp>


#define LeftLeg 2 // left leg pin, servo[0]
#define RightLeg 3 // right leg pin, servo[1]
#define LeftFoot 4 // left foot pin, servo[2]
#define RightFoot 5 // right foot pin, servo[3]
#define Buzzer 13 //buzzer pin

long ultrasound_distance_simple() {
   long duration, distance;
   digitalWrite(8,LOW);
   delayMicroseconds(2);
   digitalWrite(8, HIGH);
   delayMicroseconds(10);
   digitalWrite(8, LOW);
   duration = pulseIn(9, HIGH);
   distance = duration/58;
   return distance;
}


void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
Otto.home();

  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
    Otto.sing( S_connection );
  Otto.home();
  delay(2*1000);
  playRtttlBlockingPGM(13,(char*)Simpsons);

}

void loop() {
    if (ultrasound_distance_simple() <= 10) {
      Otto.walk(1,1000,-1); // BACKWARD
    }
    if ((ultrasound_distance_simple() > 20) && ( ultrasound_distance_simple() < 30)) {
      Otto.sing(S_fart1);
    }
    if (ultrasound_distance_simple() > 30) {
      Otto.home();
    }

}