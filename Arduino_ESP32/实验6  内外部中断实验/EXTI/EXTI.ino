int key = 0;
int led = 2;

boolean flag = true;

void EXTI()  //中断服务函数
{
  flag = !flag;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(key, INPUT);
  attachInterrupt(key, EXTI, FALLING);    // 设置外部中断
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag)
  {digitalWrite(led, HIGH);}
  if(!flag)
  {digitalWrite(led, LOW);}
}
