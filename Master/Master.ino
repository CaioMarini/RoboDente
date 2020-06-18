

#define pinVRx A0
#define pinVRy A1
#define button 7//Botao musica
int buttonState = 0;//botao musica
#define botopassum 8 //botao motor passo um
int bpsum = 0;//botao passo um
#define botopassdois 9//botao motor passi dois
int bpsdois = 0;//botao passo dois
void setup() {
  // put your setup code here, to run once:
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(button,INPUT);
  Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);

  buttonState = digitalRead(button);
  bpsum = digitalRead(botopassum);
  bpsdois = digitalRead(botopassdois);

  //Serial.print("\n   Valor VRX: ");
  //Serial.print(valorVRx);
  //Serial.print("   Valor VRy: ");
  //Serial.print(valorVRy);

  


  if(valorVRx <= 300){
    //Serial.print("\nF");
    Serial.write('F');//Frente
    delay(20);
  }else if(valorVRx >=1000){
   // Serial.print("\n T");//Volta
    Serial.write('T');
    delay(20);
  }else if(valorVRy <= 100){
    //Serial.print("\nD");//Direita
    Serial.write('D');
    delay(20);
  }else if(valorVRy >=1000){
   // Serial.print("\nE");//esquerda
    Serial.write('E');
    delay(20);
  }
  else if(buttonState == HIGH){
    Serial.write('O');
    delay(300);
  }else if(bpsum == HIGH){
    Serial.write('W');
    delay(300);
  }else if(bpsdois == HIGH){
    Serial.write('S');
    delay(300);
  }else{
   Serial.write('A');
    delay(20);
  }
  
  
  
  
  
}

  
