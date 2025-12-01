# philosophers

![demo](https://imgur.com/a/z0vCbDF)

*4 philos, 42ms die time, 20ms eat, 20ms sleep.  no deaths.  tight timing works.*

## what is this

42 project.  the dining philosophers problem but make it thread-safe. 

basically philosophers sit at a table, they need two forks to eat, and they die if they don't eat in time. classic synchronization problem.

## implementation

- pthreads for threading
- mutexes for fork synchronization
- precise timing with gettimeofday
- no data races, no deadlocks (hopefully)

built this to understand multithreading better.  learned a lot about race conditions the hard way. 
