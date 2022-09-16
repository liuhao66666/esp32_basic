String A = "0"; //用于存储用户输入的字符串A
String B = "0"; //用于存储用户输入的字符串B
int A_number = 0; //用于存储字符串转换成整型的数字A
int B_number = 0; //用于存储字符串转换成整型的数字B
bool A_flag = false; //判断用户是否输入A
bool B_flag = false; //判断用户是否输入B

void setup() {
  Serial.begin(115200);  //初始化串口1
}

void loop() {
  if(!A_flag && !B_flag)  //此时用户没有输入A和B，两个标志位均为false
  {
    Serial.printf("Please input A \r\n");
    while(Serial.available() == 0); //等待用户输入A
    A = Serial.readString(); //存储字符串A
    A_flag = true; //A已经输入，更新标志位
  }
  if(A_flag && !B_flag)   //此时用户已经输入A，只有B标志位为false
  {
    Serial.printf("Please input B \r\n");
    while(Serial.available() == 0); //等待用户输入B
    B = Serial.readString(); //存储字符串B
    B_flag = true; //B已经输入，更新标志位
  }
  if(A_flag && B_flag)  //此时用户已经输入A和B，将字符串转换为整型并相加
  {
    for(int i=0;i<A.length()-1;i++) //将A转换为整型
    {
      A_number = A_number*10 + (A.charAt(i)-'0'); 
    }
    for(int i=0;i<B.length()-1;i++) //将B转换为整型
    {
      B_number = B_number*10 + (B.charAt(i)-'0'); 
    }
    Serial.printf("A+B=%d\r\n",A_number+B_number); //将A和B相加并输出
    A_number = 0;   //数字A归零
    B_number = 0;   //数字B归零
    A_flag = false; //标志位A改为false
    B_flag = false; //标志位B改为false
    
  }
  
}
