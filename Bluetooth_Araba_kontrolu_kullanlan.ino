char dataIn = 'S'; // Durma fonksiyonu için karakter
int pinileri = 3; //İleri sürüş için kontrol pini
int pingeri = 5; //Geri sürüş için kontrol pini
int pinsol = 6; //Sola sürüş için kontrol pini
int pinsag = 9; //Sağa sürüş için kontrol pini
char determinant; //Program döngüsü için karakter
char det; //Program döngüsü için karakter
int frontlight = 10;
int backlight = 11;
int korna = 12;
void setup()
{
Serial.begin(9600); //HC-06 bluetooth modülü için btu 9600
pinMode(pinileri, OUTPUT);
pinMode(pingeri, OUTPUT);
pinMode(pinsol, OUTPUT);
pinMode(pinsag, OUTPUT);
pinMode(frontlight, OUTPUT);
pinMode(backlight, OUTPUT);
pinMode(korna, OUTPUT);

}
 
void loop()
{
det = check();
while (det == 'F') //Telefondaki programda atanmış olan ileri sürüş butonunun harf eşdeğeri
{
digitalWrite(pinileri, HIGH);
det = check();
}
while (det == 'B') //Telefondaki programda atanmış olan geri sürüş butonunun harf eşdeğeri
{
digitalWrite(pingeri, HIGH);
det = check();
}
while (det == 'L') //Telefondaki programda atanmış olan sola dönüş butonunun harf eşdeğeri
{
digitalWrite(pinsol, HIGH);
det = check();
}
while (det == 'R') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
{
digitalWrite(pinsag, HIGH);
det = check();
}
while (det == 'G')
{
  digitalWrite(pinileri,HIGH);
  digitalWrite(pinsol, HIGH);
  det = check();
}
while (det == 'I')
{
digitalWrite(pinileri,HIGH);
digitalWrite(pinsag, HIGH);
det = check();
}
while (det == 'H')
{
digitalWrite(pingeri, HIGH);
digitalWrite(pinsol,HIGH);
det = check();
}
while (det == 'J')
{
 digitalWrite(pingeri,HIGH);
 digitalWrite(pinsag, HIGH);
det = check();
 }
while (det == 'S') //Telefondaki programda atanmış olan durma fonksiyonun harf eşdeğeri
{
digitalWrite(pinileri, LOW);
digitalWrite(pingeri, LOW);
digitalWrite(pinsol, LOW);
digitalWrite(pinsag, LOW);
det = check();
}
while (det == 'W') //Telefondaki programda atanmış olan ön ışığı aç butonunun harf eşdeğeri
{
digitalWrite(frontlight, HIGH);
det = check();
}
while (det == 'w') //Telefondaki programda atanmış olan ön ışığı kapat butonunun harf eşdeğeri
{
digitalWrite(frontlight, LOW);
det = check();
}
while (det == 'U') //Telefondaki programda atanmış olan arka ışığı aç butonunun harf eşdeğeri
{
digitalWrite(backlight, HIGH);
det = check();
}
while (det == 'u') //Telefondaki programda atanmış olan arka ışığı kapat butonunun harf eşdeğeri
{
  digitalWrite(backlight, LOW);
 det = check();
  }
  while (det == 'V') //Telefondaki programda atanmış olan kornayı aç butonunun harf eşdeğeri
{
  digitalWrite( korna, HIGH);
det = check();
  }
  while (det == 'v') //Telefondaki programda atanmış olan kornayı kapat butonunun harf eşdeğeri
{
  digitalWrite(korna, LOW);
det = check();
  } 
}
 
int check()
{
if (Serial.available() > 0) //Serial portun kontrollü
{
dataIn = Serial.read(); //Telefondan gelen verilerin kontrollü
if (dataIn == 'F')
{
determinant = 'F';
}
else if (dataIn == 'B')
{
determinant = 'B';
}
else if (dataIn == 'L')
{
determinant = 'L';
}
else if (dataIn == 'R')
{
determinant = 'R';
}
else if (dataIn == 'S')
{
determinant = 'S';
}
 else if (dataIn == 'G')
{
determinant = 'G';
}
else if (dataIn == 'I')
{
determinant = 'I';
}
else if (dataIn == 'H')
{
determinant = 'H';
}
else if (dataIn == 'J')
{
determinant = 'J';
}
else if (dataIn == 'W')
{
determinant = 'W';
}
else if (dataIn == 'w')
{
determinant = 'w';
}
else if (dataIn == 'U')
{
determinant = 'U';
}
else if (dataIn == 'u')
{
determinant = 'u';
}
else if (dataIn == 'V')
{
determinant = 'V';
}
else if (dataIn == 'v')
{
determinant = 'v';
}
}
return determinant;
}
