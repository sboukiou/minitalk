# MiniTalk
## The purpose of this project is to code a small data exchange program using UNIX signals.

    Create a communication program in the form of a client and a server.
## How It would work
    The server will be started and it will print it's own process id
    Then the client shall send a string given as param alongside with the server pid
    to that server

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

### Building part :
#### The client:
    ** First we need to check given arguments and if they're valid **
    -->     Args numbers must be --> 2
    -->     Target server Pid --> pid_t 0 < pid_t < MAX_PID
    -->     Message to be sent -> A string or a NULL Value

#### The server:
    ** First we get our server process id **
    --->        Using the getpid() function


## Resources:
\
[The linux programming interface](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf) is good book for Unix prorgrammig in genral
and has some good chapters talking about signals in details.\
[Linux man pages](https://linux.die.net/man/) The default option, searche engine for unix programming.\
[Stackoverflow Signals](https://stackoverflow.com/search?q=signals+in+C)\
