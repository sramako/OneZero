
String bluetoothRead, Str_x, Str_y, Str_p;
int x ;
int y ;
int points;
int length;

int pwmMotorA=11;
int pwmMotorB=10;
int ForwardA=8;
int BackA=9;
int ForwardB=6;
int BackB=7;




void setup() {
  Serial.begin(9600);       
  
  
  
  pinMode(pwmMotorA, OUTPUT); 
  pinMode(ForwardA, OUTPUT); 

  pinMode(BackA, OUTPUT);   
  pinMode(pwmMotorA, OUTPUT);
  
  pinMode(ForwardB, OUTPUT); 
  pinMode(BackB, OUTPUT); 
  
  analogWrite(pwmMotorA, 140);
  analogWrite(pwmMotorB, 140);
  

}

void loop() {
 int i=0;
  char commandbuffer[200];


  if(Serial.available()){
    
     delay(10);

     while( Serial.available() && i< 199) {
        commandbuffer[i++] = Serial.read();
  
      
     }
     commandbuffer[i++]='\0';
     bluetoothRead = (char*)commandbuffer;
     length = bluetoothRead.length();
  
  
     
     if(bluetoothRead.substring(0, 1).equals("x")){
       
       int i=1;
       while(bluetoothRead.substring(i, i+1) != ("y")){
       i++;
       }
       
       Str_x = bluetoothRead.substring(1, i);
       x = Str_x.toInt();
       
 
     
       Str_y = bluetoothRead.substring(i+1, length -1);
       y = Str_y.toInt();
       
        Str_p = bluetoothRead.substring(length - 1, length);
        points = Str_p.toInt();

       i = 1;
       
      
      Stop();
 
 if(x < 40){
   Left();
  
  }
  if(x > 140){
    Right();
    
  } 
  if(x < 140 && x > 40){
    if(points == 1){
   Forward(); 
    }
    if(points == 0){
    Stop();
    }
    if(points == 2){
     Back(); 
    }
  }

     

}
}
}





void Left(){
  digitalWrite(ForwardA, LOW); 
  digitalWrite(BackA, HIGH);

  digitalWrite(ForwardB, HIGH); 
  digitalWrite(BackB, LOW);
  
}


void Right(){
  
  digitalWrite(ForwardA, HIGH); 
  digitalWrite(BackA, LOW);
    
  digitalWrite(ForwardB, LOW); 
  digitalWrite(BackB, HIGH);
  
}


void Forward(){
  digitalWrite(ForwardA, HIGH); 
  digitalWrite(BackA, LOW);
    
  digitalWrite(ForwardB, HIGH); 
  digitalWrite(BackB, LOW);
}


void Back(){
  digitalWrite(ForwardA, LOW); 
  digitalWrite(BackA, HIGH);

  digitalWrite(ForwardB, LOW); 
  digitalWrite(BackB, HIGH);
}


void Stop(){ 
  digitalWrite(ForwardA, LOW); 
  digitalWrite(BackA, LOW);
  
  digitalWrite(ForwardB, LOW); 
  digitalWrite(BackB, LOW);
}
