## Chapter 09

### Exercise 9.1

> Refer back to our discussion of the utmp and wtmp files in Section 6.8. Why are the logout records written by the init process? Is this handled the same way for a network login?

When the user is terminal login, the workflow is **init->**getty->**login->**shells.When the **login is done,it will be deleted, so the process **shell becomes orphan process and be redirected to **init as his child.

So when the user logouts, the process **shell must be deleted, and his parent **init will notice this event. Then he writes the logout record to file **wtmp and **utmp.

But in the network login, the parent process of **shell is process **inetd, and he is always running to accept other network login request, so when uer logouts, it is inetd's duty to write to the file **utmp and **wtmp.

### Exercise 9.2

> Write a small program that calls fork and has the child create a new session. Verify that the child becomes a process group leader and that the child no longer has a controlling terminal.
