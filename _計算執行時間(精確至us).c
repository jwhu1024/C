struct timeval start, end;
gettimeofday( &start, NULL );
sleep(3);
gettimeofday( &end, NULL );
int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
printf("time: %d us\n", timeuse);