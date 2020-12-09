#include <U8glib.h>
#include "doorring.h"
#include "words.h"

int length;
int tonepin=6;//定义蜂鸣器接口
int ledp=12;//定义LED灯接口
int Sensor = 8; //接收传感器的信号

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);     //设置OLED型号
//-------字体设置，大、中、小
#define setFont_L u8g.setFont(u8g_font_7x13)
#define setFont_M u8g.setFont(u8g_font_fixed_v0r)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_SS u8g.setFont(u8g_font_fub25n)
#define INTERVAL_LCD             20             //定义OLED刷新时间间隔  
unsigned long lcd_time = millis();                 //OLED刷新时间计时器

void setup() {
  
pinMode(tonepin,OUTPUT);
pinMode(ledp,OUTPUT);
length=sizeof(melody)/sizeof(melody[0]);
pinMode(Sensor, INPUT); 
pinMode(10,OUTPUT);
// 设置为输入
}

void loop() {
 ring();
 led();
 delay(500);     
}

void ring(){
    for(int x=0;x<length;x++)//使LED灯随着音乐闪烁
  {
    tone(tonepin,melody[x]);
    digitalWrite(ledp, HIGH);//高电平亮灯
    delay(400*noteDurations[x]); 
    digitalWrite(ledp, LOW);//低电平灭灯
    delay(100*noteDurations[x]);
    noTone(tonepin);
  } 
    play();//播放音乐的命令
}

void led(){
  
 int val = digitalRead(Sensor); // 读取引脚电平
 int a=1;
 int b=2;
 if (val==1)  // 若检测到有人，则val值为1
 {
  digitalWrite(10,HIGH);      
  delay(500);
  digitalWrite(10,LOW);
  delay(500);
  u8g.firstPage();
      do {
    setFont_M;
    u8g.drawBitmapP(0, 0, 16, 16, I);
   } while (u8g.nextPage());
 }
  else
  {
  digitalWrite(10,LOW);
  u8g.firstPage();
  do {
    setFont_M;
    u8g.drawBitmapP(0, 0, 16, 64, ri);
      }while (u8g.nextPage());
  delay(500);
  }
}
