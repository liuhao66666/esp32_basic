int DAC_Pin = 25; //DAC1
 
hw_timer_t * timer = NULL;
int dac_num = 0;
int step_num = 0;
float sinWave[32] = {2448,2832,3186,3496,3751,3940,4057,4095,
                    4057,3940,3751,3496,3186,2832,2448,2048,
                    1648,1264,910,600,345,156,39,0,
                    39,156,345,600,910,1264,1648,2048}; //正弦信号数值

void tim1Interrupt() //中断服务函数
{
  dac_num = 255*(sinWave[step_num]/4095.0); 
  step_num++;
  if(step_num == 32){step_num=0;}
  dacWrite(DAC_Pin,dac_num);
}

void setup() {
  Serial.begin(115200);
  pinMode(DAC_Pin,OUTPUT); //DAC引脚初始化
  timer = timerBegin(0, 80, true); //使用定时器0、80分频、向上计数
  timerAttachInterrupt(timer, &tim1Interrupt, true); //开启定时器中断，电平触发
  timerAlarmWrite(timer, 100, true); //周期10000*1us=10ms
  timerAlarmEnable(timer);
}

void loop() {
  
}
