/*
# This sample codes is for testing the RS485 shiled(automatic transmission mode).
# Editor : YouYou
# Date   : 2013.9.16
# Ver    : 0.1
# Product: RS485 shield
# SKU    : DFR0259
*/
int led = 13;    //定义LED所在灯管脚
void setup()
{
  Serial.begin(9600);    //初始化串口
  pinMode(led,OUTPUT);
}
void loop()
{
  int temp;    //串口数据临时缓存
  if(Serial.available())    //如果串口接收到数据了
  {
    temp=Serial.read();    //暂存接收到的数据
     if(temp=='V'){
      digitalWrite(led,1-digitalRead(led));    //如果接收到的数据是字符“V”，则改变LED灯的状态
    Serial.println("OK");    //回复OK，表示收到了字符“V”，并改变了LED的状态
     }
  }
}
