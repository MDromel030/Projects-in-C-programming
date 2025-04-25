#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void fill_date(char *);
void fill_time(char *, int);
int input_format();
void run_stopwatch();
void run__clock();
void clear_screen();

int main()
{
    char time[50], date[100];
    int format = input_format();
    while (1)
    {
        fill_time(time, format);
        fill_date(date);
        clear_screen();
        printf("\nLive: %s\n", time);
        printf("\nDate %s", date);
        printf("\nRun Stopwatch!!Press ctrl+c and restart to select stopwatch mode\n");
        sleep(1);
    }

    return 0;
}
/*void clear_screen()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}*/

void clear_screen()
{
#ifdef _WIN32

    system("cls");
#else
    system("clear");

#endif
}

int input_format()
{
    int format;
    int choice;
    printf("Select among these feature:\n");
    printf("1.Clock\n");
    printf("2. stopwatch\n");
    printf("Choose to select:");
    scanf("%d", &choice);
    if (choice == 2)
    {
        run_stopwatch();
        exit(0);
    }

    else if (choice == 1)
    {
        printf("\n choose a time format: ");
        printf("\n1. 24 hour Format.");
        printf("\n2. 12 hour Format.");
        printf("\nmake a choice: ");
        scanf("%d", &format);
        return format;
    }
}

void fill_date(char *buffer)
{
    time_t realtime;
    struct tm *current_time;
    // char buffer[100];//

    time(&realtime);
    current_time = localtime(&realtime);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void fill_time(char *buffer, int format)
{
    time_t realtime;
    struct tm *current_time;
    // char buffer[100];//

    time(&realtime);
    current_time = localtime(&realtime);
    if (format == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else if (format == 2)
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // cppreference.com
    }
}

void run_stopwatch()
{
    int sec = 0, mnt = 0, hours = 0;

    printf("\n--- Stopwatch ---\n");
    printf("Press Ctrl+C to stop the stopwatch.\n");
    sleep(1);

    while (1)
    {
        clear_screen();
        printf("\nStopwatch: %02d:%02d:%02d\n", hours, mnt, sec);
        sleep(1);
        sec++;

        if (sec == 60)
        {
            sec = 0;
            mnt++;
        }
        if (mnt == 60)
        {
            mnt = 0;
            hours++;
        }
    }
}
