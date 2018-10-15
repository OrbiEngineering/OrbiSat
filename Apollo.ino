#include <VirtualWire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

float d1;
float d2;
float d3;
float d4;
float d5;
float d6;

float p1;
float p2;
float p3;
float p4;
float p5;
float p6;

float alfa = 0;
float alfa2 = 0;
float beta = 0;
float mat = 0;

int analogPin1 = 1;
int analogPin2 = 2;
int analogPin3 = 3;
int analogPin4 = 4;
int analogPin5 = 5;
int analogPin6 = 6;

float maior = 0;
float secmaior = 0;

char Valor_CharMsg[4];
int valRec;
char recebido_RF_char[4];
float valor;

#define DHTPIN A0 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup()

{
  Serial.begin(9600);

  //RECEPTOR
  vw_set_rx_pin(9);//Pino que estamos conectados
  vw_setup(500);//Velocidade de bytes, quanto menor o valor, maior a precisão, porém, menor o alcance
  vw_rx_start();

  //TRANSMISSOR
  vw_set_tx_pin(6);
  vw_setup(500);

  //SENSOR TEMPERATURA
  dht.begin();
}

void loop()

{
  //Sensor de temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //Painel Solar
  maior = p1;
  if (p2 > maior)  {
    maior = p2;
  }
  if (p3 > maior)  {
    maior = p3;
  }
  if (p4 > maior)  {
    maior = p4;
  }
  if (p5 > maior)  {
    maior = p5;
  }
  if (p6 > maior)  {
    maior = p6;
  }

  d1 =  maior - p1;
  d2 =  maior - p2;
  d3 =  maior - p3;
  d4 =  maior - p4;
  d5 =  maior - p5;
  d6 =  maior - p6;

  secmaior = p1;
  if (d2 < d1 && d2 > 0)  {
    p2 = secmaior;
  }
  if (d3 < d2 && d3 > 0)  {
    p3 = secmaior;
  }
  if (d4 < d3 && d4 > 0)  {
    p4 = secmaior;
  }
  if (d5 < d4 && d5 > 0)  {
    p5 = secmaior;
  }
  if (d6 < d5 && d6 > 0)  {
    p6 = secmaior;
  }

  p1 = analogRead(analogPin1) * 0.00488759;
  p2 = analogRead(analogPin2) * 0.00488759;
  p3 = analogRead(analogPin3) * 0.00488759;;
  p4 = analogRead(analogPin4) * 0.00488759;;
  p5 = analogRead(analogPin5) * 0.00488759;;
  p6 = analogRead(analogPin6) * 0.00488759;;

  mat = maior / secmaior;
  alfa = atan(mat);
  alfa2 = alfa * 57.2958;
  beta = 90 - alfa2;

  delay(1000);

  //RECEPTOR
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen))
  {
    int i;
    for (i = 0; i < buflen; i++)
    {
      recebido_RF_char[i] = char(buf[i]); //Armazena os caracteres recebidos
    }
    recebido_RF_char[buflen] = '\0';
    valRec = atoi(recebido_RF_char);

    //TRANSMISSOR
    //Estabilização
    if (valRec == 1) {
      
      
      valor = t;
      dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
      Serial.println(Valor_CharMsg);
      
      //Envio Temperatura
      if(valor = t) 
      
      { 
       delay(1000);
       valor = t;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados
       Serial.println(Valor_CharMsg);
    }}

    //Estabilização
    if (valRec == 2)

    {
      valor = h;
      dtostrf (valor, 4, 2, Valor_CharMsg);//Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
      Serial.println(Valor_CharMsg);
      
      delay(1000);
      valor = h;
      dtostrf (valor, 4, 2, Valor_CharMsg);//Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
      Serial.println(Valor_CharMsg);
     }
    
     //Envio Umidade     
     if(valor = h) 
     
     {
       delay(1000);
       valor = h;
       dtostrf (valor, 4, 2, Valor_CharMsg);//Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados
       Serial.println(Valor_CharMsg); 
     }

    //Estabilização
    if (valRec == 3)

    {
      valor = p1;
      dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
      
      delay(1000);
      valor = p1;
      dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
      
      delay(1000);
      valor = p1;
      dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
      delay(1000);
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
      vw_wait_tx(); //Aguarda envio dos dados
    
    //Envio Painéis solares  
    if(valor = p1) 
     
     {
       delay(1000);
       valor = p1;
       dtostrf (valor, 4, 2, Valor_CharMsg);//Converte valor para envio
       delay(2000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados
       Serial.println(Valor_CharMsg); 

      
      
       delay(1000);
       valor = p2;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(2000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

       
      
       delay(1000);
       valor = p3;
       dtostrf (valor, 4, 2, Valor_CharMsg);//Converte valor para envio
       delay(2000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

       
       
       delay(1000);
       valor = p4;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

       
       
       delay(1000);
       valor = p5;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

      
      
       delay(1000);
       valor = p6;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

      
      
       delay(1000);
       valor = alfa;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados

       
      
       delay(1000);
       valor = beta;
       dtostrf (valor, 4, 2, Valor_CharMsg); //Converte valor para envio
       delay(1000);
       vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
       vw_wait_tx(); //Aguarda envio dos dados
      }
    }
  }
}

