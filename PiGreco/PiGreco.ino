  #include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int button1 = 8;
int button2 = 9;
int button3 = 10;
int button4 = 11;
int button5 = 12;
byte cuore[8] = {B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000};
int punteggio = 0;
double tempo = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  lcd.begin(16, 2);
  lcd.createChar(0, cuore);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  StampaVite();
  StampaPiGreco();
}

void StampaVite()
{
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
}

void StampaPiGreco()
{
  int posizione = random(6, 12);
  lcd.setCursor(posizione, 1);
  lcd.write("a");
  delay(tempo);
  lcd.clear();
}
void Premibottone()
{
  if ()
  {
    // se il buttone è on nella stessa posizione del pigreco allora punti++ sennò qualcosa
  }
}

void AccorciaTempo()
{
  if(punteggio % 5 == 0)
  {
    tempo = tempo / 0,25;
  }
}

void BottoniOff()
{
  //usare all'inizio e alla ine per mettere i bottoni off
}
