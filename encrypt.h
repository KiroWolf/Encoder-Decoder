#pragma once

char* immutableCaesarEncoder(char* text, int offset);

void mutableCaesarEncoder(char* text, int offset);

char* immutableCaesarDecoder(char* text, int offset);

void mutableCaesarDecoder(char* text, int offset);

char* immutableXorCoder(char* text, char* key);

void mutableXorCoder(char* text, char* key);