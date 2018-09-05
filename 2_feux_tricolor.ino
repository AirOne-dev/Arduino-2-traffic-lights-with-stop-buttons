const int leds[6] = {1,2,3,4,5,6};
const int buttons[2] = {0, 13};
int etat = 0;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  pinMode(buttons[0], INPUT);
  pinMode(buttons[1], INPUT);
}

void loop() {
  feux(2000, 4000);
}

void feux(int ptidelay, int lngdelay) {
  eteindre(4, 2); 
  for (int i = 0; i < 4000; i+=40) {
    etat = digitalRead(buttons[0]);
    if (etat == HIGH) {
      eteindre(0, 666);
      goto feu2vert;
    }
    allumer(0, 5);
    delay(25);
  }
  feu2vert:
  allumer(1, 666);
  eteindre(0, 666);
  delay(2000);
  
  for (int i = 0; i < 4000; i+=40) {
    etat = digitalRead(buttons[1]);
    if (etat == HIGH) {
      eteindre(5, 1);
      goto feu1vert;
    }
    allumer(2, 3);
    eteindre(5, 1);
    delay(25);
  }
  feu1vert:
  allumer(4, 666);
  eteindre(3, 666);
  delay(2000);
}

void allumer(int pin, int piin) {
  digitalWrite(leds[pin], HIGH);
  digitalWrite(leds[piin], HIGH);
}

void eteindre(int pin, int piin) {
  digitalWrite(leds[pin], LOW);
  digitalWrite(leds[piin], LOW);
}


