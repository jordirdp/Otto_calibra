#include <Otto.h>
Otto Otto;

#define LeftLeg 2 // left leg pin, servo[0]
#define RightLeg 3 // right leg pin, servo[1]
#define LeftFoot 4 // left foot pin, servo[2]
#define RightFoot 5 // right foot pin, servo[3]
#define Buzzer 13 //buzzer pin

 void Otto_moveLegs(int T, int posLegL, int posLegR, int posFootL, int posFootR) {   int posLegs[]={ posLegL,posLegR,posFootL,posFootR };   Otto._moveServos(T,posLegs); }

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
Otto.home();

  Otto_moveLegs(200,90,90,90,90);
    Otto.home();
  Otto_moveLegs(100,97,90,80,75);Otto.saveTrimsOnEEPROM();

}

void loop() {

}