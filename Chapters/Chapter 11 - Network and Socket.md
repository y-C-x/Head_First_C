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

### Port Reuse

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

### `recv` - Read from clients

```c
<bytes read> = recv(<descriptor>, <buffer>, <bytes to read>, 0);
```

---
IMPORTANT

* string does not end with `\0`
* when users type in telnet, string ends with `\r\n`
* `recv()` returns char's number read, -1 if error, 0 if the client shuts the connection.
* `recv()` cannot receive all chars in one call, which means *you might have to call `recv()` multiple times*

---

for example
`Who'` `s t` `here?\r\n`

#### read_in fx

```c
int read_in(int socket, char *buf, int len)
{
  char *s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);
  while ((c > 0) && (s[c - 1] != '\n'))
  {
    s += c;
    slen -= c;
    c = recv(socket, s, slen, 0);
  }

  if (c < 0)
    return c;
  else if (c == 0)
    buf[0] = '\0';  // read nothing
  else
    s[c - 1] = '\0';  // replace \r with \0 // should be c-2 here
  return len - slen;
}
```

#### ikkp_server.c

`read_in()` and `strcasecmp()` have problems here.

Notice that `strcasecmp()` only compares the specific length of chars in buff with
the given std answer, which makes it possible to return true wile comparing "AB" and "ABxxxxx"
while the no. of chars to be compared is 2.

### Use `fork()`

#### ikkp_server_3.c

close `connect` socket in parent process;  
close `listerner` socket in child process;

```c
while(1) {
  int connect_d = accept(...);

  if(!fork()){ // in child
    close(listener_d);
    ...
    close(connect_d); // close when communication is finished
    exit(0); // exit the child process
  }

  close(connect_d);
}
```

### network client

have to be done in US... (update later)
