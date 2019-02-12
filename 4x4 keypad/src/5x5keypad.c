#include<4x4keypad.h>

void keypad_init()
{
  char i;
   for(i=0;i<(sizeof(key_column)/sizeof(char))&& (key_column[i]);i++)   

         {pinMode(key_column[i],INPUT); Serial.print("initialized column :");Serial.println(i+1);}
        Serial.println("finished initializing columns!!!");         
   for(i=0;i<(sizeof(key_row)/sizeof(char)) && (key_row[i]);i++)
         {pinMode(key_row[i],OUTPUT);Serial.print("initialized row :");Serial.println(i+1);}
        Serial.println("finished initializing rows!!!");

}


char getkey()
{  
    char buttons[][4]=
     {{'A','B','#','*'},
      {'1','2','3','^'},
      {'4','5','6','!'},
      {'7','8','9',0x1B} 
     };
   char i,j,key=0;
   for(i=0;i<sizeof(key_row) && key_row[i] && key_column[i];i++)
      {
         digitalWrite(key_row[i],LOW);
         for(j=0;j<sizeof(key_column);j++)
            {
            if(!digitalRead(key_column[j]))                
               delay(20);
               while(!digitalRead(key_column[i]))
                      key=buttons[i][j];            
             }
           digitalWrite(key_row[i],HIGH);
       }  
  return key;
 }

char must_getkey()
{
  char key=0;
    while(key==0)
      key=getkey();
return key;

}    