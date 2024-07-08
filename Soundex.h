#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char *codes = "01230120022455012623010202";
    return isalpha(c) ? codes[toupper(c) - 'A'] : '0';
}

void initializeSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
}

void appendSoundexCode(char *soundex, int *sIndex, char code) {
    if (*sIndex < 4) {
        soundex[*sIndex] = code;
        (*sIndex)++;
        soundex[*sIndex] = '\0';
    }
}

void fillSoundex(char *soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    if (!name || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    initializeSoundex(name, soundex);

    int sIndex = 1;
    char prevCode = getSoundexCode(name[0]);

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            appendSoundexCode(soundex, &sIndex, code);
            prevCode = code;
        }
    }

    fillSoundex(soundex, sIndex);
}

#endif // SOUNDEX_H
