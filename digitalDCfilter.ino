/* 
    this has been made by filter design assistance from http://www-users.cs.york.ac.uk/~fisher/cgi-bin/mkfscript
*/
int sample = 0;
int last_sample = 0;
double filtered_value = 0;
double last_filtered_value = 0;
double GAIN = 4.077683537;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // We're going to read in samples from the analog port
  // then process them and send through serial. 
  // These wil be plotted on some kind of serial oscilloscope.
  
  last_sample = sample;
  sample = analogRead(A0)/GAIN;      // read in the next value
  
  last_filtered_value = filtered_value;
  
  // LPF 10Hz corner freq, IIR Butterworth 1st order
  filtered_value = (sample + last_sample) + (0.5095254495*last_filtered_value);    
  
  //Serial.print(sample);
  //Serial.print(' ');
  Serial.println(filtered_value);
  // delay(10);
}
