#include "ring.h" //含有所有旋律音高宏定义的头文件
int melody[]={

NOTE_G4, //5

NOTE_E4, //3

NOTE_E4, //3

NOTE_E4, //3

NOTE_E4, //3

NOTE_F4, //4

NOTE_G4,  //5

NOTE_D4, //2

NOTE_G4, //5

NOTE_D4, //2

NOTE_D4, //2

NOTE_D4, //2

NOTE_D4, //2

NOTE_E4, //3

NOTE_F4, //4

NOTE_E4, //3

NOTE_C4, //1

NOTE_A4, //6

NOTE_A4, //6

NOTE_A4, //6

NOTE_A4, //6

NOTE_B4, //7

NOTE_C5, //1.
NOTE_G3, //.5
NOTE_F4, //4

NOTE_E4, //3/

NOTE_C4, //1

NOTE_D4, //2



NOTE_C4, //1

0,

NOTE_D4, //2

NOTE_G3, //.5

NOTE_C4, //1

0,
NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD3,NTD2,NTD2,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1,
  NTD2,NTD2,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD2,
  NTD1,NTD2,NTDL5,NTD0,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD4,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1

};

//持续时间函数

int noteDurations[]={

4,4,4,4,

4,4,4,4,

4,4,2,

4,4,2,

4,4,4,4,2,2,

4,4,4,4,2,2,

2,2,2,2,

2,2,2,2,
1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,0.5,0.5,1,1,
  1,0.5,0.5,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,0.5,0.5,
  1,1,1,1,
  1+0.5,0.5,1+1,
};

//播放命令

void play()

{

for(int thisNote = 0;thisNote<29;thisNote++){

//计算旋律持续时间
int noteDuration = 1000/noteDurations[thisNote];

tone(4,melody[thisNote], noteDuration);//播放音乐

//为了区别不同旋律，设置一个最小的间隔时间



int pauseBetweenNotes = noteDuration * 1.30;

delay(pauseBetweenNotes);

//停止当前旋律播放

noTone(8);

}
}
