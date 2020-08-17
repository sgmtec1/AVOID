// Open Source
#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

const int pinoOut = 8; //PINO DIGITAL UTILIZADO PELO MÓDULO
int pinLed = 2;

void setup(){
  pinMode(pinoOut, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin (9600); //INICIALIZA A SERIAL
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(2, OUTPUT);
}

void loop(){
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("DETECTANDO >>>>> "); //IMPRIME O TEXTO NO DISPLAY LCD
  
  if(digitalRead(pinoOut) == LOW){ //SE LEITURA DO PINO FOR IGUAL A LOW, FAZ
    Serial.println ("Objeto detectado"); //IMPRIME O TEXTO NO MONITOR SERIAL
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("OBJETO DETECTADO       ");
    digitalWrite(pinLed, HIGH);
  }else{ //SENÃO, FAZ
    Serial.println ("Nenhum objeto detectado"); //IMPRIME O TEXTO NO MONITOR SERIAL
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("NENHUM OBJETO       ");
    digitalWrite(pinLed, LOW);
  }
}
