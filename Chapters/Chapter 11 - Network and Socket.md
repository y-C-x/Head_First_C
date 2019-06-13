# Chapter 11 - Network and Socket

## Knock-Knock Server

require `telnet` package

```c
> telnet 127.0.0.1 30000
```

IP - internet protocol

### BLAB

B - Bind
L - Listen
A - Accept
B - Begin

#### Bind

ports - associated with differnet service

`Bind` requires two things:
`socket descriptor` and `socket name`

Socket

```c
#include <sys/socket.h>
...
int listener_d = socket(PF_INET, SOCK_STREAM, 0);
if (listener_d == -1)
  error("Can't open socket");
```

Socket Name

```c
#include <arpa/inet.h>
...
struct sockaddr_in name;
name.sin_family = PF_INET;
name.sin_port = (in_port_t)htons(30000);
name.sin_addr.s_addr = htonl(INADDR_ANY);
```

Bind

```c
int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));

if(c == -1)
  error("Can't bind to port 30000");
```

#### Listen

Set the maximum waiting length of listen() quene.

```c
if (listen(listener_d, 10) == -1)
  error("Can't listen");
```

in this case the 11th client will be told "the server is too busy to respond"

#### Accept

return the second `socket descriptor`

```c
struct sockaddr_storage client_addr;
unsigned int address_size = sizeof(client_addr);

int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
```

#### Begin - `send`

socket is a two-way stream.

Use `\r\n` for CR.

```c
char *msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n>";
if (send(connect_d, msg, strlen(msg), 0) == -1)
  error("send");
```

Note  
Port range : 0 - 65535
Choose port no. higher than 1024 to be safe.

#### Port Reuse

**IMPORTANT**  
There's delay in binding port.
Once you bind sockets to a port, OS will allow no program to bind it again, including the previous binded one.

In this case, you should use

```c
int reuse = 1;
if(Setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
  error("Cant set the \"reuse port\" opt");
```

---
