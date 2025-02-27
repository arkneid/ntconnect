// includes
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void get_networks()
{
	FILE *fp;
	char path[1035];

	// Execute the iwlist command to scan the WiFi networks
	fp = popen("iwlist wlp0s20f3 scan | grep 'ESSID'", "r");
	if(fp == NULL)
	{
		printf("Failed to check the WiFi networks.\n");
		exit(1);
	}

	printf("Available WiFi networks:\n");
	// Read and print the output line by line
	while(fgets(path, sizeof(path), fp) != NULL)
	{
		// Print SSID (ESSID)
		printf("%s", path);
	}

	// Close read process
	pclose(fp);
}
