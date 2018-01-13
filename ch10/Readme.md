### Common Signal

## SIGABRT
```
This signal is generated by calling the **abort** function. The process terminates abnormally.
```
## SIGALRM

This signal is generated when a timer set with the **alarm** function expires. This signal is also generated when an interval timer set by the **setitimer** function expires.

## SIGBUS

This signal indicates an implementation-defined hardware default. Implementations usually generate this signal on certain types of memory faults.

## SIGCANCEL

This signal is used internally by the Solaris threads library. It is not meant for general use.

## SIGCHILD

Whenever a process terminates or stops, the SIGCHILD signal is sent to the parent. By default, this signal is ignored, so the parent must catch this signal if it wants to be notified whenever a child's status changes. The normal action in the signal-catching function is to call one of the **wait** functions to fetch the child's process ID and termination status.

## SIGCONT

This job-control signal is sent to a stopped process when it is continued. The default action is to continue a stopped process, but to ignore the signal if the process wasn't stopped.

## SIGEMT

This indicates an implementation-defined hardware fault. (Not all platforms support this signal)

## SIGFPE

This signals an arithmetic exception, such as divide by 0, floating-point overflow, and so on.

## SIGFREEZE

This signal is defined only by Solaris.

## SIGHUP

This signal is sent to the controlling process (session leader) associated with a controlling terminal if a disconnect is detected by the terminal interface.
This signal is also generated if the session leader terminates. In this case, the signal is sent to each process in the foreground process group.
This signal is commonly used to notify daemon processes to unread their configuration files.The reason SIGHUP is chosen for this task is that a daemon should not have a controlling terminal and would normally never receive this signal.

## SIGILL

This signal indicates that the process has executed an illegal hardware instruction.

## SIGINFO

This BSD signal is generated by the terminal driver when we type the status key (often Control-T). This signal is sent to all processes in the foreground process group.
This singal normally causes status information on processes in the foreground process group to be displayed on the terminal.

**No support for Linux**

## SIGINT
This signal is generated by the terminal driver when we press the interrupt key (often DELETE or control-C). This signal is sent to all processes in the foreground process group.

## SIGIO

This signal indicates an asynchronous I/O event.

## SIGIOT

This indicates an implementation-defined hardware fault.

## SIGJVM1 && SIGJVM2

Signal reserved for use by the Java virtual machine on Solaris

## SIGKILL

The most powerful signal, which is one of the two that can't be caught or ignored. It provides the system administrator with a sure way to kill any process.

## SIGLOST

## SIGLWP

## SIGPIPE

If we write to a pipeline but the reader has terminated, SIGPIPE is generated. This signal is also generated when a process writes to a socket of type SOCK_STREAM that is no longer connected.

## SIGPOLL
## SIGPROF
Both might be removed in a future version of the standard.

## SIGPWR
This signal is system dependent. If you get the battery.

## SIGQUIT
This signal is generated by the terminal driver when we press the terminal quit key (often Control-backslash). This signal is sent to all processes in the foreground process group. This signal not only terminates the foreground process group, but also generates a core file.

## SIGSEGV
This signal indicates that the process has made an invalid memory reference such as dereferencing an uninitialized pointer.

## SIGSTKFLT
Defined only by Linux.

## SIGSTOP

This job-control signal stops a process. It is similar to the interactive stop signal(SIGTSTP), but SIGSTOP cannot be caught or ignored.

## SIGSYS

This singals an invalid system call.

## SIGTERM

This is the termination signal sent by the **kill** command by default.Because it can be caught by applications, using SIGTERM gives programs a chance to terminate gracefully by cleaning up before exiting.

In contract to SIGKILL, which can't be caught or ignored.

## SIGTHAW
## SIGTHR
## SIGTRAP

This signal indicates an implementation-defined hardware fault.

## SIGTSTP

This interactive stop signal is generated by the terminal driver when we press the terminal suspend key(often Control-Z).

## SIGTTIN

This signal is generated by the terminal driver when a process in a background process group tries to read from its controlling terminal.

## SIGTTOU

This signal is generated by the terminal driver when a process in a background process group tries to write from its controlling terminal.

## SIGURG

This signal notifies the process that an urgent condition has occurred. It is optionally generated when out-of-band data is received on a network connection.

## SIGUSR1 && SIGUSR2

user-defined signal, for use in application programs.

## SIGVTALRM
This signal is generated when a virtual interval timer set by the **setitimer** function expires.

## SIGWAITING
## SIGWINCH

If a process changes the window size from its previous value using the **ioctl** set-window-size command, the kernel generates the SIGWINCH signal for the foreground process group.

## SIGXCPU

If the process exceeds its soft CPU time limit, the SIGXCPU signal is generated.

## SIGXFSZ

This signal is generated if the process exceeds its soft file size limit.

## SIGXRES









