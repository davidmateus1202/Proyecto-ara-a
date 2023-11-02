#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// canal en el que estan conectado cada servo

#define servo1 0
#define servo2 1
#define servo3 2
#define servo4 3
#define servo5 4
#define servo6 5
#define servo7 6
#define servo8 7


// pulsos maximos y minimos de cada servo

#define servo1_pulso_minimo 300 // Valor mínimo para el pulso PWM
#define servo1_pulso_maximo 400 // Valor maximo para el pulso PWM

#define servo2_pulso_minimo 300
#define servo2_pulso_maximo 400

#define servo3_pulso_minimo 330
#define servo3_pulso_maximo 400

#define servo4_pulso_minimo 50
#define servo4_pulso_maximo 500

#define servo5_pulso_minimo 200
#define servo5_pulso_maximo 400

#define servo6_pulso_minimo 350
#define servo6_pulso_maximo 400

#define servo7_pulso_minimo 300
#define servo7_pulso_maximo 400

#define servo8_pulso_minimo 100
#define servo8_pulso_maximo 400




int direction = 1; // Dirección de movimiento (1 para aumentar, -1 para disminuir)
int step = 5; // Incremento en la posición en cada ciclo del bucle

char valor;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);  // Frecuencia de PWM en Hz


  // Ajusta el rango de pulsos PWM para tu servo específico
  pwm.setPWM(servo1, 0, servo1_pulso_minimo);  // Conecta el servo al canal 0
  pwm.setPWM(servo2, 0, servo2_pulso_minimo);
  pwm.setPWM(servo3, 0, servo3_pulso_minimo);
  pwm.setPWM(servo4, 0, servo4_pulso_minimo);
  pwm.setPWM(servo5, 0, servo5_pulso_minimo);
  pwm.setPWM(servo6, 0, servo6_pulso_minimo);
  pwm.setPWM(servo7, 0, servo7_pulso_minimo);
  pwm.setPWM(servo8, 0, servo8_pulso_minimo);

  delay(1000);
}


void loop() {

  mover_pata1();
  mover_pata2();
  
}



void mover_pata1(){

   for (int posicion = servo6_pulso_minimo; posicion <= 550 ; posicion+=3 ){
    
    pwm.setPWM(servo6, 0, posicion);
    delay(5); 
  }

  // for que sube la garrita
  for (int posicion = servo1_pulso_minimo; posicion >= 100; posicion-=3){
    
  

    pwm.setPWM(servo1, 0, posicion);
    delay(5); 
  }
   
   for (int posicion = servo2_pulso_minimo; posicion <= 400   ; posicion+=3){
    
    pwm.setPWM(servo2, 0, posicion);
    delay(5); 
  }
  
  for (int posicion = 100; posicion <= servo1_pulso_minimo; posicion+=3 ){
    
    pwm.setPWM(servo1, 0, posicion);
    delay(5); 
  }
  for (int posicion = 400; posicion >= servo2_pulso_minimo   ; posicion-=3 ){
    
    pwm.setPWM(servo2, 0, posicion);
    delay(5); 
  }

  for (int posicion = 550; posicion >= servo6_pulso_minimo   ; posicion-=3){
    
    pwm.setPWM(servo6, 0, posicion);
    delay(5); 
  } 
}

void mover_pata2(){

  // mover servo 7 para pata 2

  for (int posicion = servo7_pulso_minimo; posicion >= 200 ; posicion-=3 ){
    
    pwm.setPWM(servo7, 0, posicion);
    delay(5); 
  }

  // for para levantar la garrita del servo 4 

  for (int posicion = servo4_pulso_minimo; posicion <= 400; posicion+=3){
    
    pwm.setPWM(servo4, 0, posicion);
    delay(5); 
  }

  // for para mover la pata de servo 3

  for (int posicion = servo3_pulso_minimo; posicion >=180  ; posicion-=3){
    
    pwm.setPWM(servo3, 0, posicion);
    delay(5); 
  }


  // finaliza movimiento del servo 4

  for (int posicion = 400; posicion >= servo4_pulso_minimo; posicion-=3){
    
    pwm.setPWM(servo4, 0, posicion);
    delay(5); 
  }

  //finaliza movimiento del servo 3

  for (int posicion2 = 180; posicion2 <= servo3_pulso_minimo; posicion2+=3){
    
    pwm.setPWM(servo3, 0, posicion2);
    delay(5); 
  }

 //ALZA LA GARRITA EL SEVO 8
   
   for (int posicion = servo8_pulso_minimo; posicion <= 400; posicion+=3){
    
    pwm.setPWM(servo8, 0, posicion);
    delay(5); 
  }



  // finaliza movimiento del servo7


  for (int posicion = 200; posicion <= servo7_pulso_minimo   ; posicion+=3 ){
    
    pwm.setPWM(servo7, 0, posicion);
    delay(5); 
  }
   //finalza el movimiento del servo 8
      for (int posicion = 400; posicion >= servo8_pulso_minimo; posicion-=3){
    
    pwm.setPWM(servo8, 0, posicion);
    delay(5); 
  }


    
  
   
}
