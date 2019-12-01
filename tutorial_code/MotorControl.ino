void _ahead() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  analogWrite(L_PWM, 255);

  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
  analogWrite(R_PWM, 255);
}

void _stop() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  analogWrite(L_PWM, 0);

  digitalWrite(RA, LOW);
  digitalWrite(RB, LOW);
  analogWrite(R_PWM, 0);
}

void _back() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  analogWrite(L_PWM, 255);

  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
  analogWrite(R_PWM, 255);
}

void move_steering(int speed_left, int speed_right) { //If speed > 0: turn ahead. If speed = 0: stop. If < 0: turn back
  if (speed_left > 0) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, LOW);
    analogWrite(L_PWM, speed_left);
  }
  else if (speed_left < 0) {
    digitalWrite(LA, LOW);
    digitalWrite(LB, HIGH);
    analogWrite(L_PWM, -speed_left);
  }
  else if (speed_left == 0) {
    digitalWrite(LA, LOW);
    digitalWrite(LB, LOW);
    analogWrite(L_PWM, speed_left);
  }

  if (speed_right > 0) {
    digitalWrite(RA, HIGH);
    digitalWrite(RB, LOW);
    analogWrite(R_PWM, speed_right);
  }
  else if (speed_right < 0) {
    digitalWrite(RA, LOW);
    digitalWrite(RB, HIGH);
    analogWrite(R_PWM, -speed_right);
  }
  else if (speed_right == 0) {
    digitalWrite(RA, LOW);
    digitalWrite(RB, LOW);
    analogWrite(R_PWM, speed_right);
  }
}
