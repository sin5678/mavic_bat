
/*
   电压:4.16-4.22V涓流补充:100%
  电压:4.15v  剩余容量:99%
  电压:4.14v  剩余容量:97%
  电压:4.12v  剩余容量:95%
  电压:4.10v  剩余容量:92%
  电压:4.08v  剩余容量:90%
  电压:4.05v  剩余容量:87%
  电压:4.03v  剩余容量:85%
  电压:3.97v  剩余容量:80%
  电压:3.93v  剩余容量:75%
  电压:3.90v  剩余容量:70%
  电压:3.87v   余容量:60%
  电压:3.81v  剩余容量:55%
  电压:3.79v  剩余容量:50%
  电压:3.77v  剩余容量:45%
  电压:3.76v  剩余容量:42%
  电压:3.76V （持久电压点）
  电压:3.76v  剩余容量:40%
  电压:3.74v  剩余容量:35%
  电压:3.73v  剩余容量:30%
  电压:3.72v  剩余容量:25%
  电压:3.71v  剩余容量:20%
  电压:3.71V （持久电压点）
  电压:3.69v  剩余容量:15%
  电压:3.66v  剩余容量:12%
  电压:3.65v  剩余容量:10%
  电压:3.64v  剩余容量:8%
  电压:3.63v  剩余容量:5%
  电压:3.61v  剩余容量:3%
  电压:3.59v  剩余容量:1%
  电压:3.58v  剩余容量:关机 一般手机 MP4等设置在此关机。电池输出电流不足，减小很多。
  电压:3.55v  剩余容量:-2%
  电压:3.50v  剩余容量:-5%有电压但电流减小
  电压:3.42v  剩余容量:-8%
  电压:3.3v  剩余容量:-10%影响容量了
  电压:3.0v  剩余容量:-12%
  电压:2.7v   剩余容量:-13%电池快要报废了，容量大打折扣！！！此剩余容量为正比，不是绝对的，只是最低忍耐点为0，如果小于0，放电为负数，电池可能完全放光没电，那样电池就废了。如放到负数-5%—-8%，基本到了极限了，放到最低电压:3.2—2.7v，电池再充电电流很小很慢 影响很大的
*/

double mhA = 0.0f;
double total_mhA = 4000; //电池总共有多少毫安
unsigned long proc_time;
unsigned long proc_last_time;
//上次发送串口数据的时间
unsigned long last_send_time;
double V_5v = 4.377; //板子上5V输出口的电压

uint8_t vol_to_parsent(uint32_t vol)
{
  vol = vol / 3;
  if (vol >= 4150) return 100;
  if (vol >= 4140) return 99;
  if (vol >= 4130) return 98;
  if (vol >= 4140) return 97;
  if (vol >= 4120) return 96;
  if (vol >= 4120) return 95;
  if (vol >= 4120) return 94;
  if (vol >= 4110) return 93;
  if (vol >= 4100) return 92;
  if (vol >= 4090) return 91;
  if (vol >= 4080) return 90;
  if (vol >= 4070) return 89;
  if (vol >= 4060) return 88;
  if (vol >= 4050) return 87;
  if (vol >= 4040) return 86;
  if (vol >= 4030) return 85;
  if (vol >= 4010) return 84;
  if (vol >= 4000) return 83;
  if (vol >= 3990) return 82;
  if (vol >= 3980) return 81;
  if (vol >= 3970) return 80;
  if (vol >= 3960) return 79;
  if (vol >= 3955) return 78;
  if (vol >= 3950) return 77;
  if (vol >= 3940) return 76;
  if (vol >= 3930) return 75;
  if (vol >= 3920) return 74;
  if (vol >= 3915) return 73;
  if (vol >= 3910) return 72;
  if (vol >= 3905) return 71;
  if (vol >= 3900) return 70;
  if (vol >= 3895) return 69;
  if (vol >= 3890) return 68;
  if (vol >= 3885) return 67;
  if (vol >= 3880) return 66;
  if (vol >= 3870) return 65;
  if (vol >= 3865) return 64;
  if (vol >= 3860) return 63;
  if (vol >= 3855) return 62;
  if (vol >= 3850) return 61;
  if (vol >= 3840) return 60;
  if (vol >= 3835) return 59;
  if (vol >= 3830) return 58;
  if (vol >= 3825) return 57;
  if (vol >= 3820) return 56;
  if (vol >= 3810) return 55;
  if (vol >= 3805) return 54;
  if (vol >= 3800) return 53;
  if (vol >= 3795) return 52;
  if (vol >= 3790) return 51;
  if (vol >= 3785) return 50;
  if (vol >= 3782) return 49;
  if (vol >= 3779) return 48;
  if (vol >= 3776) return 47;
  if (vol >= 3773) return 46;
  if (vol >= 3770) return 45;
  if (vol >= 3768) return 44;
  if (vol >= 3766) return 43;
  if (vol >= 3764) return 42;
  if (vol >= 3762) return 41;
  if (vol >= 3760) return 40;
  if (vol >= 3755) return 39;
  if (vol >= 3750) return 38;
  if (vol >= 3746) return 37;
  if (vol >= 3743) return 36;
  if (vol >= 3740) return 35;
  if (vol >= 3738) return 34;
  if (vol >= 3736) return 33;
  if (vol >= 3734) return 32;
  if (vol >= 3732) return 31;
  if (vol >= 3730) return 30;
  if (vol >= 3728) return 29;
  if (vol >= 3726) return 28;
  if (vol >= 3724) return 27;
  if (vol >= 3722) return 26;
  if (vol >= 3720) return 25;
  if (vol >= 3718) return 24;
  if (vol >= 3716) return 23;
  if (vol >= 3714) return 22;
  if (vol >= 3712) return 21;
  if (vol >= 3710) return 20;
  if (vol >= 3705) return 19;
  if (vol >= 3700) return 18;
  if (vol >= 3696) return 17;
  if (vol >= 3693) return 16;
  if (vol >= 3690) return 15;
  if (vol >= 3680) return 14;
  if (vol >= 3670) return 13;
  if (vol >= 3660) return 12;
  if (vol >= 3655) return 11;
  if (vol >= 3650) return 10;
  if (vol >= 3645) return 9;
  if (vol >= 3640) return 8;
  if (vol >= 3636) return 7;
  if (vol >= 3633) return 6;
  if (vol >= 3630) return 5;
  if (vol >= 3620) return 4;
  if (vol >= 3610) return 3;
  if (vol >= 3600) return 2;
  if (vol >= 3590) return 1;
  if (vol <= 3500) return 0;
  return 0;
}

