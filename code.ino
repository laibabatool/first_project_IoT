int trigger_pin = 2;

int echo_pin = 3;

int buzzer_pin = 10; 

int time;

int distance; 




void setup ( ) {

        Serial.begin (9600); 

        pinMode (trigger_pin, OUTPUT); 

        pinMode (echo_pin, INPUT);

        pinMode (buzzer_pin, OUTPUT);
        pinMode(A0, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);




}




void loop ( ) {
  
  float reading = analogRead(A0);
  // put your main code here, to run repeatedly:
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;
  Serial.print(temperatureC); Serial.print("Centigrade");
  Serial.println();
 // delay(2000);
  if (temperatureC >= 20)
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  else if (temperatureC <= 10)
  {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }

    digitalWrite (trigger_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.034) / 2;

    

  if (distance <= 10) 

        {

        Serial.println (" Door Open ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, HIGH);

        delay (500);

        }

  else {

        Serial.println (" Door closed ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);

        delay (500);        

  } 

  }
