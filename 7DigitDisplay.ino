int numbersArray[10][12] = {/*0*/1,1,0,1,1,0,1,1,0,0,0,0,
                       /*1*/1,1,0,0,0,0,0,0,0,0,0,0,
                       /*2*/1,0,0,1,1,1,0,1,0,0,0,0,
                       /*3*/1,1,0,1,0,1,0,1,0,0,0,0,
                       /*4*/1,1,0,0,0,1,1,0,0,0,0,0,
                       /*5*/0,1,0,1,0,1,1,1,0,0,0,0,
                       /*6*/0,1,0,1,1,1,1,1,0,0,0,0,
                       /*7*/1,1,0,0,0,0,1,1,0,0,0,0,
                       /*8*/1,1,0,1,1,1,1,1,0,0,0,0,
                       /*9*/1,1,0,1,0,1,1,1,0,0,0,0};

int digitArray[4][12] = {/*D1*/0,0,0,0,0,0,0,0,1,1,1,0,
                         /*D2*/0,0,0,0,0,0,0,0,1,1,0,1,
                         /*D3*/0,0,0,0,0,0,0,0,1,0,1,1,
                         /*D4*/0,0,0,0,0,0,0,0,0,1,1,1};


int x = 0;

void displayNumber(int number[12]){
    for(int i = 0; i < 12; i++){
        if(number[i] == 0){
            digitalWrite(i+2, LOW);
        }
        else{
            digitalWrite(i+2, HIGH);
        }
    }
}


void setNumber(int value, int digit){
  int number[12] = {0};
  
  for(int j = 0; j < 12; j++){
    number[j] = numbersArray[value][j];
  }

  switch(digit){
    case 1:
      for(int i = 0; i < 12; i++){
        if(digitArray[0][i] == 1){
          number[i] = digitArray[0][i];
        }
      }
      displayNumber(number);
      break;
    case 2:
      for(int i = 0; i < 12; i++){
        if(digitArray[1][i] == 1){
          number[i] = digitArray[1][i];
        }
      }
      displayNumber(number);
      break;
    case 3:
      for(int i = 0; i < 12; i++){
        if(digitArray[2][i] == 1){
          number[i] = digitArray[2][i];
          //number[2] = 1;
        }
      }
      displayNumber(number);
      break;
    case 4:
      for(int i = 0; i < 12; i++){
        if(digitArray[3][i] == 1){
          number[i] = digitArray[3][i];
        }
      }
      displayNumber(number);
      break;
  }


}

void setup(){
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
    
   pinMode(A5, INPUT);
    Serial.begin(9600);
   
}
int y = 1;

void showNumber(int x){
    int y = 0;
    int z;
    int w;
    
    if(x <= 9){
        y+=1;
        setNumber(x, 1);
    }
    
    else if(x > 9 && x <= 99){
        setNumber(x/10, 2);
        delay(5);
        setNumber(x - (x / 10 * 10) , 1);
        delay(5);
    }
    
    
    else if(x > 99 && x <= 999){
        z = x - (x / 100 * 100);
        setNumber(x/100, 3);
        delay(5);
        setNumber((x - (x / 100 * 100)) / 10, 2);
        delay(5);
        setNumber(z - (z / 10 * 10) , 1);
        delay(5);
    }
    else if(x > 999 && x <= 9999){
        z = x - (x /1000 * 1000);
        .w = z - (z /100 * 100);
        delay(5);
        setNumber(x/1000, 4);
        delay(5);
        setNumber(z/100, 3);
        delay(5);
        setNumber(w/10, 2);
        delay(5);
        setNumber(w -(w / 10 * 10), 1);
        
    }
    
}

int ldr = 0;
void loop(){
   
    showNumber(x);
    
    if(analogRead(A5) == 0){
        x+=1;
        
    }
   
    

    
    
    
}