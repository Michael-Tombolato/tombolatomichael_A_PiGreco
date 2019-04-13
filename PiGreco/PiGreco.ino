  #include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int button1 = 8;
int button2 = 9;
int button3 = 10;
int button4 = 11;
int button5 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  ì
}
