struct MorseChar {
    char ch;
    const char* code;
};

const MorseChar morseTable[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},

    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
};

const int lampPin = LED_BUILTIN;
const int soundPin = 9;
const int frequency = 432;

const unsigned long unit = 200; // milliseconds
const unsigned long DOT_DURATION = unit;
const unsigned long DASH_DURATION = 3 * unit;
const unsigned long SYMBOL_GAP = unit;
const unsigned long LETTER_GAP = 3 * unit;
const unsigned long WORD_GAP = 7 * unit;

// Lookup
const char* getMorse(char c) {
    if (c >= 'a' && c <= 'z'){
      c = c - 'a' + 'A';
    }

    for (const auto& m : morseTable) {
        if (m.ch == c){
          return m.code;
        }
    }
    return nullptr; // not found
}

void doMorse(char c) {
  const char* code = getMorse(c);

  if (code == nullptr) {
    Serial.print("Unsupported character: ");
    Serial.println(c);
    return;
  }
  
  for (int i = 0; code[i] != '\0'; i++) {
    unsigned long duration;
    
    if (code[i] == '.') {
      duration = DOT_DURATION;     // Dot: 200 ms ON
    } else {
      duration = DASH_DURATION;   // Dash: 600 ms ON
    }
    
    digitalWrite(lampPin, HIGH);
    tone(soundPin, frequency);
    
    delay(duration);
    
    digitalWrite(lampPin, LOW);
    noTone(soundPin);
      
    if (code[i + 1] != '\0') { // if it isn't '\0', which is the end of a string
      delay(SYMBOL_GAP); // Add delay between the morse codes 
    }
  }
}

void setup() {
    pinMode(lampPin, OUTPUT);
  	pinMode(soundPin, OUTPUT);
    digitalWrite(lampPin, LOW);

    Serial.begin(9600); // This initializes serial communication at 9600 baud so your computer and Arduino can exchange text through the Serial Monitor.
    Serial.println("Enter text for morse:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    input.toUpperCase();

    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      
      if (c == ' ') {
        
        // Only add a word gap if the previous character
        // was not also a space
        if (i > 0 && input.charAt(i - 1) != ' ') {
          delay(WORD_GAP - LETTER_GAP);
        }
        continue;
      }
      
      Serial.println(c);
      doMorse(c);
      
      // Add letter gap only if the next character
      // isn't a space
      
      if (i + 1 < input.length() && input.charAt(i + 1) != ' ') {
        delay(LETTER_GAP);
      }
    }
	
    digitalWrite(lampPin, LOW);
    noTone(soundPin);
    Serial.println("Finished!\n");
  }
}
