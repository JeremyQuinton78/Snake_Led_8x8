unsigned char i;

#define Max7219_pinCLK 10
#define Max7219_pinCS 9
#define Max7219_pinDIN 8

int teteX = 3;
int teteY = 6;
char way = 'r' ;
int Matrix[8][8] ;
int SnakeX[64] ;
int SnakeY[64] ;
int taille = 1 ;
int sumBinar ;
char unsignedVar ;
int fruitX = 6 ;
int fruitY = 2 ;
int varLoop = 0 ;

void setup() {
  pinMode(Max7219_pinCLK, OUTPUT);
  pinMode(Max7219_pinCS, OUTPUT);
  pinMode(Max7219_pinDIN, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH) ;
  delay(50);  //Initialiser
  Init_MAX7219();
  Serial.begin(9600);
  randomSeed(analogRead(5));
  for (int i = 0 ; i < 64; i++) {
    SnakeX[i] = 0 ;
    SnakeY[i] = 0 ;
  }

}

void loop() {
  
  int joystickX = analogRead(A1);
  int joystickY = analogRead(A0);
  joystickX = map(joystickX, 0, 1023, -1, 2);
  joystickY = map(joystickY, 0, 1023, -1, 2);
  


  if ((joystickX == -1) && (way != 'r')) {  way = 'l' ; }
  if ((joystickX == 1) && (way != 'l')) {  way = 'r' ; }
  if ((joystickY == 1) && (way != 'b')) {  way = 't' ; }
  if ((joystickY == -1) && (way != 't')) {  way = 'b' ; }

  switch (way) {
    case 'l': teteX = teteX - 1 ; break;
    case 'r': teteX = teteX + 1 ; break;
    case 't': teteY = teteY + 1 ; break;
    case 'b': teteY = teteY - 1 ; break;
  }
  
  if (teteX < 1) { teteX = 8 ; }
  if (teteX > 8) { teteX = 1 ; }
  if (teteY < 1) { teteY = 8 ; }
  if (teteY > 8) { teteY = 1 ; }

  
  if (Matrix[teteX-1][teteY-1] == 1) {
    if ((teteX == fruitX) && (teteY == fruitY)) {
      taille ++ ;
      boolean verifFruit = false ;
      while (verifFruit == false ) {
        verifFruit = true ;
        fruitX = random(1,8) ;
        fruitY = random(1,8) ;
        for (int i = 0 ; i < 8; i++){
            for (int j = 0 ; j < 8; j++){
              if (Matrix[fruitX-1][fruitY-1] == 1) { verifFruit = false ; }
            }  
        }
      }
    }
    else { 
      taille = 1 ;
      delay(2000) ;
    }
  }
  

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Matrix[i][j] = 0 ;
    }
  }

  for (int j = 0; j <= 8; j++) { Write_Max7219(j, 0x00) ; }
  
  Matrix[teteX-1][teteY-1] = 1 ;
  
  for (int i = 0; i <= taille; i++) { Matrix[SnakeX[i]-1][SnakeY[i]-1] = 1 ; }
  
  Matrix[fruitX-1][fruitY-1] = 1 ; 
  
 
  for(int i = 0 ; i < 8; i++){
    sumBinar = 0 ;
    if (Matrix[i][0] == 1) { sumBinar = sumBinar + 128 ; }
    if (Matrix[i][1] == 1) { sumBinar = sumBinar + 64 ; }
    if (Matrix[i][2] == 1) { sumBinar = sumBinar + 32 ; }
    if (Matrix[i][3] == 1) { sumBinar = sumBinar + 16 ; }
    if (Matrix[i][4] == 1) { sumBinar = sumBinar + 8 ; }
    if (Matrix[i][5] == 1) { sumBinar = sumBinar + 4 ; }
    if (Matrix[i][6] == 1) { sumBinar = sumBinar + 2 ; }
    if (Matrix[i][7] == 1) { sumBinar = sumBinar + 1 ; }    
    if (sumBinar == 0) { unsignedVar = 0x00 ; }
    if (sumBinar == 1) { unsignedVar = 0x01 ; }
    if (sumBinar == 2) { unsignedVar = 0x02 ; }
    if (sumBinar == 3) { unsignedVar = 0x03 ; }
    if (sumBinar == 4) { unsignedVar = 0x04 ; }
    if (sumBinar == 5) { unsignedVar = 0x05 ; }
    if (sumBinar == 6) { unsignedVar = 0x06 ; }
    if (sumBinar == 7) { unsignedVar = 0x07 ; }
    if (sumBinar == 8) { unsignedVar = 0x08 ; }
    if (sumBinar == 9) { unsignedVar = 0x09 ; }
    if (sumBinar == 10) { unsignedVar = 0x0a ; }
    if (sumBinar == 11) { unsignedVar = 0x0b ; }
    if (sumBinar == 12) { unsignedVar = 0x0c ; }
    if (sumBinar == 13) { unsignedVar = 0x0d ; }
    if (sumBinar == 14) { unsignedVar = 0x0e ; }
    if (sumBinar == 15) { unsignedVar = 0x0f ; }
    if (sumBinar == 16) { unsignedVar = 0x10 ; }
    if (sumBinar == 17) { unsignedVar = 0x11 ; }
    if (sumBinar == 18) { unsignedVar = 0x12 ; }
    if (sumBinar == 19) { unsignedVar = 0x13 ; }
    if (sumBinar == 20) { unsignedVar = 0x14 ; }
    if (sumBinar == 21) { unsignedVar = 0x15 ; }
    if (sumBinar == 22) { unsignedVar = 0x16 ; }
    if (sumBinar == 23) { unsignedVar = 0x17 ; }
    if (sumBinar == 24) { unsignedVar = 0x18 ; }
    if (sumBinar == 25) { unsignedVar = 0x19 ; }
    if (sumBinar == 26) { unsignedVar = 0x1a ; }
    if (sumBinar == 27) { unsignedVar = 0x1b ; }
    if (sumBinar == 28) { unsignedVar = 0x1c ; }
    if (sumBinar == 29) { unsignedVar = 0x1d ; }
    if (sumBinar == 30) { unsignedVar = 0x1e ; }
    if (sumBinar == 31) { unsignedVar = 0x1f ; }
    if (sumBinar == 32) { unsignedVar = 0x20 ; }
    if (sumBinar == 33) { unsignedVar = 0x21 ; }
    if (sumBinar == 34) { unsignedVar = 0x22 ; }
    if (sumBinar == 35) { unsignedVar = 0x23 ; }
    if (sumBinar == 36) { unsignedVar = 0x24 ; }
    if (sumBinar == 37) { unsignedVar = 0x25 ; }
    if (sumBinar == 38) { unsignedVar = 0x26 ; }
    if (sumBinar == 39) { unsignedVar = 0x27 ; }
    if (sumBinar == 40) { unsignedVar = 0x28 ; }
    if (sumBinar == 41) { unsignedVar = 0x29 ; }
    if (sumBinar == 42) { unsignedVar = 0x2a ; }
    if (sumBinar == 43) { unsignedVar = 0x2b ; }
    if (sumBinar == 44) { unsignedVar = 0x2c ; }
    if (sumBinar == 45) { unsignedVar = 0x2d ; }
    if (sumBinar == 46) { unsignedVar = 0x2e ; }
    if (sumBinar == 47) { unsignedVar = 0x2f ; }
    if (sumBinar == 48) { unsignedVar = 0x30 ; }
    if (sumBinar == 49) { unsignedVar = 0x31 ; }
    if (sumBinar == 50) { unsignedVar = 0x32 ; }
    if (sumBinar == 51) { unsignedVar = 0x33 ; }
    if (sumBinar == 52) { unsignedVar = 0x34 ; }
    if (sumBinar == 53) { unsignedVar = 0x35 ; }
    if (sumBinar == 54) { unsignedVar = 0x36 ; }
    if (sumBinar == 55) { unsignedVar = 0x37 ; }
    if (sumBinar == 56) { unsignedVar = 0x38 ; }
    if (sumBinar == 57) { unsignedVar = 0x39 ; }
    if (sumBinar == 58) { unsignedVar = 0x3a ; }
    if (sumBinar == 59) { unsignedVar = 0x3b ; }
    if (sumBinar == 60) { unsignedVar = 0x3c ; }
    if (sumBinar == 61) { unsignedVar = 0x3d ; }
    if (sumBinar == 62) { unsignedVar = 0x3e ; }
    if (sumBinar == 63) { unsignedVar = 0x3f ; }
    if (sumBinar == 64) { unsignedVar = 0x40 ; }
    if (sumBinar == 65) { unsignedVar = 0x41 ; }
    if (sumBinar == 66) { unsignedVar = 0x42 ; }
    if (sumBinar == 67) { unsignedVar = 0x43 ; }
    if (sumBinar == 68) { unsignedVar = 0x44 ; }
    if (sumBinar == 69) { unsignedVar = 0x45 ; }
    if (sumBinar == 70) { unsignedVar = 0x46 ; }
    if (sumBinar == 71) { unsignedVar = 0x47 ; }
    if (sumBinar == 72) { unsignedVar = 0x48 ; }
    if (sumBinar == 73) { unsignedVar = 0x49 ; }
    if (sumBinar == 74) { unsignedVar = 0x4a ; }
    if (sumBinar == 75) { unsignedVar = 0x4b ; }
    if (sumBinar == 76) { unsignedVar = 0x4c ; }
    if (sumBinar == 77) { unsignedVar = 0x4d ; }
    if (sumBinar == 78) { unsignedVar = 0x4e ; }
    if (sumBinar == 79) { unsignedVar = 0x4f ; }
    if (sumBinar == 80) { unsignedVar = 0x50 ; }
    if (sumBinar == 81) { unsignedVar = 0x51 ; }
    if (sumBinar == 82) { unsignedVar = 0x52 ; }
    if (sumBinar == 83) { unsignedVar = 0x53 ; }
    if (sumBinar == 84) { unsignedVar = 0x54 ; }
    if (sumBinar == 85) { unsignedVar = 0x55 ; }
    if (sumBinar == 86) { unsignedVar = 0x56 ; }
    if (sumBinar == 87) { unsignedVar = 0x57 ; }
    if (sumBinar == 88) { unsignedVar = 0x58 ; }
    if (sumBinar == 89) { unsignedVar = 0x59 ; }
    if (sumBinar == 90) { unsignedVar = 0x5a ; }
    if (sumBinar == 91) { unsignedVar = 0x5b ; }
    if (sumBinar == 92) { unsignedVar = 0x5c ; }
    if (sumBinar == 93) { unsignedVar = 0x5d ; }
    if (sumBinar == 94) { unsignedVar = 0x5e ; }
    if (sumBinar == 95) { unsignedVar = 0x5f ; }
    if (sumBinar == 96) { unsignedVar = 0x60 ; }
    if (sumBinar == 97) { unsignedVar = 0x61 ; }
    if (sumBinar == 98) { unsignedVar = 0x62 ; }
    if (sumBinar == 99) { unsignedVar = 0x63 ; }
    if (sumBinar == 100) { unsignedVar = 0x64 ; }
    if (sumBinar == 101) { unsignedVar = 0x65 ; }
    if (sumBinar == 102) { unsignedVar = 0x66 ; }
    if (sumBinar == 103) { unsignedVar = 0x67 ; }
    if (sumBinar == 104) { unsignedVar = 0x68 ; }
    if (sumBinar == 105) { unsignedVar = 0x69 ; }
    if (sumBinar == 106) { unsignedVar = 0x6a ; }
    if (sumBinar == 107) { unsignedVar = 0x6b ; }
    if (sumBinar == 108) { unsignedVar = 0x6c ; }
    if (sumBinar == 109) { unsignedVar = 0x6d ; }
    if (sumBinar == 110) { unsignedVar = 0x6e ; }
    if (sumBinar == 111) { unsignedVar = 0x6f ; }
    if (sumBinar == 112) { unsignedVar = 0x70 ; }
    if (sumBinar == 113) { unsignedVar = 0x71 ; }
    if (sumBinar == 114) { unsignedVar = 0x72 ; }
    if (sumBinar == 115) { unsignedVar = 0x73 ; }
    if (sumBinar == 116) { unsignedVar = 0x74 ; }
    if (sumBinar == 117) { unsignedVar = 0x75 ; }
    if (sumBinar == 118) { unsignedVar = 0x76 ; }
    if (sumBinar == 119) { unsignedVar = 0x77 ; }
    if (sumBinar == 120) { unsignedVar = 0x78 ; }
    if (sumBinar == 121) { unsignedVar = 0x79 ; }
    if (sumBinar == 122) { unsignedVar = 0x7a ; }
    if (sumBinar == 123) { unsignedVar = 0x7b ; }
    if (sumBinar == 124) { unsignedVar = 0x7c ; }
    if (sumBinar == 125) { unsignedVar = 0x7d ; }
    if (sumBinar == 126) { unsignedVar = 0x7e ; }
    if (sumBinar == 127) { unsignedVar = 0x7f ; }
    if (sumBinar == 128) { unsignedVar = 0x80 ; }
    if (sumBinar == 129) { unsignedVar = 0x81 ; }
    if (sumBinar == 130) { unsignedVar = 0x82 ; }
    if (sumBinar == 131) { unsignedVar = 0x83 ; }
    if (sumBinar == 132) { unsignedVar = 0x84 ; }
    if (sumBinar == 133) { unsignedVar = 0x85 ; }
    if (sumBinar == 134) { unsignedVar = 0x86 ; }
    if (sumBinar == 135) { unsignedVar = 0x87 ; }
    if (sumBinar == 136) { unsignedVar = 0x88 ; }
    if (sumBinar == 137) { unsignedVar = 0x89 ; }
    if (sumBinar == 138) { unsignedVar = 0x8a ; }
    if (sumBinar == 139) { unsignedVar = 0x8b ; }
    if (sumBinar == 140) { unsignedVar = 0x8c ; }
    if (sumBinar == 141) { unsignedVar = 0x8d ; }
    if (sumBinar == 142) { unsignedVar = 0x8e ; }
    if (sumBinar == 143) { unsignedVar = 0x8f ; }
    if (sumBinar == 144) { unsignedVar = 0x90 ; }
    if (sumBinar == 145) { unsignedVar = 0x91 ; }
    if (sumBinar == 146) { unsignedVar = 0x92 ; }
    if (sumBinar == 147) { unsignedVar = 0x93 ; }
    if (sumBinar == 148) { unsignedVar = 0x94 ; }
    if (sumBinar == 149) { unsignedVar = 0x95 ; }
    if (sumBinar == 150) { unsignedVar = 0x96 ; }
    if (sumBinar == 151) { unsignedVar = 0x97 ; }
    if (sumBinar == 152) { unsignedVar = 0x98 ; }
    if (sumBinar == 153) { unsignedVar = 0x99 ; }
    if (sumBinar == 154) { unsignedVar = 0x9a ; }
    if (sumBinar == 155) { unsignedVar = 0x9b ; }
    if (sumBinar == 156) { unsignedVar = 0x9c ; }
    if (sumBinar == 157) { unsignedVar = 0x9d ; }
    if (sumBinar == 158) { unsignedVar = 0x9e ; }
    if (sumBinar == 159) { unsignedVar = 0x9f ; }
    if (sumBinar == 160) { unsignedVar = 0xa0 ; }
    if (sumBinar == 161) { unsignedVar = 0xa1 ; }
    if (sumBinar == 162) { unsignedVar = 0xa2 ; }
    if (sumBinar == 163) { unsignedVar = 0xa3 ; }
    if (sumBinar == 164) { unsignedVar = 0xa4 ; }
    if (sumBinar == 165) { unsignedVar = 0xa5 ; }
    if (sumBinar == 166) { unsignedVar = 0xa6 ; }
    if (sumBinar == 167) { unsignedVar = 0xa7 ; }
    if (sumBinar == 168) { unsignedVar = 0xa8 ; }
    if (sumBinar == 169) { unsignedVar = 0xa9 ; }
    if (sumBinar == 170) { unsignedVar = 0xaa ; }
    if (sumBinar == 171) { unsignedVar = 0xab ; }
    if (sumBinar == 172) { unsignedVar = 0xac ; }
    if (sumBinar == 173) { unsignedVar = 0xad ; }
    if (sumBinar == 174) { unsignedVar = 0xae ; }
    if (sumBinar == 175) { unsignedVar = 0xaf ; }
    if (sumBinar == 176) { unsignedVar = 0xb0 ; }
    if (sumBinar == 177) { unsignedVar = 0xb1 ; }
    if (sumBinar == 178) { unsignedVar = 0xb2 ; }
    if (sumBinar == 179) { unsignedVar = 0xb3 ; }
    if (sumBinar == 180) { unsignedVar = 0xb4 ; }
    if (sumBinar == 181) { unsignedVar = 0xb5 ; }
    if (sumBinar == 182) { unsignedVar = 0xb6 ; }
    if (sumBinar == 183) { unsignedVar = 0xb7 ; }
    if (sumBinar == 184) { unsignedVar = 0xb8 ; }
    if (sumBinar == 185) { unsignedVar = 0xb9 ; }
    if (sumBinar == 186) { unsignedVar = 0xba ; }
    if (sumBinar == 187) { unsignedVar = 0xbb ; }
    if (sumBinar == 188) { unsignedVar = 0xbc ; }
    if (sumBinar == 189) { unsignedVar = 0xbd ; }
    if (sumBinar == 190) { unsignedVar = 0xbe ; }
    if (sumBinar == 191) { unsignedVar = 0xbf ; }
    if (sumBinar == 192) { unsignedVar = 0xc0 ; }
    if (sumBinar == 193) { unsignedVar = 0xc1 ; }
    if (sumBinar == 194) { unsignedVar = 0xc2 ; }
    if (sumBinar == 195) { unsignedVar = 0xc3 ; }
    if (sumBinar == 196) { unsignedVar = 0xc4 ; }
    if (sumBinar == 197) { unsignedVar = 0xc5 ; }
    if (sumBinar == 198) { unsignedVar = 0xc6 ; }
    if (sumBinar == 199) { unsignedVar = 0xc7 ; }
    if (sumBinar == 200) { unsignedVar = 0xc8 ; }
    if (sumBinar == 201) { unsignedVar = 0xc9 ; }
    if (sumBinar == 202) { unsignedVar = 0xca ; }
    if (sumBinar == 203) { unsignedVar = 0xcb ; }
    if (sumBinar == 204) { unsignedVar = 0xcc ; }
    if (sumBinar == 205) { unsignedVar = 0xcd ; }
    if (sumBinar == 206) { unsignedVar = 0xce ; }
    if (sumBinar == 207) { unsignedVar = 0xcf ; }
    if (sumBinar == 208) { unsignedVar = 0xd0 ; }
    if (sumBinar == 209) { unsignedVar = 0xd1 ; }
    if (sumBinar == 210) { unsignedVar = 0xd2 ; }
    if (sumBinar == 211) { unsignedVar = 0xd3 ; }
    if (sumBinar == 212) { unsignedVar = 0xd4 ; }
    if (sumBinar == 213) { unsignedVar = 0xd5 ; }
    if (sumBinar == 214) { unsignedVar = 0xd6 ; }
    if (sumBinar == 215) { unsignedVar = 0xd7 ; }
    if (sumBinar == 216) { unsignedVar = 0xd8 ; }
    if (sumBinar == 217) { unsignedVar = 0xd9 ; }
    if (sumBinar == 218) { unsignedVar = 0xda ; }
    if (sumBinar == 219) { unsignedVar = 0xdb ; }
    if (sumBinar == 220) { unsignedVar = 0xdc ; }
    if (sumBinar == 221) { unsignedVar = 0xdd ; }
    if (sumBinar == 222) { unsignedVar = 0xde ; }
    if (sumBinar == 223) { unsignedVar = 0xdf ; }
    if (sumBinar == 224) { unsignedVar = 0xe0 ; }
    if (sumBinar == 225) { unsignedVar = 0xe1 ; }
    if (sumBinar == 226) { unsignedVar = 0xe2 ; }
    if (sumBinar == 227) { unsignedVar = 0xe3 ; }
    if (sumBinar == 228) { unsignedVar = 0xe4 ; }
    if (sumBinar == 229) { unsignedVar = 0xe5 ; }
    if (sumBinar == 230) { unsignedVar = 0xe6 ; }
    if (sumBinar == 231) { unsignedVar = 0xe7 ; }
    if (sumBinar == 232) { unsignedVar = 0xe8 ; }
    if (sumBinar == 233) { unsignedVar = 0xe9 ; }
    if (sumBinar == 234) { unsignedVar = 0xea ; }
    if (sumBinar == 235) { unsignedVar = 0xeb ; }
    if (sumBinar == 236) { unsignedVar = 0xec ; }
    if (sumBinar == 237) { unsignedVar = 0xed ; }
    if (sumBinar == 238) { unsignedVar = 0xee ; }
    if (sumBinar == 239) { unsignedVar = 0xef ; }
    if (sumBinar == 240) { unsignedVar = 0xf0 ; }
    if (sumBinar == 241) { unsignedVar = 0xf1 ; }
    if (sumBinar == 242) { unsignedVar = 0xf2 ; }
    if (sumBinar == 243) { unsignedVar = 0xf3 ; }
    if (sumBinar == 244) { unsignedVar = 0xf4 ; }
    if (sumBinar == 245) { unsignedVar = 0xf5 ; }
    if (sumBinar == 246) { unsignedVar = 0xf6 ; }
    if (sumBinar == 247) { unsignedVar = 0xf7 ; }
    if (sumBinar == 248) { unsignedVar = 0xf8 ; }
    if (sumBinar == 249) { unsignedVar = 0xf9 ; }
    if (sumBinar == 250) { unsignedVar = 0xfa ; }
    if (sumBinar == 251) { unsignedVar = 0xfb ; }
    if (sumBinar == 252) { unsignedVar = 0xfc ; }
    if (sumBinar == 253) { unsignedVar = 0xfd ; }
    if (sumBinar == 254) { unsignedVar = 0xfe ; }
    if (sumBinar == 255) { unsignedVar = 0xff ; }
    Write_Max7219(i+1,unsignedVar);  
  }

  SnakeX[0] = teteX ;
  SnakeY[0] = teteY ;
  for (int i = taille; i >= 0; i = i - 1) {
    SnakeX[i+1] = SnakeX[i] ;
    SnakeY[i+1] = SnakeY[i] ;    
  }
  
  varLoop++ ;
  delay(250) ;
}


void Init_MAX7219(void)
{
  Write_Max7219(0x09, 0x00);       //decoding ：BCD
  Write_Max7219(0x0a, 0x03);       //brightness
  Write_Max7219(0x0b, 0x07);       //scanlimit；8 LEDs
  Write_Max7219(0x0c, 0x01);       //power-down mode：0，normal mode：1
  Write_Max7219(0x0f, 0x00);       //test display：1；EOT，display：0
}

void Write_Max7219(unsigned char address, unsigned char dat)
{
  digitalWrite(Max7219_pinCS, LOW);
  Write_Max7219_byte(address);           //address，code of LED
  Write_Max7219_byte(dat);               //data，figure on LED
  digitalWrite(Max7219_pinCS, HIGH);
}

void Write_Max7219_byte(unsigned char DATA)
{
  unsigned char i;
  digitalWrite(Max7219_pinCS, LOW);
  for (i = 8; i >= 1; i--)
  {
    digitalWrite(Max7219_pinCLK, LOW);
    digitalWrite(Max7219_pinDIN, DATA & 0x80); // Extracting a bit data
    DATA = DATA << 1;
    digitalWrite(Max7219_pinCLK, HIGH);
  }
}
