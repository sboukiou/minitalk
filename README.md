___
___
# MiniTalk
___
## The purpose of this project is to code a small data exchange program using UNIX signals.

    Create a communication program in the form of a client and a server.
___
## How It would work
    The server will be started and it will print it's own process id
    Then the client shall send a string given as param alongside with the server pid
    to that server

___
___
### Functions to use:
    ◦ write
    ◦ ft_printf (Previous project)
    ◦ signal
    ◦ sigemptyset
    ◦ sigaddset
    ◦ sigaction
    ◦ kill
    ◦ getpid
    ◦ malloc
    ◦ free
    ◦ pause
    ◦ sleep
    ◦ usleep
    ◦ exit

___
### Signals to be used
___
___
**SIGUSR1**

    This signal and SIGUSR2 are available for programmer-defined purposes.
    The kernel never generates these signals for a process. Processes may use
    these signals to notify one another of events or to synchronize with each
    other. In early UNIX implementations, these were the only two signals that
    could be freely used in applications. (In fact, processes can send one
    another any signal, but this has the potential for confusion if the kernel
    also generates one of the signals for a process.) Modern UNIX implementations
    provide a large set of realtime signals that are also available for
    programmer-defined purposes (Section 22.8).\

___

___
### Building part :
#### The client:
    ** First we need to check given arguments and if they're valid **
    -->     Args numbers must be --> 2
    -->     Target server Pid --> pid_t 0 < pid_t < MAX_PID
    -->     Message to be sent -> A string or a NULL Value
___

#### The server:
    ** First we get our server process id **
    --->        Using the getpid() function
___


___
___
## Resources:
___
[The linux programming interface](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)
___
[Linux man pages](https://linux.die.net/man/)
___
[Stackoverflow Signals](https://stackoverflow.com/search?q=signals+in+C)
___
[Unicode and wide characters](https://beej.us/guide/bgc/html/split/unicode-wide-characters-and-all-that.html)
___
[Unix signals](https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/)
