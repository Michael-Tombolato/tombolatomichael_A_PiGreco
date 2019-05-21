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
  for (int i = 0; i < 5; i++)
  {
    lcd.setCursor(0, 1);
    lcd.write("b");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  BottoniOff();
  StampaVitePunti();
  StampaPiGreco();
  PremiBottone();
  BottoniOff();
}

void StampaVitePunti()
{
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write("Punti: " + punti);
}

void StampaPiGreco()
{
  posizione = random(6, 12);
  lcd.setCursor(posizione, 1);
  lcd.write("a");
  delay(tempo);
  lcd.clear();
}
void PremiBottone()
{
  if (posizione == 6 && digitalRead(button1) == HIGH)
  {
    punti++;
  }
  else if (posizione == 7 && digitalRead(button2) == HIGH)
  {
    punti++;
  }
  else if (posizione == 8 && digitalRead(button3) == HIGH)
  {
    punti++;
  }
  else if (posizione == 9 && digitalRead(button4) == HIGH)
  {
    punti++;
  }
  else if (posizione == 10 && digitalRead(button5) == HIGH)
  {
    punti++;
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
