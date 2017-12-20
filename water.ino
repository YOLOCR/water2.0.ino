#define Humidity_of_Earth A0    //定义AO引脚 
#define Humidity_of_Water A5    //定义A5引脚
void setup() {
  //定义各个引脚的输入输出模式
  pinMode(Humidity_of_Earth, INPUT);
  pinMode(Humidity_of_Water, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);  
}  
void loop() {
  //在串口监视器中打印数据测试
 /* Serial.print("Humidity of earth=");  
  Serial.print(analogRead(Humidity_of_Earth));//在串口监视器中打印A0读取的湿度的数值  
  Serial.print("|D7=");  
  Serial.println(digitalRead(7));//在串口监视器中打印D7读取的数数值
  Serial.print("Humidity of water=");  
  Serial.print(analogRead(Humidity_of_Water));//在串口监视器中打印A0读取的湿度的数值  
  Serial.print("|D8=");  
  Serial.println(digitalRead(8));//在串口监视器中打印D7读取的数数值
  delay(1000);*/
  //控制水泵开关
  int a=analogRead(Humidity_of_Earth);
  int b=digitalRead(8);
  if(a>500&&b<1){
    digitalWrite(6,1);//当湿度值小于设定值且水位高于设定值时，D6引脚为高电平，水泵开启
  }
  else {
    digitalWrite(6,0);//反之，D6引脚为低电平，水泵关闭
  }
  //控制警示灯和蜂鸣器
  if(b>0){
    digitalWrite(9,1);//当水位低于设定值时，D9引脚为高电平，报警灯和蜂鸣器开启
  }
  else{//反之，D9引脚为低电平，报警灯和蜂鸣器关闭
    digitalWrite(9,0);
  }
}  
