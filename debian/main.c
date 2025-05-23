// includes
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/***********************/

int main(int argc, char **argv) 
{
    const char* net_file = "/etc/network/interfaces";

    if(geteuid() != 0)
    {
	    printf("The ntconnect cannot be run without escalated privileges.\nPlease use sudo to do it!\n");
	    return 1;
    }
            
    if(check_args(argc, argv, "-h") == 1 || check_args(argc, argv, "--help") == 1)
    {
            help();
            return 0;
    }

    if(argc == 2 && (check_args(argc, argv, "-H") == 1 || check_args(argc, argv, "--history") == 1))
    {
        check_history();
        return 0;
    }

    if(argc == 2 && (check_args(argc, argv, "-l") == 1 || check_args(argc, argv, "--list") == 1))
    {
	    get_networks();
	    return 0;
    }

    if(argc == 7)
    {
        if(check_args(argc, argv, "-m"))
        {
            if((check_args(argc, argv, "-s") != 1 || check_args(argc, argv, "-w") != 1) && check_args(argc, argv, "-p") == 1)
            {
                help();
            }
            else
            {
                write_file_portal(argc, argv, net_file);
            }
        }
        else if(check_args(argc, argv, "-p") != 1 || check_args(argc, argv, "-s") != 1 || check_args(argc, argv, "-w") != 1)
        {
            help();
        }
        else
        {
            write_file(argc, argv, net_file);
        }
    }
    else
    {
        help();
    }

return 0;
}
