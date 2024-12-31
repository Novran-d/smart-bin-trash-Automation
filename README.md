# smart-bin-trash-Automation dengan arduino uno
gambar skecth sirkuit PENGEMBANGAN TEMPAT SAMPAH OTOMATIS BERBASIS ARDUINO DENGAN SENSOR ULTRASONIC “SMART TRASH BIN“


## Komponen" Yang Dibutuhkan (Tools & Materials):

• Arduino Uno = 1 unit- Mikrokomputer yang akan mengendalikan seluruh sistem.
• Sensor ultrasonic = 1 uni- Digunakan untuk mendeteksi jarak antara tutup tempat sampah dan benda di sekitarnya.
• Servo Motor  = 1 unit- Untuk membuka dan menutup tutup tempat sampah secara otomatis.
• Breadboard dan Kabel Jumper - Untuk membuat sambungan antara komponen.

## Koneksi Komponen:
### • Sensor Ultrasonik:

•Pin VCC sensor dihubungkan ke pin 5V Arduino.
•Pin GND sensor dihubungkan ke pin GND Arduino.
•Pin Trig sensor dihubungkan ke pin Digital 9 Arduino.
•Pin Echo sensor dihubungkan ke pin Digital 8 Arduino.

### • Motor Servo:

Kabel daya motor servo (merah) dihubungkan ke pin 5V Arduino.
Kabel GND motor servo (cokelat/hitam) dihubungkan ke GND Arduino.
Kabel sinyal motor servo (kuning/oranye) dihubungkan ke pin Digital 7 Arduino.

## Daya dan Ground:

Breadboard digunakan untuk menghubungkan jalur daya dan ground ke beberapa komponen.
Arduino Uno dihubungkan ke sumber daya melalui kabel USB.

## Alur Kerja:

Sensor ultrasonik mendeteksi objek dalam jarak tertentu.
Arduino memproses data dan mengirimkan sinyal ke motor servo.
Motor servo bergerak untuk membuka atau menutup penutup berdasarkan jarak yang terdeteksi.


## Circuit Schematic:

![Circuit-Schematic](img/Neat.jpg)

## Sketch Code Program:

```cpp
#include <Servo.h>

Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(4);
}

void loop()
{
  pinMode(13, OUTPUT);
  
  digitalWrite(13, LOW);
  //delayMicroseconds(5);
  digitalWrite(13, HIGH);
  //delayMicroseconds(5);
  digitalWrite(13, LOW);
  
  pinMode(13, INPUT);
  int duration = pulseIn(13, HIGH);
  Serial.println(duration);
  int cm = duration / 87;
  
  Serial.println(cm);
  
  if(cm <=25){
  	servo.write(0);
  }
  else if(cm <= 50){
  	servo.write(30);
  }
  else if(cm <= 100){
  	servo.write(50);
  }
  else if(cm <= 150){
  	servo.write(70);
  }
  else if(cm <= 170){
  	servo.write(100);
  }
  else if(cm <= 200){
  	servo.write(130);
  }
  else if(cm <= 250){
  	servo.write(150);
  }
  else{
  	servo.write(180);
  }
  delay(100);
}
```

## Conclusion:

- If the intensity of sunlight hitting this sensor decreases, the output from the LDR will be read by the Arduino and the lighting will activate itself and vice versa, if the intensity of sunlight hitting this sensor increases, then the output from the LDR will be read by the Arduino and the lighting will turn itself off. .
