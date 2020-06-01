int moistPin = 0;
int moistVal = 0;
int tooDry = 150; //set low parameter for plant
int tooWet = 400; //set high parameter for plant
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  moistVal = analogRead(moistPin);
  Serial.println(moistVal);
  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); //calculate percent for probes about 1 - 1.5 inches apart
  Serial.print(percent);
  Serial.println("% Moisture ");
  if (moistVal <= tooDry) {
    digitalWrite(2, HIGH); //Red LED
  }
   else if (moistVal >= tooDry) {
    digitalWrite(2, LOW); //Red LED
  }
  delay(250);
}
