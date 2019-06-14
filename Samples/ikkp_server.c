#include <server_fx.h>
#include <signal.h>

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int listen_d;

void handle_shutdown(int sig)
{
	if (listen_d)
		close(listen_d);
	fprintf(stderr, "\nBye\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	if (catch_signal(SIGINT, handle_shutdown) == -1)
	{
		error("Can't set the interrupt handler");
	}
	int port = 30000;

	char *reply[] = {
		"Knock! Knock!\r\n",
		"Oscar\r\n",
		"Oscar silly question, you get a silly answer\r\n"};

	int listener_d = open_listener_socket();
	if (listener_d == -1)
		error("Can't open socket");

	// Bind
	bind_to_port(listener_d, port);

	// Listen
	if (listen(listener_d, 10) == -1)
		error("Can't listen");
	puts("Waiting for connection");

	char buf[255];

	while (1)
	{
		// Accept
		struct sockaddr_storage client_addr;
		unsigned int address_size = sizeof(client_addr);
		int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

		if (say(connect_d, reply[0]) != -1)
		{
			read_in(connect_d, buf, sizeof(buf));
		}

		if (strncmp("Who's there?", buf, 12)){
			// printf("%d\n",strncmp("Who's there?", buf, 12));
			say(connect_d, "You should say \"Who's there?\"\r\n");
		}
		else
		{
			say(connect_d, reply[1]);
			read_in(connect_d, buf, sizeof(buf));
			if (strncmp("Oscar who?", buf, 10))
				say(connect_d, "You should say \"Oscar who?\"\r\n");
			else
			{
				say(connect_d, reply[2]);
			}
		}
		close(connect_d);
	}

	return 0;
}