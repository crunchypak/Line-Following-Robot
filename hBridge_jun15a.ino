int middleAnalogPin = A0;
int middleVal = 0; 
int leftAnalogPin = A1;
int leftVal = 0; 
int rightAnalogPin = A2;
int rightVal = 0; 
int THRESHOLD = 300;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  //pinMode(analogPin, INPUT);
}

void loop() {
  //105 white, 1019 brown
  //666 dark, 77 white
  middleVal = analogRead(middleAnalogPin);
  //Serial.println("Middle " + middleVal); 
  //Serial.println(middleVal);

  //35 white, 1019 brown
  //665, 666, 667 dark, 20, 21 white
  leftVal = analogRead(leftAnalogPin);
  //Serial.println("Left " + leftVal);
  //Serial.println(leftVal);

  //40 or 41 white, 1018 brown
  //now - 665, 666 dark, 22 or 23 white
  rightVal = analogRead(rightAnalogPin);
  //Serial.println("Right " + rightVal);
  //Serial.println(rightVal);
  
  Serial.print(String(leftVal) + " ");
  Serial.print(String(middleVal) + " ");
  Serial.println(String(rightVal));
                                   
  /*    if only middle black, forward
   *    if none black, stop                                                                                         
   *    if middle and left black, turn left
   *    if middle and right black, turn right
   *    
   */
  if(!isBlack(leftVal)  && !isBlack(middleVal) && !isBlack(rightVal)) {
    halt();
  }
  else if((!isBlack(leftVal) && !isBlack(rightVal)) || isBlack(middleVal)) {
    forwards();
  }
  else if(isBlack(leftVal)  && !isBlack(rightVal)) {
    left();
  }
  else if(!isBlack(leftVal) && isBlack(rightVal)) {
    right();
  }

  /*
   * 
  if(!isBlack(leftVal)  && isBlack(middleVal) && !isBlack(rightVal)) {
    forwards();
  }
  else if(!isBlack(leftVal)  && !isBlack(middleVal) && !isBlack(rightVal)) {
    halt();
  }
  else if(isBlack(leftVal)  && isBlack(middleVal) && !isBlack(rightVal)) {
    left();
  }
  else if(!isBlack(leftVal)  && isBlack(middleVal) && isBlack(rightVal)) {
    right();
  }
   * */
   
  //backwards();
  //forwards();
  //right();
}
   
/*
void oppDirections() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}
*/

bool isBlack(int sensorVal) {
  if(sensorVal > THRESHOLD) {
    return true;
  }
  else {
    return false;
  }
}

void backwards() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void forwards() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void left() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void right() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

void halt() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
