int Value;
char Buffer[12];
String Data="";
int delimiter = (int) '\n';
void setup() 
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

void loop() 
{
  while(!Serial.available())
  {
    delay(200);  
  }
  while(Serial.available())
  {
    int num = Serial.read();
    Serial.println("Hello World");
    if (num == delimiter)
    {
      break;
    }
    else
    {
      Data += (char) num;
    }
  }
  int Length = Data.length() + 1;
  Data.toCharArray(Buffer, Length);
  Data = "";
  int Value = atoi(Buffer);
  for(int Power=6;Power>=0;Power--)
  {
    if(Value>=(pow(2,Power)))
    {
      Value-=pow(2,Power);
      digitalWrite(Power+6,HIGH);
    }
    else
    {
      digitalWrite(Power+6,LOW);
    }
  }
}
