#define tastoR A0
#define tastoG A1
#define tastoV A2
#define tastoB A3

int numeroLed=4;
int pinR=11;
int pinG=10;
int pinV=9;
int pinB=8;
int pinLED[]={pinV,pinB,pinG,pinR};
int pinTasti[]={tastoV,tastoB,tastoG,tastoR};
int tempoAcc=2000;
int tempoVerif;
int ledAcc;
long timeChange;
int punti=0;

void setup() {
// put your setup code here, to run once:
for(int a=0;a<numeroLed;a++)
  {
  pinMode(pinLED[a],OUTPUT);
  digitalWrite(pinTasti[a], HIGH);
  }
timeChange=millis();
tempoVerif=tempoAcc;
}

void loop() {
if(millis()-timeChange>tempoVerif)
  {
  Ricomincia();
  }
  else if(digitalRead(pinTasti[ledAcc])==LOW)
  {
    SegnaPunti();
    AccendiLed();
  }
}

void AccendiLed(){
randomSeed(millis()); // imposta millis() come base per generare un numero casuale da 0 a 255
ledAcc = random(4); // numero casuale da 0 a 3
for(int a=0;a<numeroLed;a++){
digitalWrite(pinLED[a],LOW);
}
digitalWrite(pinLED[ledAcc],HIGH);
timeChange=millis();

}

void SegnaPunti(){
delay(50);
tempoVerif=tempoVerif-25;
punti=punti+1;
Serial.println(punti);
}

void Ricomincia(){
for(int b=0;b<5;b++){
for(int a=0;a<numeroLed;a++){
digitalWrite(pinLED[a], HIGH); // turn the LED on (HIGH is the voltage level)
delay(50); // wait for a second
digitalWrite(pinLED[a], LOW); // turn the LED off by making the voltage LOW
delay(50);

}
}
timeChange=millis();
punti=0;
tempoVerif=tempoAcc;
}
