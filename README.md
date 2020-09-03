# DTMF generátor tónů #

Vaším úkolem je vytvořit program, který uživateli vygeneruje WAV soubor s libovolným množstvím DTMF tónů, které uživatel zadá z klávesnice. 
Každý symbol se generuje jako krátké písknutí, ve kterém se mísí dva tóny (vlny sinus) , nižší a vyšší (Frekvence ke každému symbolu viz obrázek).

![dtmf_keypad](doc/dtmf.png)

Číslice 2 by teda byla kombinací dvou tónů 697 Hz a 1336 Hz.

Jednotlivé tóny se počítají podle vzorce **sin(2 * π * f * i/8000 Hz)**, kde i jsou čísla od 0 do 8000 [Hz] (8000 Hz používáme, jelikož je to vzorkovací frekvence pro telefony), tyto hodnoty 
pak dále násobíme proměnnou 'VOLUME', která je definována v hlavičkovém souboru 'dtmf.h', aby výsledný soubor byl lépe slyšitelný. 'f' je zde frekvence dle zadaného symbolu.

Tento výsledný tón uložte do vektoru z úlohy č.6 (Pole vektoru je nutno předělat na datový typ 'short' z uint64_t ve struktůře a funkcích). 

Ukázkový výsledný soubor můžete najít ve složce 'test_files' pod názvem 'sound.wav' nebo po kliknutí [ZDE](test_files/sound.wav).

# DTMF tone generator #

Your rask is to create a program that generates WAV file with any amount of DTMF tones from stdin. Symbols are generated as a short 'beep', in which there are mixed two tones (sine waves) with
short and high frequency (Frequencies to each symbols are listed in picture below).

![dtmf_keypad](doc/dtmf.png)

The symbol '2' would be the mixture of tones with frequency of 697 Hz and 1336 Hz.

Each tone is generated like this **sin(2 * π * f * i/8000 Hz)**, where i is a number 0 to 8000 [Hz] (8000 because sampling rate of telephone is 8000 Hz),
those values are multipled by variable 'VOLUME', which is defined in header file 'dtmf.h', so the output file has higher volume. 'f' is frequency of symbol.

Final values are stored in vector from task 6 (Change the vector array to 'short' instead of uint64_t in struct and functions).

Example of output file is located in 'test_files/sound.wav' or [HERE](test_files/sound.wav).

## Ukázkový běh programu / Example of program ##
```
0 - Vector Create
1 - Input chars
2 - Write to file
M - Menu
E - Exit
0
Vector created successfully!
1
Please enter a symbol (1-9) or A,B,C,D,*,#, space means there is a pause between sounds, anything else to exit.
1
2
3
e
Symbols added to the vector!
2
WAV file created successfully!
e
Ending the program!
```