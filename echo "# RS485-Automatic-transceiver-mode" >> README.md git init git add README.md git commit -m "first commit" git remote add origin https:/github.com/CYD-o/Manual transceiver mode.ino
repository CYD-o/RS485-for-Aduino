/*
# This sample codes is for testing the RS485 shiled(manual transmission mode).
# EN = 2；
# Editor : YouYou
# Date   : 2013.9.16
# Ver    : 0.1
# Product: RS485 shield
# SKU    : DFR0259
*/
int led = 13;    //定义LED所在灯管脚
int EN = 2;    //定义RS485扩展板的使能端（2号数字IO口），高电平为发送状态，低电平为接收状态
void setup()
{
  Serial.begin(9600);     //初始化串口
  pinMode(led,OUTPUT);
  pinMode(EN,OUTPUT);
}
void loop()
{
  int temp;   //串口数据临时缓存
  digitalWrite(EN,LOW);    //使能端低电平，RS485扩展板等待接收数据
  if(Serial.available())    //如果串口接收到数据了
  {
    temp=Serial.read();   
     if(temp=='V')  //如果接收到的数据是字符“V”，则改变LED灯的状态
     {
      digitalWrite(led,1-digitalRead(led));
      digitalWrite(EN,HIGH);    //使能端高电平，RS485扩展板处于发送状态
      Serial.println("OK");    //回复OK，表示收到了字符“V”，并改变了LED的状态
      delay(10);    //延时一段时间，等待数据发送完
     }
  }
}
