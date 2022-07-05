#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


int main(void) {
	
	time_t t, t2, t3, t4;
	struct tm *local_t, *gm_t, str_tm;

	struct timespec tsp_set, tsp_get;
	struct timeval tv;

	char local_t_buf[32], gm_t_buf[64];


	t = time(NULL);
	local_t = localtime(&t);
	gm_t = gmtime(&t);
	
	
	if (strftime(local_t_buf, 32, "t local %Y-%m-%d %H:%M:%S", local_t) == 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", local_t_buf);
	
	
	if (strftime(gm_t_buf, 64, "time & date: %r, %a %b %d, %Y", gm_t) == 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", gm_t_buf);
/*
	tsp_set.tv_sec = 1000000000LL;
	tsp_set.tv_nsec = 0;
	clock_getres(CLOCK_REALTIME, &tsp_set);
*/	
	tsp_set.tv_sec = 1657001069LL;
	tsp_set.tv_nsec = 0;
	clock_settime(CLOCK_REALTIME, &tsp_set);

	
	if (clock_gettime(CLOCK_REALTIME, &tsp_get) == -1)
		printf("clock gettime error\n");
	else {
		
		t2 = tsp_get.tv_sec;		
		gm_t = gmtime(&t2);
		strftime(gm_t_buf, 64, "t2 gm: %Y-%m-%d %H:%M:%S", gm_t);	
		printf("%s\n", gm_t_buf);

		gettimeofday(&tv, NULL);
		t3 = tv.tv_sec;
		gm_t = gmtime(&t3);
		strftime(gm_t_buf, 64, "t3 gm: %Y-%m-%d %H:%M:%S", gm_t);	
		printf("%s\n", gm_t_buf);

	}

	if (strptime("2022-07-05 14:19:04", "%Y-%m-%d %H:%M:%S", &str_tm) == NULL)
		printf("strptime error\n");

	else {
	
		if ((t4 = mktime(&str_tm)) == -1)
			printf("mktime error");
		else
			printf("t4: %ld\n", (long int) t4);
	}


	exit(0);
}
