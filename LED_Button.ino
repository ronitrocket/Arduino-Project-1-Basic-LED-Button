int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledLevel = 0;

void setup() {
  
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last) {
  
  boolean current = digitalRead(switchPin);
  
  if (last != current) {
    
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() {

  currentButton = debounce(lastButton);
  if (lastButton == HIGH && currentButton == LOW) {
    
    ledLevel = ledLevel + 51;
  }

  if (ledLevel > 255) ledLevel = 0;
  
  lastButton = currentButton;
  analogWrite(ledPin, ledLevel);
}
