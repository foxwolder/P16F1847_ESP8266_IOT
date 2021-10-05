
sbit DHT11_Pin at PORTB.B3;
sbit DHT11_DIR at TRISB.B3;
extern unsigned int DHT11_HUM;
extern char DHT11_CHKSM;
char New_Flag = 0;
char New_Flag2 = 0;
char New_Flag3=5;
unsigned char ddata[40];
unsigned char ddata2[40];
unsigned char ddata3[40];
char *res;
unsigned char *ssid;
 unsigned char Rx_buff;
unsigned char *password;
     char kadar,cc=0;
     char kadar2=0;
     char kadar3=0;
     int check1=0;
     int check2=0;
     int stat=0;
     int wait=0;
     char tespit=0;
     char clear=0;
long veri;
char derece[7];
char nem[7];
unsigned char out[7];
int uz=0;
int reset=0,statet=0;
 int pp,ppp=0;
 unsigned timeOut2 = 0;
const double Rl      = 1030.0;
const double Vadc_33 = 0.0032226562;
double Vrl;
double Rs;
double ppm;
double ratio;
int x_flag=0;
  double lgPPM;
unsigned int gas_value;
char text[7];
   char* codetxt_to_ramtxt(const char* ctxt){
static char txtt[100];
char i;
  for(i =0; txtt[i] = ctxt[i]; i++);
  return txtt;
}

    void kes(){

                                           UART1_write_Text(codetxt_to_ramtxt("AT+CWMODE=1\r\n"));

    }
        void dns_check()
      {

              New_Flag2=1;
    UART1_write_Text(codetxt_to_ramtxt(" AT+PING=\"8.8.8.8\"\r\n"));
         delay_ms(1000);
      }
      void bekleme()
      {

            while (timeOut2 < 2000){

                 delay_ms(1);
                timeOut2++;



            }
            timeOut2=0;

      }



       char daat;
       int iii= 0;
        void interrupt()

        {

         unsigned timeOut = 0;
          if(RCSTA&0x06)
                  {
                      CREN_bit=0;
                      daat=RCREG;

                       CREN_bit=1;

                  }
                else

             {

       if (PIR1.RCIF) {
         while (timeOut < 50000){
              if (Uart1_Data_Ready()){
              Rx_buff=Uart1_Read();
          ddata[kadar]=Rx_buff;
             kadar++;
       if (kadar>=40) {kadar=0; }
                 iii++;
              }
              timeOut++;
              }
                   timeOut = 0;
                       kadar=0;
                  New_Flag = 1;




     }
          }


         }
        void chk()
        {

                if(stat==1)

       {
       new_flag3=0;


                  gas_value = ADC_Read(0);


            delay_ms(500);



   if(DHT11_CHKSM==((DHT11_TMP>>8)+(DHT11_HUM>>8)+(DHT11_TMP&0xff)+(DHT11_HUM&0xff)))
   {



                                 inttostr(DHT11_TMP>>8,derece);

                                   inttostr(DHT11_HUM>>8,nem);


        }

          delay_ms(500);
        if(strlen(derece)>0 && strlen(nem)>0)
        {
       Vrl = (double)gas_value * Vadc_33;
  Rs = Rl * (5 - Vrl)/Vrl;
  ratio = Rs/Rl;
  lgPPM = (log10(ratio) * -2.6)+ 2.7;
  ppm = pow(10,lgPPM);
              longtostr(ppm,text);



           PORTB.F4=1;
           delay_ms(10);
             PORTB.F4=0;

             UART1_write_Text(codetxt_to_ramtxt("ATE0\r\n"));
                  Delay_ms(100);
    UART1_write_Text(codetxt_to_ramtxt("AT+CIPMUX=1\r\n"));
                      delay_ms(300);
            UART1_write_Text(codetxt_to_ramtxt("\AT+CIPSTART=0,\""));
               UART1_write_Text(codetxt_to_ramtxt("TCP"));
               UART1_write_Text(codetxt_to_ramtxt("\",\""));
               UART1_write_Text(codetxt_to_ramtxt("destination.host.me"));
               UART1_write_Text(codetxt_to_ramtxt("\",80\r\n"));

                   PORTB.F4=1;
                    delay_ms(10);
                    PORTB.F4=0;

       uz= strlen( codetxt_to_ramtxt("POST /index.php?apikey=c4cd2912-099e-44ee-bba9-e1a176587654&value1="));
                     uz=uz+strlen(ltrim(rtrim(derece)));
                      uz=uz+strlen(codetxt_to_ramtxt("&value2="));
                      uz=uz+strlen(ltrim(rtrim(nem)));
                        uz=uz+strlen(codetxt_to_ramtxt("&value3="));
                         uz=uz+strlen(codetxt_to_ramtxt(text));
                         uz=uz+ strlen(codetxt_to_ramtxt("&sensor=30 HTTP/1.1\r\n"));
                         uz =uz+ strlen(codetxt_to_ramtxt("Host:destination.host.me"));
                          uz=uz+4;
                           inttostr(uz,out);
                           delay_ms(300);

                         UART1_Write_Text (codetxt_to_ramtxt("AT+CIPSEND=0,"));
                          UART1_Write_Text (ltrim(rtrim(out)));
                            UART1_Write_Text(codetxt_to_ramtxt("\r\n")) ;

                                     delay_ms(100);
                                        PORTB.F4=1;
                    delay_ms(10);
                    PORTB.F4=0;
                          UART1_Write_Text (codetxt_to_ramtxt("POST /index.php?apikey=c4cd2912-099e-44ee-bba9-e1a176587654&value1="));

 UART1_Write_Text (ltrim(rtrim(derece)));

 UART1_Write_Text (codetxt_to_ramtxt("&value2="));

 UART1_Write_Text (ltrim(rtrim(nem)));

 UART1_Write_Text (codetxt_to_ramtxt("&value3="));

 UART1_Write_Text (ltrim(rtrim(text)));

UART1_Write_Text(codetxt_to_ramtxt("&sensor=30 HTTP/1.1\r\n"));

UART1_Write_Text(codetxt_to_ramtxt("Host:destination.host.me")) ;
UART1_Write_Text(codetxt_to_ramtxt("\r\n")) ;
UART1_Write_Text(codetxt_to_ramtxt("\r\n")) ;
                Delay_Ms(500);

                                  UART1_Write_Text(codetxt_to_ramtxt("AT+CIPCLOSE=5\r\n")) ;

           PORTB.F4=1;
                    delay_ms(10);
                    PORTB.F4=0;
                       bekleme();
                         memset(derece,0,7);
                         memset(nem,0,7);
                       }

  }


        }


      void main()
{
OSCCON=0x78;

  INTCON.PEIE = 1;
    INTCON.GIE = 1;
     PIE1.RCIE=1;
     PIR1.RCIF=0;

  CM1CON0=0;
  CM1CON1=0;
  CM2CON0=0;
  CM2CON1=0;

          APFCON0.RXDTSEL=1;
        APFCON1.TXCKSEL=1;
     ANSELB = 0;
           ANSELA = 0b00000001;
          ADCON0= 0b00000001;
       TRISB.B2 = 1;
 TRISA0_bit = 1;
 TRISA.F0=1;
 TRISB.F4=0;
  PORTB.F4=0;
TRISA.F1 = 1;
PORTA.F1=0;


delay_us(5);
 DHT11_init();
       delay_ms(100);
  UART1_Init(114286);

      Delay_ms(100);
     memset(ddata,0,strlen(ddata));
     clear=Uart1_Read();

       ADC_Init_Advanced(_ADC_INTERNAL_VREFH);

            Delay_ms(500);
    UART1_write_Text(codetxt_to_ramtxt("AT+CIPMUX=1\r\n"));




           Delay_ms(100);
             UART1_write_Text(codetxt_to_ramtxt("ATE0\r\n"));
        while(1){

         if(wait==1)
         {

                           PORTB.F4=1;

                   }





         if(stat==1)
         {
        Dht11_Start();
        DHT11_Read();
          }
               if(reset==1)
               {

                UART1_write_Text(codetxt_to_ramtxt("AT+CWQAP\r\n"));
            delay_ms(300);
         UART1_write_Text(codetxt_to_ramtxt("AT+CWMODE=2\r\n"));
          delay_ms(300);
    UART1_write_Text(codetxt_to_ramtxt("AT+CIPMODE=0\r\n"));
     delay_ms(300);
    UART1_write_Text(codetxt_to_ramtxt("AT+CIPMUX=1\r\n"));
     delay_ms(800);
    UART1_write_Text(codetxt_to_ramtxt("AT+CWSAP=\"Gas_cutter\",\""));
    UART1_write_Text(codetxt_to_ramtxt("password"));
    UART1_write_Text(codetxt_to_ramtxt("\",11,4\r\n"));
               delay_ms(800);
           UART1_write_Text(codetxt_to_ramtxt("AT+CIPAP=\"172.28.10.1\"\r\n"));
       delay_ms(300);
        UART1_write_Text(codetxt_to_ramtxt("AT+CIPSERVER=1,333\r\n"));
               delay_ms(300);
                   wait=1;
                  reset=0;

                     memset(ddata,0,strlen(ddata));
                    clear=Uart1_Read();

                   do{
                        PORTB.F4=1;
                    delay_ms(50);
                    PORTB.F4=0;
                    delay_ms(50);
                      pp++;
                   }while(pp<15);






               }
                pp=0;




  if(New_Flag){

                                  do  {

                                        if(new_flag2==1)
                                        {


                                               if(ddata[tespit]=='O'&& ddata[tespit+1]=='K')
                                               {
                                               stat=1;
                                               New_Flag2=0;
                                                New_Flag3=0;
                                      }

                                       }




                                       if(stat==0)
                                       {

                                      if(ddata[tespit]=='|')
                                      {
                                                   kadar2=tespit;
                                             do
                                             {

                                                   ddata2[cc] =ddata[kadar2+1];
                                                     kadar2++;
                                                    cc++;
                                             } while(cc<=strlen(ddata));
                                             cc=0;

                                               clear=Uart1_Read();

                                               ssid=ddata2;

                                                      kadar2=0;
                                                       check1=1;

                                      }
                                          else if(ddata[tespit]=='$')
                                      {



                                                             kadar3=tespit;
 do
                                             {

                                                      ddata3[cc] =ddata[kadar3+1];
                                                     kadar3++;
                                                     cc++;
                                             } while(cc<=strlen(ddata));
                                             cc=0;
                                                     memset(ddata,0,strlen(ddata));
                                                       clear=Uart1_Read();
                                                 password=ddata3;

                                                      kadar3=0;
                                                       check2=1;
 }                                    if(ddata[tespit]=='F'&& ddata[tespit+1]=='A')
                                      {


                                               clear=Uart1_Read();
                  if(stat==0)
                   {
                   do{
                        PORTB.F4=1;
                    delay_ms(800);
                    PORTB.F4=0;
                    delay_ms(800);
                      pp++;
                   }while(pp<3);
                   pp=0;
                   }
                                      }

                                         if(ddata[tespit]=='G')
                                      {

                                                kes();

                                               wait=0;
                                               x_flag=0;
                                               stat=1;
                                              New_Flag3=0;


                   do{
                        PORTB.F4=0;
                    delay_ms(200);
                    PORTB.F4=1;
                    delay_ms(200);
                      pp++;
                   }while(pp<8);
                   pp=0;



                                      }

                                      }
                                     if(stat==1)
                                     {
                                       if((ddata[tespit]=='b'&&ddata[tespit+1]=='u'&&ddata[tespit+2]=='s')||(ddata[tespit]=='E'&&ddata[tespit+1]=='R'&&ddata[tespit+2]=='R'))
                                      {

                            x_flag++;
                  if(x_flag==5)
                    {
                  do{
                   do{
                        PORTB.F4=0;
                    delay_ms(100);
                    PORTB.F4=1;
                    delay_ms(100);
                      pp++;
                   }while(pp<2);
                   pp=0;

                   delay_ms(500);
                    PORTB.F4=1;
                      delay_ms(50);
                       PORTB.F4=0;
                       ppp++;
                    }while(ppp<10);
                    ppp=0;
                     stat=0;
                               x_flag=0;
                       UART1_write_Text(codetxt_to_ramtxt("AT+RST\r\n"));
                         }



                         }



                                    }












                tespit++;
       }  while(tespit<=40);


            tespit=0;













     if((check1==1)&&(check2==1))
      {


                     PIR1.RCIF=0;
              UART1_write_Text(codetxt_to_ramtxt("AT+CWMODE=3\r\n"));
              delay_ms(2000);
               UART1_write_Text(codetxt_to_ramtxt("\AT+CWJAP=\""));
               UART1_write_Text(rtrim(ltrim(ddata2)));
               UART1_write_Text(codetxt_to_ramtxt("\",\""));
               UART1_write_Text(rtrim(ltrim(ddata3)));
               UART1_write_Text(codetxt_to_ramtxt("\"\r\n"));
                     delay_ms(100);
                    PIR1.RCIF=1;
                       delay_ms(100);

                       check1=0;
                       check2=0;
         memset(ssid,0,strlen(ddata2));
         memset(password,0,strlen(ddata3));


                            }

        New_Flag = 0;
          memset(ddata,0,strlen(ddata));
   }


         chk();


                 if(PORTA.F1 == 1)
    {

       if(PORTA.F1 == 1)
       {


        UART1_write_Text(codetxt_to_ramtxt("AT+RST\r\n"));
              reset = 1;
              stat=0;
              New_Flag3 = 1;


       }
    }


                     if( New_Flag3!=1)     {
                    dns_check();

}





             gas_value=0;








    }
































 }