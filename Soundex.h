#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Function to get Soundex code for a given character
char getSoundexCode(char c) {
    static const char *codes = "01230120022455012623010202";
    return isalpha(c) ? codes[toupper(c) - 'A'] : '0';
}

// Function to initialize the Soundex string with the first character
void initializeSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
}

// Function to append the Soundex code to the Soundex string if valid
void appendSoundexCode(char *soundex, int *sIndex, char code) {
    if (*sIndex < 4) {
        soundex[*sIndex] = code;
        (*sIndex)++;
        soundex[*sIndex] = '\0';
    }
}

// Function to fill the remaining positions of the Soundex string with '0'
void fillSoundex(char *soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

// Function to process the name and append appropriate Soundex codes
void processName(const char *name, char *soundex, int *sIndex) {
    char prevCode = getSoundexCode(name[0]);
    for (int i = 1; name[i] != '\0' && *sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            appendSoundexCode(soundex, sIndex, code);
            prevCode = code;
        }
    }
}

// Main function to generate the Soundex string
void generateSoundex(const char *name, char *soundex) {
    if (!name || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    initializeSoundex(name, soundex);
    int sIndex = 1;
    processName(name, soundex, &sIndex);
    fillSoundex(soundex, sIndex);
}

#endif // SOUNDEX_H
