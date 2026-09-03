const int trigPin = 9;
const int echoPin = 10;



const int yesilLED = 2;
const int beyazLED = 3;
const int kirmiziLED = 4;
const int buzzer = 5; 



void setup() {
  Serial.begin(9600) ;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT) ;

  pinMode(yesilLED, OUTPUT);
  pinMode(beyazLED, OUTPUT);
  pinMode(kirmiziLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long sure = pulseIn(echoPin, HIGH);

  float mesafe = sure * 0.0343 / 2;

  Serial.print("mesafe: ");
  Serial.print(mesafe);
  Serial.print(" cm");

  if (mesafe > 30) {
    digitalWrite(yesilLED, HIGH);
    digitalWrite(beyazLED, LOW);
    digitalWrite(kirmiziLED, LOW);
    
    
  }
  else if ( mesafe > 10) {
    digitalWrite(yesilLED, LOW);
    digitalWrite(beyazLED, HIGH);
    digitalWrite(kirmiziLED, LOW);
    
  }
  else {
    digitalWrite(yesilLED, LOW);
    digitalWrite(beyazLED, LOW);
    digitalWrite(kirmiziLED, HIGH);
    
  }

  if (mesafe > 30) {
    noTone(buzzer);

  }
  else if (mesafe > 20) {
    tone(buzzer, 1000, 100);
    delay(700);
  }
  else if (mesafe > 10) {
    tone(buzzer, 1000, 100);
    delay(300);
    
  }
  else {
    tone(buzzer, 1000);
    delay(100);
  }
  


}
