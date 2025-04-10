String transformed_word;
char input_word[50]; // no es necesario 'new' en Arduino

void setup() {
  Serial.begin(9600);
  Serial.println("Please type a word to convert in UpperCase: ");
}

void loop() {
  if (Serial.available() > 0) {
    String user_entry = Serial.readStringUntil('\n');
    int len = user_entry.length();
    if (len >= 50) len = 49;

    for (int i = 0; i < len; i++) {
      input_word[i] = user_entry[i];
    }
    input_word[len] = '\0';

    char* transformed = convert_lowercase_to_uppercase(input_word);

    Serial.print("Converted to UpperCase: ");
    Serial.println(transformed);

    delete[] transformed; // Liberar memoria asignada dinámicamente

    Serial.println("Please type another word to convert in UpperCase: ");
  }
}

// Corrección de ortografía en el nombre de la función
int calculate_string_length(char* word) {
  int i = 0;
  while (word[i] != '\0') {
    i++;
  }
  return i;
}

char* convert_lowercase_to_uppercase(char* word) {
  int word_length = calculate_string_length(word) + 1;
  char* transformed_word = new char[word_length];
  int letter;

  for (int i = 0; word[i] != '\0'; i++) {
    letter = word[i];
    if (letter >= 'A' && letter <= 'Z') {
      transformed_word[i] = letter;
    } else if (letter >= 'a' && letter <= 'z') {
      transformed_word[i] = letter - 32;
    } else {
      transformed_word[i] = letter;
    }
  }

  transformed_word[word_length - 1] = '\0'; // Corrección de índice

  return transformed_word;
}