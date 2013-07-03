#include <syslog.h>
#define mPrintf(debug, format, args...) syslog(LOG_NOTICE, format, ##args) ; if (debug) printf(format, ##args)



int main(){
	setlogmask (LOG_UPTO (LOG_NOTICE));
	
	openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "Program started by User %d", getuid ());
	mPrintf(1, "B tree falls in a forest\n");
	mPrintf(0, "A tree falls in a forest\n");
	//syslog (LOG_INFO, "A tree falls in a forest");
	closelog ();
}
