  #include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int button1 = 8;
int button2 = 9;
int button3 = 10;
int button4 = 11;
int button5 = 12;
byte cuore[8] = {B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000};
int punti = 0;
double tempo = 3000;
int posizione = 0;
int vite = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  lcd.begin(16, 2);
  lcd.createChar(0, cuore);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (vite != 0)
  {
   BottoniOff();
   StampaVitePunti();
   lcd.write(punti);
   StampaPiGreco();
   PremiBottone();
   BottoniOff(); 
  }
  else
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.write("Hai perso");
    delay(5000);
    vite = 3;
  }
}

void StampaVitePunti()
{
  lcd.setCursor(0,0);
  for (int i = vite; i > 0; i--)
  {
    lcd.write(byte(0));
  }
  lcd.setCursor(6, 0);
  lcd.write("Punti: ");
  lcd.setCursor(13, 0);
  //lcd.write(punti);
}

void StampaPiGreco()
{
  randomSeed(analogRead(0));
  posizione = random(6, 11);
  lcd.setCursor(posizione, 1);
  lcd.write("a");
  delay(tempo);
  lcd.clear();
}

void PremiBottone()
{
  bool punto = false;
  if (posizione == 6 && digitalRead(button1) == HIGH)
  {
    punti++;
    punto = true;
  }
  else if (posizione == 7 && digitalRead(button2) == HIGH)
  {
    punti++;
    punto = true;
  }
  else if (posizione == 8 && digitalRead(button3) == HIGH)
  {
    punti++;
    punto = true;
  }
  else if (posizione == 9 && digitalRead(button4) == HIGH)
  {
    punti++;
    punto = true;
  }
  else if (posizione == 10 && digitalRead(button5) == HIGH)
  {
    punti++;
    punto = true;
  }
  if (!punto)
  {
    vite--;
  }
}

void AccorciaTempo()
{
  if(punti % 5 == 0)
  {
    tempo = tempo / 0,25;
  }
}

void BottoniOff()
{
  digitalRead(button1) == LOW;
  digitalRead(button2) == LOW;
  digitalRead(button3) == LOW;
  digitalRead(button4) == LOW;
  digitalRead(button5) == LOW;
}
