# Line Following Robot
My robot is an autonomous, wheeled vehicle that uses light sensors to detect a line, and follow it using dc motors. 

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Reyna A. | Adlai E. Stevenson High School | Computer Engineering | Incoming Sophomore

https://docs.google.com/document/d/1knMDCemPxow6FKgmn9HEC7iVgEH3KeSJTzBhRPgIl_w/edit?usp=sharing

![BillofMaterials](https://user-images.githubusercontent.com/107717711/176966244-57a3c50f-0972-423c-9bfa-23641d67cd33.PNG)


![File_000](https://user-images.githubusercontent.com/107717711/176527440-0ad7e898-2922-430e-9a36-3cb83d35e959.jpeg)

  
# Final Milestone
My final milestone consisted of adding on the last two sensors, attaching the back wheels and securing the back motors to the chassis, adding a 9V battery for extra power, and finishing the line following program. My greatest obstacles were with the IR sensors, as I needed the built in potentiometer to be set to just the right sensitivity for all three. However, with time and tweaking, testing each sensor under pieces of white and black paper with the readings printing to my computer screen, I was able to accomplish this. Other challenges included debugging the hardware and identifying the issues with so many parts and possible places of error. To work around this, I made sure to test as I went and persist if a seemingly impossible to solve problem occurred.

[![Milestone 3](https://res.cloudinary.com/marcomontalbano/image/upload/v1656530749/video_to_markdown/images/youtube--ok5LcHCXnxk-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/ok5LcHCXnxk "Milestone 3")

# Second Milestone
My second milestone is connecting the arduino, h-bridge, battery pack, and front DC motors onto the chassis of the car. I also attached the front wheels, soldered wires to connect the back motors to the h-bridge, connected one IR sensor, and wrote functions to move the car forwards, backwards, left, and right. My biggest challenge was the soldering, because this was my first time learning to solder, so I had to practice a bit first before soldering for my project. After this, I was able to successfully solder and connect the motors to the h-bridge.

[![Milestone 2](https://res.cloudinary.com/marcomontalbano/image/upload/v1656018183/video_to_markdown/images/youtube--zO5w537ZInI-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/zO5w537ZInI "Milestone 2")

# First Milestone
  

My first milestone is setting up the arduino and the h-bridge in order to move DC motors. To do this, I connected each motor to the h-bridge using alligator clips to distribute the current from a 6V battery pack, and the h-bridge to the arduino as well. Four digital pins connected on the arduino corresponded to spinning the motors in different directions. By passing input, 'HIGH' or 'LOW,' to each pin using the digitalWrite function, I was able to control each motor to spin forwards or backwards with various high-low combinations. Using these different combinations, I will eventually be able to turn the car left and right as well. Despite challenges in securing the battery pack's thin wires under the screws of the h-bridge, I was able to overcome the issues by stripping each wire to expose more of the wire to grip.

[![Mile Stone #!](https://res.cloudinary.com/marcomontalbano/image/upload/v1655495688/video_to_markdown/images/youtube--E6sysRuu57s-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=E6sysRuu57s&t=2s&ab_channel=BlueStampEng "Mile Stone #!")

## Code
```cpp
<int middleAnalogPin = A0;
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
}>
```
