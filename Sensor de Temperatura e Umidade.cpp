#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int dhtPin = 9;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// DHT11
#define Type DHT11
DHT HT(dhtPin, Type);

int humidity;
float tempC;
float tempF;
int dTime = 500;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  // Lê a umidade e a temperatura
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  // Verifica se as leituras foram bem-sucedidas
  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("Falha na leitura do DHT11!");
    lcd.setCursor(0, 0);
    lcd.print("Erro de leitura");
    lcd.setCursor(0, 1);
    lcd.print("DHT11!");
  } else {
    Serial.print("Humidade Relativa: ");
    Serial.print(humidity);
    Serial.print("% / Temperatura: ");
    Serial.print(tempC);
    Serial.print("ºC / ");
    
    lcd.setCursor(0, 0);
    lcd.print("Humidade: ");
    lcd.print(humidity);
    lcd.print("%");
    
    lcd.setCursor(0, 1);
    lcd.print("Temp.: ");
    lcd.print(tempC);
    lcd.print("*C");
  }

  delay(dTime);
  lcd.clear();
}