int counter=0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(4,INPUT);
}

void loop() {
  if(Serial.available()>0){
      char data=Serial.read()-48;
      if(data==1)
          digitalWrite(13,HIGH);
      else if(data==2)
          digitalWrite(13,LOW);
      else if(data==3){
          int i=0;
          digitalWrite(13,LOW);
          delay(150);
          for(i=0;i<3;i++){
             digitalWrite(13,HIGH);
             delay(500);
             digitalWrite(13,LOW);
             delay(200);
          }
     }
      else if(data==4){
          Serial.setTimeout(8000);
          int variable=Serial.parseInt();
          int result=variable*variable;
          Serial.println(result);
          delay(2000);   
    }
    else if(data==5){
         while(1){
            int button = Serial.read();
            if(button==7)
               break;
            int press=digitalRead(4);
            if(press==HIGH){
                counter++;
                Serial.println(counter);
            }
            while(press==HIGH){
                delay(10);
                press=digitalRead(4);
            }
            while(press==LOW){
                delay(10);
                press=digitalRead(4);
            }
        }
    }
  }
}
    