const uint16_t crc_tab16[256] = {
  0x0000, 0x1189, 0x2312, 0x329B, 0x4624, 0x57AD, 0x6536, 0x74BF,
  0x8C48, 0x9DC1, 0xAF5A, 0xBED3, 0xCA6C, 0xDBE5, 0xE97E, 0xF8F7,
  0x1081, 0x0108, 0x3393, 0x221A, 0x56A5, 0x472C, 0x75B7, 0x643E,
  0x9CC9, 0x8D40, 0xBFDB, 0xAE52, 0xDAED, 0xCB64, 0xF9FF, 0xE876,
  0x2102, 0x308B, 0x0210, 0x1399, 0x6726, 0x76AF, 0x4434, 0x55BD,
  0xAD4A, 0xBCC3, 0x8E58, 0x9FD1, 0xEB6E, 0xFAE7, 0xC87C, 0xD9F5,
  0x3183, 0x200A, 0x1291, 0x0318, 0x77A7, 0x662E, 0x54B5, 0x453C,
  0xBDCB, 0xAC42, 0x9ED9, 0x8F50, 0xFBEF, 0xEA66, 0xD8FD, 0xC974,
  0x4204, 0x538D, 0x6116, 0x709F, 0x0420, 0x15A9, 0x2732, 0x36BB,
  0xCE4C, 0xDFC5, 0xED5E, 0xFCD7, 0x8868, 0x99E1, 0xAB7A, 0xBAF3,
  0x5285, 0x430C, 0x7197, 0x601E, 0x14A1, 0x0528, 0x37B3, 0x263A,
  0xDECD, 0xCF44, 0xFDDF, 0xEC56, 0x98E9, 0x8960, 0xBBFB, 0xAA72,
  0x6306, 0x728F, 0x4014, 0x519D, 0x2522, 0x34AB, 0x0630, 0x17B9,
  0xEF4E, 0xFEC7, 0xCC5C, 0xDDD5, 0xA96A, 0xB8E3, 0x8A78, 0x9BF1,
  0x7387, 0x620E, 0x5095, 0x411C, 0x35A3, 0x242A, 0x16B1, 0x0738,
  0xFFCF, 0xEE46, 0xDCDD, 0xCD54, 0xB9EB, 0xA862, 0x9AF9, 0x8B70,
  0x8408, 0x9581, 0xA71A, 0xB693, 0xC22C, 0xD3A5, 0xE13E, 0xF0B7,
  0x0840, 0x19C9, 0x2B52, 0x3ADB, 0x4E64, 0x5FED, 0x6D76, 0x7CFF,
  0x9489, 0x8500, 0xB79B, 0xA612, 0xD2AD, 0xC324, 0xF1BF, 0xE036,
  0x18C1, 0x0948, 0x3BD3, 0x2A5A, 0x5EE5, 0x4F6C, 0x7DF7, 0x6C7E,
  0xA50A, 0xB483, 0x8618, 0x9791, 0xE32E, 0xF2A7, 0xC03C, 0xD1B5,
  0x2942, 0x38CB, 0x0A50, 0x1BD9, 0x6F66, 0x7EEF, 0x4C74, 0x5DFD,
  0xB58B, 0xA402, 0x9699, 0x8710, 0xF3AF, 0xE226, 0xD0BD, 0xC134,
  0x39C3, 0x284A, 0x1AD1, 0x0B58, 0x7FE7, 0x6E6E, 0x5CF5, 0x4D7C,
  0xC60C, 0xD785, 0xE51E, 0xF497, 0x8028, 0x91A1, 0xA33A, 0xB2B3,
  0x4A44, 0x5BCD, 0x6956, 0x78DF, 0x0C60, 0x1DE9, 0x2F72, 0x3EFB,
  0xD68D, 0xC704, 0xF59F, 0xE416, 0x90A9, 0x8120, 0xB3BB, 0xA232,
  0x5AC5, 0x4B4C, 0x79D7, 0x685E, 0x1CE1, 0x0D68, 0x3FF3, 0x2E7A,
  0xE70E, 0xF687, 0xC41C, 0xD595, 0xA12A, 0xB0A3, 0x8238, 0x93B1,
  0x6B46, 0x7ACF, 0x4854, 0x59DD, 0x2D62, 0x3CEB, 0x0E70, 0x1FF9,
  0xF78F, 0xE606, 0xD49D, 0xC514, 0xB1AB, 0xA022, 0x92B9, 0x8330,
  0x7BC7, 0x6A4E, 0x58D5, 0x495C, 0x3DE3, 0x2C6A, 0x1EF1, 0x0F78
};


