#ifndef LOWERCASE_TO_UPPERCASE_H
#define LOWERCASE_TO_UPPERCASE_H

int calculate_string_lenght(char* world){
    bool flag = true;
    int i=0;
    while(flag==true){
        if(world[i] != 0){
            i++;
        }else{
            flag=false;
        }
    }return i;
}

char* convert_lowercase_to_uppercase(char* world){
    int world_lenght = calculate_string_lenght(world) + 1;
    char* transformed_world = new char[world_lenght];
    int letter;

    for(int i=0; world[i] != '\0'; i++){
        letter = world[i];
        if (letter >= 65 && letter <= 90){
            transformed_world[i] = letter;
        } else if (letter >= 97 && letter <= 122){
            transformed_world[i] = letter - 32;
        } else {
            transformed_world[i] = letter;
        }
    }

    transformed_world[world_lenght] = '\0';

    return transformed_world;
}

#endif // LOWERCASE_TO_UPPERCASE_H
