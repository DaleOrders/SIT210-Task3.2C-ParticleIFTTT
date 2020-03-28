int sensor_pin = A4; /* Soil moisture sensor O/P pin */

//setup
void setup() {
Serial.begin(9600); /* Define baud rate for serial communication */

}
void loop() {
    
    //Read sensor
    int sensor_analog = analogRead(sensor_pin);
    
    //Detects if the plant is overwatered. If so send IFTTT to email notification
    if(sensor_analog>=300)
    {
        Particle.publish("Moisture1", "overwatered");
    }
    
    //It is safe to water the plant. It is not overwatered.
    else 
    {
        Particle.publish("Moisture1", "underwatered");
    }
    Serial.print(sensor_analog);
    Serial.print("%\n\n");
    delay(100000);
}