unsigned short CRC_INIT = 0x3692;

uint16_t crc16_update(uint16_t crc, uint8_t ch)
{
  uint16_t tmp;
  uint16_t msg;

  msg = 0x00ff & (uint16_t)ch;
  tmp = crc ^ msg;
  crc = (crc >> 8) ^ crc_tab16[tmp & 0xff];

  return crc;
}
uint16_t sdk_stream_crc16_calc(const uint8_t *pMsg, size_t nLen)
{
  size_t i;
  uint16_t wCRC = CRC_INIT;

  for (i = 0; i < nLen; i++)
  {
    wCRC = crc16_update(wCRC, pMsg[i]);
  }
  return wCRC;
}

void send_vol(uint32_t vol, uint32_t current)
{
  uint32_t int_mhA = mhA;
  uint32_t int_total_mhA = total_mhA;
  current = current / 100;
  uint8_t pkt[] = {0x55, 0x2C, 0x04, 0x36, 0x0B, 0x09, 0x25, 0x1B, 0x00, 0x0D, 0x02, 0x00, 0x0c, 0x30, 0x00, 0x00, 0xF0, 0xFA, 0xFF, 0xFF, 0x0A, 0x1A, 0x00, 0x00, 0x0A, 0x1A, 0x00, 0x00, 0xc8, 0x01, 0x03, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01};
  uint8_t send_pkt[sizeof(pkt) + 2];
  memcpy(&pkt[12], &vol, 4);
  memcpy(&pkt[20], &int_total_mhA, 4);
  memcpy(&pkt[24], &int_mhA, 4);
  memcpy(&pkt[28], &current, 2);  //本来显示温度的地方 现在显示电流
  pkt[31] = mhA/total_mhA * 100; //vol_to_parsent(vol);
  uint16_t csum = sdk_stream_crc16_calc(pkt, sizeof(pkt));
  memcpy(&send_pkt[0], &pkt[0], sizeof(pkt));
  memcpy(&send_pkt[sizeof(pkt)], &csum, 2);

  Serial.write(send_pkt, sizeof(send_pkt));
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);

  last_send_time = 0;
  unsigned long proc_last_time = 0;
  proc_last_time = millis();
  
}

float  get_A()
{
   int Iv = analogRead(A0);
   float I = V_5v * (Iv/1023.0) * 17 * (0.0005 / (0.005/3));
   return I;
}

//获取电压
float get_V()
{
  int sensorValue = analogRead(A1);
  //Serial.println(sensorValue);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (V_5v / 1023.0);
  return voltage * 10.2;
}

// the loop routine runs over and over again forever:
void loop() {
  float a = get_A();
  proc_time = millis();
  mhA += (a * ((proc_time - proc_last_time)) / 3600.0f);
  proc_last_time = proc_time;
  if(proc_time - last_send_time > 1000)
  {
    int V = analogRead(A0);
    //Serial.println(V);
   // double current = V * (V_5v / 1023.0);
   // Serial.println(V_5v * (V/1023.0) * 17 * (0.0005 / (0.005/3)));
    
    //Serial.println(a);
    //Serial.println(mhA);
    //Serial.println(get_V() );
    
    send_vol(get_V() , a);
    last_send_time = proc_time;
  }
  delay(50);
}
