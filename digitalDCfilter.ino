/* 
this has been taken and modified from

http://openenergymonitor.org/emon/buildingblocks/digital-filters-for-offset-removal

Acknowledgements duly noted.

*/
int sample = 0;
int last_sample = 0;
double filtered_value = 0;
double last_filtered_value = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // Generate a test signal
  last_sample = sample;
  sample = analogRead(A0);      // read in the next value
  
  last_filtered_value = filtered_value;
  
  // LPF 10Hz corner freq, IIR Butterworth 1st order
  filtered_value = 0.996 * (filtered_value + sample - last_sample);    
  
  //Serial.print(sample);
  //Serial.print(' ');
  Serial.println(filtered_value);
  delay(10);
}
