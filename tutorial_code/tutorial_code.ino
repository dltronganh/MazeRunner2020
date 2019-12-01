/*
   This code is for the CAPS-Tech's Contest 3rd
   Maze Runner Robot Race 2020
   Good luck to all of you

   Committee CAPS-Tech's Contest 3rd
*/

//define for motor

#define LA    11  //control direction of motor left
#define LB    12  //control direction of motor left
#define L_PWM 13  //control speed of motor left

#define RA    9  //control direction of motor right
#define RB    10   //control direction of motor right
#define R_PWM 8   //control speed of motor right

//define for sensor
#define TF 7 //Trig Front
#define EF 6 //Echo Front

#define TL 3 //Trig Left
#define EL 2 //Echo Left

#define TR 5 //Trig Right
#define ER 4 //Echo Right

int Motor[6] = {LA, LB, L_PWM, RA, RB, R_PWM}; //motors sensor
int Sensor[6] = {TL, TF, TR, EL, EF, ER};      //Sensors array
int dis[3];                                    //To store distance of Left, Center, Right

void setup() {

  for (int i = 0; i < 3; i++) {
    pinMode(Sensor[i], OUTPUT);
    pinMode[Sensor[i + 3], INPUT];
  }

  for (int i = 0; i < 6; i++) {
    pinMode(Motor[i], OUTPUT);
  }

  Serial.begin(9600);

}

void loop() {
    GetDistance();
    runRightFollower();

  // TestMotor();
//  TestTurn();
}

void GetDistance() {
  for (int i = 0; i < 3; i++) {
    long duration = 0;
    int distance = 0;
    digitalWrite(Sensor[i], LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(Sensor[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(Sensor[i], LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(Sensor[i + 3], HIGH);

    // Calculating the distance
    distance = duration * 0.034 / 2;

    // Prints the distance on the Serial Monitor
    Serial.print(i);
    Serial.print(": ");
    Serial.print(distance);
    Serial.print("      ");

    //save to data array
    dis[i] = distance;
  }

  Serial.println(); //to new line in Serial Monitor

  delay(10);
}


void runRightFollower() { //run by right wall follow method
  if (dis[1] > 10) {
    if (dis[2] <= 5 ) {
      move_steering(80, 100);
    }
    else if (dis[2] > 5) {
      move_steering(100, 80);
    }
  }
  else if (dis[1] <= 10) {
    if (dis[2] < 10) {
      move_steering(-100, 100);
      delay(800);
    }
    else if (dis[2] >10){
      move_steering(100, -100);
      delay(800);
    }
  }


}

void TestMotor() {
  _ahead();
  delay(1000);
  _stop();
  delay(1000);
  _back();
  delay(1000);
  _stop();
  delay(1000);
}

void TestTurn() {
  move_steering(-100, 100);
  delay(1000);
  move_steering(0, 0);
  delay(10000);
}
