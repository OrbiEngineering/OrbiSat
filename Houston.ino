#include <VirtualWire.h>

int valor;
char Valor_CharMsg[4];
float valRec;
char recebido_RF_char[4];
char comando;

void setup() {

  Serial.begin(9600);

  //TRANSMISSOR
  vw_set_tx_pin(6);
  vw_setup(500);

  //RECEPTOR
  vw_set_rx_pin(9);
  vw_setup(500);
  vw_rx_start();

}

void loop() {

  comando = Serial.read();

  //TRANSMISSOR
  if (comando == '1') {

    valor = 1;
    itoa (valor, Valor_CharMsg, 10); //Converte valor para envio
    delay(1000);
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
    vw_wait_tx(); //Aguarda envio dos dados
    delay(1000);

    //RECEPETOR
    //Estabilização
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
      valRec = atof(recebido_RF_char);

    }

    Serial.print("Estabilizacao de sinal... ");


    delay(2000);


    uint8_t buf2[VW_MAX_MESSAGE_LEN];
    uint8_t buf2len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf2, &buf2len))
    {
      int i;
      for (i = 0; i < buf2len; i++)
      {
        recebido_RF_char[i] = char(buf2[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf2len] = '\0';
      valRec = atof(recebido_RF_char);

    }

    Serial.print("Temperatura: ");
    Serial.println(valRec);
  }



  //TRANSMISSOR
  if (comando == '2') {

    valor = 2;
    itoa (valor, Valor_CharMsg, 10); //Converte valor para envio
    delay(1000);
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
    vw_wait_tx(); //Aguarda envio dos dados
    delay(1000);

    //RECEPETOR
    //Estabilização
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
      valRec = atof(recebido_RF_char);
    }

    Serial.print("Estabilizacao de sinal...");


    delay(2000);

    uint8_t buf1[VW_MAX_MESSAGE_LEN];
    uint8_t buf1len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf1, &buf1len))
    {
      int i;
      for (i = 0; i < buf1len; i++)
      {
        recebido_RF_char[i] = char(buf1[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf1len] = '\0';
      valRec = atof(recebido_RF_char);

    }

    Serial.print(". ");


    delay(2000);

    
    uint8_t buf2[VW_MAX_MESSAGE_LEN];
    uint8_t buf2len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf2, &buf2len))
    {
      int i;
      for (i = 0; i < buf2len; i++)
      {
        recebido_RF_char[i] = char(buf2[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf2len] = '\0';
      valRec = atof(recebido_RF_char);
    }

    Serial.print("Umidade: ");
    Serial.println(valRec);

  }

  //TRANSMISSOR
  if (comando == '3') {

    valor = 3;
    itoa (valor, Valor_CharMsg, 10); //Converte valor para envio
    delay(1000);
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //Envio dos dados
    vw_wait_tx(); //Aguarda envio dos dados
    delay(1000);

    //RECEPETOR
    //Estabilização
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
      valRec = atof(recebido_RF_char);
    }

    Serial.print("Estabilizacao de sinal...");


    delay(2000);
    
    uint8_t buff1[VW_MAX_MESSAGE_LEN];
    uint8_t buff1len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buff1, &buff1len))
    {
      int i;
      for (i = 0; i < buff1len; i++)
      {
        recebido_RF_char[i] = char(buff1[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buff1len] = '\0';
      valRec = atof(recebido_RF_char);

    }

    Serial.print(".");


    delay(2000);
    
    uint8_t buff2[VW_MAX_MESSAGE_LEN];
    uint8_t buff2len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buff2, &buff2len))
    {
      int i;
      for (i = 0; i < buff2len; i++)
      {
        recebido_RF_char[i] = char(buff2[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buff2len] = '\0';
      valRec = atof(recebido_RF_char);

    }

    Serial.println(".");


    delay(3000);



    //SINAL PLACA 1
    uint8_t buf1[VW_MAX_MESSAGE_LEN];
    uint8_t buf1len = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf1, &buf1len))
    {
      int i;
      for (i = 0; i < buf1len; i++)
      {
        recebido_RF_char[i] = char(buf1[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf1len] = '\0';
      valRec = atof(recebido_RF_char);
    }

    Serial.print(" P1  ");
    Serial.print(valRec);
    Serial.print(" Volts");


    delay(2000);


    //SINAL PLACA 2
    uint8_t buf2[VW_MAX_MESSAGE_LEN];
    uint8_t buf2len = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(buf2, &buf2len))
    {
      int i;
      for (i = 0; i < buf2len; i++)
      {
        recebido_RF_char[i] = char(buf2[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf2len] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" P2  ");
    Serial.print(valRec);
    Serial.print(" Volts");


    delay(2000);


    //SINAL PLACA 3
    uint8_t buf3[VW_MAX_MESSAGE_LEN];
    uint8_t buf3len = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(buf3, &buf3len))
    {
      int i;
      for (i = 0; i < buf3len; i++)
      {
        recebido_RF_char[i] = char(buf3[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf3len] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" P3  ");
    Serial.print(valRec);
    Serial.print(" Volts");


    delay(2000);

    //SINAL PLACA 4
    uint8_t buf4[VW_MAX_MESSAGE_LEN];
    uint8_t buf4len = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(buf4, &buf4len))
    {
      int i;
      for (i = 0; i < buf4len; i++)
      {
        recebido_RF_char[i] = char(buf4[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf4len] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" P4  ");
    Serial.print(valRec);
    Serial.print(" Volts");


    delay(2000);

    //SINAL PLACA 5
    uint8_t buf5[VW_MAX_MESSAGE_LEN];
    uint8_t buf5len = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(buf5, &buf5len))
    {
      int i;
      for (i = 0; i < buf5len; i++)
      {
        recebido_RF_char[i] = char(buf5[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf5len] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" P5  ");
    Serial.print(valRec);
    Serial.print(" Volts");

    delay(2000);

    //SINAL PLACA 6
    uint8_t buf6[VW_MAX_MESSAGE_LEN];
    uint8_t buf6len = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(buf6, &buf6len))
    {
      int i;
      for (i = 0; i < buf6len; i++)
      {
        recebido_RF_char[i] = char(buf6[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[buf6len] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" P6  ");
    Serial.print(valRec);
    Serial.print(" Volts");

    delay(2000);

    //SINAL ÂNGULO ALFA
    uint8_t bufA[VW_MAX_MESSAGE_LEN];
    uint8_t bufAlen = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(bufA, &bufAlen))
    {
      int i;
      for (i = 0; i < bufAlen; i++)
      {
        recebido_RF_char[i] = char(bufA[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[bufAlen] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" Alfa:  ");
    Serial.print(valRec);
    Serial.print(" graus");

    delay(2000);

    //SINAL ÂNGULO BETA
    uint8_t bufB[VW_MAX_MESSAGE_LEN];
    uint8_t bufBlen = VW_MAX_MESSAGE_LEN;

    delay(1000);

    if (vw_get_message(bufB, &bufBlen))
    {
      int i;
      for (i = 0; i < bufBlen; i++)
      {
        recebido_RF_char[i] = char(bufB[i]); //Armazena os caracteres recebidos
      }
      recebido_RF_char[bufBlen] = '\0';
      valRec = atof(recebido_RF_char);
    }
    Serial.print(" Beta:  ");
    Serial.print(valRec);
    Serial.println(" graus");

  }
}
