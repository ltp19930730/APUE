### Exercises

## 10.1 In figure 10.2, remove the for ( ;; ) statement. What happens and why?

After sending one signal, the process just exit.
Because the process pause only once and after receiving the signal.
The reason is that the pause function returns whenever a signal is caught.

## 10.2 Implement the sig2str function described in Section 10.22

## 10.3 The longjmp from sig_alrm back to sleep2 effectively aborts the call to sig_int.From this point, sleep2 returns to main.

## 10.4 
We again have a race condition, this time between the first call to alarm and the call to setjmp. If the process is blocked by the kernel between these two function calls, the alarm goes off, the signal handler is called, and longjmp is called. But since setjmp was never called, the buffer env_alrm is not set. THe operation of longjmp is undefined if its jump buffer has not been initialized by setjmp.

## 10.5 Using only a single timer( either alarm or the higher-precision setitimer), provide a set of functions that allows a process to set any number of timers.

## 10.12 
The results depend on the implementation of the standard I/O library: how the fwrite function handles an interrupted write.

On Linux 3.2.0, for example, when we use the fwrite function to write a large buffer, the fwrite function calls write directly for the same number of bytes. While in the middle of the write system calls, the alarm fires, but we don't see the signal until the write completes. It appears as if the kernel is blocking the signal while we are in the middle of the write system call.


