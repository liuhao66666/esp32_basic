int DAC_Pin = 25; //DAC1

String dac_str; //存储串口接收到的字符串信息
int dac_val = 0; //存储输出电压数值

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //初始化串口
  pinMode(DAC_Pin,OUTPUT);  //将DAC引脚转换成输出模式
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) //判断串口是否姐接收到数据
  {
    dac_val = 0; //将电压信息转换成0
    dac_str = Serial.readString(); //读取串口接收到的字符串
    for(int i=0;i<dac_str.length()-1;i++) //将A转换为整型
    {
      dac_val = dac_val*10 + (dac_str.charAt(i)-'0'); //将字符串转换为数值
    }
  }
  if(0 <= dac_val && dac_val<= 3300 ) //判断数值是否在0到3300之间
  {
    dacWrite(DAC_Pin, ((double)dac_val/3300)*255);  // 输出DAC
  }
  
}
