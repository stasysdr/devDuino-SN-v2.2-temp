#define OTA_ENABLE        4 // Button D4
#define LED_PIN           9 // LED 

int TEMP_SENSE_PIN = A3;  // Input pin for the Temp sensor MCP9700
float TEMP_SENSE_OFFSET = -0.01;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT); 
 
  Serial.begin(115200);
  Serial.println(F("devDuino SNv2.2"));
  digitalWrite(LED_PIN, HIGH); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH); 
  float temp = readMCP9700(TEMP_SENSE_PIN,TEMP_SENSE_OFFSET);
  Serial.println(temp);
  digitalWrite(LED_PIN, LOW);
  delay(3000);
}

float readMCP9700(int pin,float offset)
 
{
  analogReference(INTERNAL);
 
  analogRead(A0); //perform a dummy read to clear the adc
  delay(20);
 
  for (int n=0;n<5;n++)
    analogRead(pin);
 
  int adc=analogRead(pin);
  float tSensor=((adc*(1.1/1024.0))-0.5+offset)*100;
  float error=244e-6*(125-tSensor)*(tSensor - -40.0) + 2E-12*(tSensor - -40.0)-2.0;
  float temp=tSensor-error;
 
  return temp;
}
