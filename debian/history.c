// includes
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/************************/

void check_history()
{
    char* HOME_FOLDER = getenv("HOME");
    char* HISTORY_FOLDER = strcat(HOME_FOLDER, "/.local/share/ntconnect");
    char* HISTORY_FILE = strcat(HISTORY_FOLDER, "/history.txt");
    FILE *hist_file;
    char line[100];

    // Open file in read mode
    hist_file = fopen(HISTORY_FILE, "r");

    // Read file
    while(fgets(line, 100, hist_file))
    {
        printf("%s", line);
    }
}

void write_history(char* ssid, char* password, char* wireless_card, bool portal)
{
    char* HOME_FOLDER = getenv("HOME");
    char* HISTORY_FOLDER = strcat(HOME_FOLDER, "/.local/share/ntconnect");
    char* HISTORY_FILE = strcat(HISTORY_FOLDER, "/history.txt");
    FILE *hist_file;
    char ssid_final[100] = "SSID: ";
    char password_final[100] = "PASSKEY: ";
    char wireless_card_final[100] = "NETWORK CARD: ";
    
    strcat(ssid_final, ssid);
    if(portal)
    {
        strcat(password_final, "AUTH PORTAL");
    }
    else
    {
        strcat(password_final, password);
    }
    strcat(wireless_card_final, wireless_card);

    hist_file = fopen(HISTORY_FILE, "a"); // Open file in append mode
    fprintf(hist_file, "\n%s", ssid_final);
    fprintf(hist_file, "%s", password_final);
    fprintf(hist_file, "%s\n", wireless_card_final);
    fprintf(hist_file, "\n#######################"); // Write new text to the end of file
    fclose(hist_file); // Close file
}
