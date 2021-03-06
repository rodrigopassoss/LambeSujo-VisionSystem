#include "../include/serialcomm.h"
#include <fstream>
#include <iostream>
#include <limits>

typedef uint32_t* LPDWORD;

using namespace std;

typedef void* HANDLE;
HANDLE Cport[16];

char comports[16][10]={"\\\\.\\COM1",  "\\\\.\\COM2",  "\\\\.\\COM3",  "\\\\.\\COM4",
                       "\\\\.\\COM5",  "\\\\.\\COM6",  "\\\\.\\COM7",  "\\\\.\\COM8",
                       "\\\\.\\COM9",  "\\\\.\\COM10", "\\\\.\\COM11", "\\\\.\\COM12",
                       "\\\\.\\COM13", "\\\\.\\COM14", "\\\\.\\COM15", "\\\\.\\COM16"};
char mode_str[128];

int  cport_nr = 4, // porta COM5 (idc inicial em 0)
     bdrate = 9600;       // 9600 baud
char mode[]={'8','N','1',0}; // palavra de 8 bits, sem paridade e 1 stop bit

int              fd = 0;     // File descriptor
struct termios   options;    // Terminal options
int              rc;         // Return value


void encerra_comunicacao_serial()
{
    unsigned char str = 255; // byte de sincronização/codificação
    RS232_SendByte(cport_nr, str);
    for(int i=1;i<10;i++) // manda zero para todas as velocidades
        RS232_SendByte(cport_nr, 0);
    RS232_CloseComport(cport_nr); // fecha a porta serial
}

int inicia_comunicacao_serial()
{
    if(RS232_OpenComport(cport_nr, bdrate, mode))
    {
        cout << "porta não existe ou não pode ser aberta." << endl;
        return(0);
    }
    else
    {
        cout << "Comunicacao iniciada corretamente." << endl;
        return(1);
    }
}

void envia_comandos_robo(unsigned char *str)
{
    for(int i=0;i<10;i++)
        RS232_SendByte(cport_nr, str[i]);
}

