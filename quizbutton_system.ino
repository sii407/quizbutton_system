int button_push_r=0;
int button_push_b=0;
int scorey_r=0;
int scorey_b=0;
int scoren_r=0;
int scoren_b=0;
int ry=0;
int rn=0;
int by=0;
int bn=0;
//LiquidCrystal lcd{};

void setup(){
  Serial.begin(9600);
  //buttom
  int i;  

  for(i=2; i<6; i++){
    pinMode(i,INPUT_PULLUP);
  }
  for (i=12; i<14; i++){
    pinMode(i,OUTPUT);
  }
  //reset
  pinMode(7,INPUT_PULLUP);
}

void loop(){
  if(digitalRead(2)==LOW && button_push_r==0){
    digitalWrite(12,HIGH);
    button_push_b=1;
  } 
  if(digitalRead(3)==LOW && button_push_b==0){
    digitalWrite(13,HIGH);
    button_push_r=1;
  }
  if(digitalRead(7)==LOW){
    
    if(ry==1){
      scorey_r=scorey_r+1;
    }
    if(rn==1){
      scoren_r=scoren_r+1;
    }
    if(by==1){
      scorey_b=scorey_b+1;
    }
    if(bn==1){
      scoren_b=scoren_b+1;
    }
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    button_push_r=0;
    button_push_b=0;
    Serial.println("Red");
    Serial.print(" 正解数:");
    Serial.println(scorey_r);
    Serial.print(" 誤答数:");
    Serial.println(scoren_r);

    Serial.println("Blue");
    Serial.print(" 正解数:");
    Serial.println(scorey_b);
    Serial.print(" 誤答数:");
    Serial.println(scoren_b);
    Serial.println("----------");
    delay(1000);
    ry=0;
    rn=0;
    by=0;
    bn=0;
  }
  if(digitalRead(4)==LOW){
    if(button_push_r==1){
      ry=1;
    
    }
    if(button_push_b==1){
      by=1;
    }
  }
  if(digitalRead(5)==LOW){
    if(button_push_r==1){
      rn=1;
    }
    if(button_push_b==1){
      bn=1;
    }
  }

}