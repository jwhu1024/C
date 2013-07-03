#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t got_usr1;
void sigusr1_handler(int sig);
void led_sync_signal(void);
void led_set_signal(void);

// wait for object
void led_sync_signal(void)
{
	struct sigaction sa;

    got_usr1 = 0;

    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return;
    }

    while (!got_usr1) {
        printf("PID %d: working hard...\n", getpid());
        sleep(1);
    }

    printf("Done in by SIGUSR1!\n");

    return;
}

// set event
void led_set_signal(void)
{
	// Send signal - kill -USR1 5023
	sprintf(szkill, "kill -USR1 %d", getpid());
	printf("szkill -> %s\n", szkill);
	system(szkill);
    return;
}

void sigusr1_handler(int sig)
{
    got_usr1 = 1;
}
