int buzzer_pin = 2;

String freq_str;

int freq = 5000; // 设置PWM的频率
int ledChannel = 0; // 设置PWM的通道
int resolution = 8; // 设置PWM 占空比的分辨率 最大占空比为 2^8 = 256

void setup() {
  Serial.begin(115200);
  ledcSetup(ledChannel, freq, resolution); // PWM初始化
  ledcAttachPin(buzzer_pin, ledChannel); // 绑定PWM通道到GPIO2上
}

void loop() {
  if(Serial.available() > 0) //判断串口是否接收到消息
  {
    freq = 0; //将频率归零
    freq_str = Serial.readString(); //读取串口接收到的频率信息
    for(int i=0;i<freq_str.length()-1;i++) 
    {
      freq = freq*10 + (freq_str.charAt(i)-'0'); 
    }
    ledcSetup(ledChannel, freq, resolution); // PWM初始化
  }
  
  ledcWrite(ledChannel, 127); //设置占空比
}
