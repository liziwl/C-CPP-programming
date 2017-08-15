all: forking_beeper zombie fork_exec fork_daemon

forking_beeper: forking_beeper.c
	gcc -o forking_beeper forking_beeper.c

zombie: zombie.c
	gcc -o zombie zombie.c

fork_exec: fork_exec.c peekaboo
	gcc -o fork_exec fork_exec.c

peekaboo: peekaboo.c
	gcc -o peekaboo peekaboo.c

fork_daemon: fork_daemon.c peekaboo_daemon
	gcc -o fork_daemon fork_daemon.c

peekaboo_daemon: peekaboo_daemon.c
	gcc -o peekaboo_daemon peekaboo_daemon.c

clean:
	rm forking_beeper
	rm zombie
	rm fork_exec
	rm peekaboo
	rm fork_daemon
	rm peekaboo_daemon
