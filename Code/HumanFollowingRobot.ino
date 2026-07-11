

// Ultrasonic Sensor
#define TRIG_PIN 9
#define ECHO_PIN 10

// IR Sensors
#define LEFT_IR 2
#define RIGHT_IR 3



// Left Motor
#define ENA 5
#define IN1 6
#define IN2 7

// Right Motor
#define ENB 11
#define IN3 12
#define IN4 13



void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  Serial.begin(9600);
}

void loop() {

  int leftIR = digitalRead(LEFT_IR);
  int rightIR = digitalRead(RIGHT_IR);

  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);


  if (leftIR == LOW) {

    turnLeft();

  }
  else if (rightIR == LOW) {

    turnRight();

  }
  else {

    if (distance > 20) {
      forward();
    }
    else {
      backward();
    }
  }

  delay(50);
}

// Ultrasonic Function


long getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  long distance = duration * 0.034 / 2;

  return distance;
}


// Motor Functions


void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
