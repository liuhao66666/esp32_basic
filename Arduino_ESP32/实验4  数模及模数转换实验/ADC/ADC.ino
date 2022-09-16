int ADC_Pin = 4; //ADC2_0

uint32_t adc_val = 0; //存储电压值原始数据
double voltage = 0; //存储电压值

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //初始化串口
}

void loop() {
  // put your main code here, to run repeatedly:
  adc_val = analogRead(ADC_Pin); //读取IO口输入的电压原始数据
  voltage = (((double)adc_val)/4095)*3.3;  //将电压原始数据转换成实际电压值
  Serial.printf("adc_val:%d, voltage:%lfV.\r\n", adc_val, voltage); //输出电压原始数据和实际电压值
  delay(100);
}
