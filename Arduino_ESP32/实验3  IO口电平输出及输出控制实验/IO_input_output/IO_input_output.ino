int LED = 2;
int KEY = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT); //将P2设置为输出模式
  pinMode(KEY,INPUT); //将P0设置成输入模式
  digitalWrite(LED,HIGH); //点亮LED
  delay(100); //延时100ms
  digitalWrite(LED,LOW); //熄灭LED
  delay(100); //延时100ms
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(KEY) == LOW) //按下key键
  {
    digitalWrite(LED,HIGH);
    while(digitalRead(KEY) == LOW); //等待key键松开
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}
