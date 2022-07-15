ts_sys_sigset: ts_sigset_t
		gcc -o ts_sigset_t ts_sigset_t.c -D USAGE_SYS_SIGSET

ts_demo_sigset: ts_sigset_t
		gcc -o ts_sigset_t ts_sigset_t.c signal_set.c -D


test_sleep2: ts_sleep2
	gcc ts_sleep2.c ../00_lib/libprsigprocmask.so -o ts_sleep2

test_sleep5: ts_sleep5
	gcc ts_sleep5.c ../00_lib/libprsigprocmask.so -o ts_sleep5

clean:
	rm -rf ts_sigset_t ts_sleep2 ts_sigset_t ts_sleep5