int RS232_OpenComport(int comport_number, int baudrate, const char *mode)
{
    if((comport_number > 15)||(comport_number < 0))
    {
        printf("illegal comport number\n");
        return(1);
    }

    switch(baudrate)
    {
        case     110 : strcpy(mode_str, "baud=110");
                       break;
        case     300 : strcpy(mode_str, "baud=300");
                       break;
        case     600 : strcpy(mode_str, "baud=600");
                       break;
        case    1200 : strcpy(mode_str, "baud=1200");
                       break;
        case    2400 : strcpy(mode_str, "baud=2400");
                       break;
        case    4800 : strcpy(mode_str, "baud=4800");
                       break;
        case    9600 : strcpy(mode_str, "baud=9600");
                       break;
        case   19200 : strcpy(mode_str, "baud=19200");
                       break;
        case   38400 : strcpy(mode_str, "baud=38400");
                       break;
        case   57600 : strcpy(mode_str, "baud=57600");
                       break;
        case  115200 : strcpy(mode_str, "baud=115200");
                       break;
        case  128000 : strcpy(mode_str, "baud=128000");
                       break;
        case  256000 : strcpy(mode_str, "baud=256000");
                       break;
        case  500000 : strcpy(mode_str, "baud=500000");
                       break;
        case 1000000 : strcpy(mode_str, "baud=1000000");
                       break;
        default      : printf("invalid baudrate\n");
                       return(1);
                       break;
    }

    if(strlen(mode) != 3)
    {
        printf("invalid mode \"%s\"\n", mode);
        return(1);
    }

    switch(mode[0])
    {
        case '8': strcat(mode_str, " data=8");
                  break;
        case '7': strcat(mode_str, " data=7");
                  break;
        case '6': strcat(mode_str, " data=6");
                  break;
        case '5': strcat(mode_str, " data=5");
                  break;
        default : printf("invalid number of data-bits '%c'\n", mode[0]);
                  return(1);
                  break;
    }

    switch(mode[1])
    {
        case 'N':
        case 'n': strcat(mode_str, " parity=n");
                  break;
        case 'E':
        case 'e': strcat(mode_str, " parity=e");
                  break;
        case 'O':
        case 'o': strcat(mode_str, " parity=o");
                  break;
        default : printf("invalid parity '%c'\n", mode[1]);
                  return(1);
                  break;
    }

    switch(mode[2])
    {
        case '1': strcat(mode_str, " stop=1");
                  break;
        case '2': strcat(mode_str, " stop=2");
                  break;
        default : printf("invalid number of stop bits '%c'\n", mode[2]);
                  return(1);
                  break;
    }

    strcat(mode_str, " dtr=on rts=on");

    fd = open(comports[comport_number], O_RDWR| O_NOCTTY);
    if (fd < 0)
    {
        // Error occurred. Examine errno to find the reason.
        printf("unable to open comport\n");
        return(1);
    }
    /*Cport[comport_number] = CreateFileA(comports[comport_number],
                      GENERIC_READ|GENERIC_WRITE,
                      0,                          // no share
                      NULL,                       // no security
                      OPEN_EXISTING,
                      0,                          // no threads
                      NULL);                      // no templates

    if(Cport[comport_number]==INVALID_HANDLE_VALUE)
    {
    printf("unable to open comport\n");
    return(1);
    }*/

    // Get the current options for the port
    if((rc = tcgetattr(fd, &options)) < 0)
    {
       fprintf(stderr, "failed to get attr: %d, %s\n", fd, strerror(errno));
       exit(EXIT_FAILURE);
    }

    // Set the baud rates to 230400
    cfsetispeed(&options, B9600);

    // Set the baud rates to 230400
    cfsetospeed(&options, B9600);

    cfmakeraw(&options);
    options.c_cflag |= (CLOCAL | CREAD);   // Enable the receiver and set local mode
    options.c_cflag &= ~CSTOPB;            // 1 stop bit
    options.c_cflag &= ~CRTSCTS;           // Disable hardware flow control
    options.c_cc[VMIN]  = 1;
    options.c_cc[VTIME] = 2;

    // Set the new attributes
    if((rc = tcsetattr(fd, TCSANOW, &options)) < 0)
    {
       fprintf(stderr, "failed to set attr: %d, %s\n", fd, strerror(errno));
       exit(EXIT_FAILURE);
    }

    /*DCB port_settings;
    memset(&port_settings, 0, sizeof(port_settings));  // clear the new struct
    port_settings.DCBlength = sizeof(port_settings);

    //if(!BuildCommDCBA(mode_str, &port_settings))
    if()
    if(!BuildCommDCBA(mode_str, &port_settings))
    {
        printf("unable to set comport dcb settings\n");
        close(fd);
        //CloseHandle(Cport[comport_number]); - windows
        return(1);
    }

    if(!SetCommState(Cport[comport_number], &port_settings))
    {
        printf("unable to set comport cfg settings\n");
        close(fd);
        //CloseHandle(Cport[comport_number]); - windows
        return(1);
    }*/

    /*COMMTIMEOUTS Cptimeouts;

    //Cptimeouts.ReadIntervalTimeout         = MAXDWORD; - windows
    Cptimeouts.ReadIntervalTimeout         = numeric_limits<long>::max();
    Cptimeouts.ReadTotalTimeoutMultiplier  = 0;
    Cptimeouts.ReadTotalTimeoutConstant    = 0;
    Cptimeouts.WriteTotalTimeoutMultiplier = 0;
    Cptimeouts.WriteTotalTimeoutConstant   = 0;

    if(!SetCommTimeouts(Cport[comport_number], &Cptimeouts))
    {
        printf("unable to set comport time-out settings\n");
        close(fd);
        //CloseHandle(Cport[comport_number]); - windows
        return(1);
    }*/

    return(0);
}

int RS232_SendByte(int comport_number, unsigned char byte)
{
    int n;

    //WriteFile(Cport[comport_number], &byte, 1, (LPDWORD)((void *)&n), NULL); - windows
    write(fd,&byte,*(LPDWORD)((void *)&n));

    if(n < 0)
        return(1);

    return(0);
}

int RS232_SendBuf(int comport_number, unsigned char *buf, int size)
{
    int n;
    //if(WriteFile(Cport[comport_number], buf, size, (LPDWORD)((void *)&n), NULL)) - windows
    if(write(fd,buf,size))
        return(n);

    return(-1);
}

void RS232_CloseComport(int comport_number)
{
    close(fd);
    //close(Cport[comport_number]); - windows
    //CloseHandle(Cport[comport_number]); - windows
}
