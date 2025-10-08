const int buttonPin= 2;   // 按鈕腳位
const int RledPin = 3;    // R 腳位
const int GledPin = 4;    // G 腳位
const int BledPin = 5;    // B 腳位

int buttonState = 0;
int lastButtonState = 0;    // 🆕 新增：記錄上一個按鈕狀態
int ledcolor = 0;

bool ButtonPressed = false;
String currentcolor = "led";

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.print("Current Color: ");
  Serial.println(buttonState);

  // ✅ 按下的「瞬間」才切換顏色（這是關鍵）
  if (buttonState == LOW & !ButtonPressed) {
    ledcolor++;
    if (ledcolor > 8) ledcolor = 0;
    ButtonPressed = true;
  } // 🆕 記得更新上一個狀態
  if(buttonState == HIGH & ButtonPressed)
  {
    ButtonPressed = false;
  }

  // 顏色控制區
  if (ledcolor == 0){
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) { // RED
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 2) { // Green
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 3){ // Blue
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if(ledcolor == 4){ // Yellow
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 5){ // Purple
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6){ // Cyan
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if(ledcolor == 7){ // 全暗
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if(ledcolor == 8){
    ledcolor = 0; // 顏色循環
  }
}
