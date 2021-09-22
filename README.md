# The Dining Philosophers Problem
This is a classic task that provides an understanding of Process synchronization, work with threads.

Exercise:
---------------------------------------------------------------------------------------------------------------------------------
• One or more philosophers are sitting at a round table doing one of three things:
eating, thinking, or sleeping.<br>
• While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.<br>
• The philosophers sit at a circular table with a large bowl of spaghetti in the center.<br>
• There are some forks on the table.<br>
• As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand.<br>
• The philosophers must never be starving.<br>
• Every philosopher needs to eat.<br>
• Philosophers don’t speak with each other.<br>
• Philosophers don’t know when another philosopher is about to die.<br>
• Each time a philosopher has finished eating, he will drop his forks and start sleeping.<br>
• When a philosopher is done sleeping, he will start thinking.<br>
• The simulation stops when a philosopher dies.<br>

Compiling's commands:
---------------------------------------------------------------------------------------------------------------------------------
* make - compiling <br>
* make clean - clean *.o <br>
* make fcleen - clean all <br>
* make re - recompiling <br>

Arguments:
---------------------------------------------------------------------------------------------------------------------------------
1. number_of_philosophers 
2. time_to_die time_to_eat 
3. time_to_sleep
4. number_of_times_each_philosopher_must_eat

Examples:
----------------------------------------------------------------------------------------------------------------------------------
* ./philo 5 800 200 200 - no one should die!<br>
* ./philo 5 800 200 200 7 - no one should die and the simulation should stop when all the philosopher has eaten
  atleast 7 times each.<br>
* ./philo 4 410 200 200 - no one should die!<br>
* ./philo 4 310 200 100 - a philosopher should die!<br>

Attention!
----------------------------------------------------------------------------------------------------------------------------------
- Do not test with more than 200 philosophers
- Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms - Test with 1 800 200 200, the
  philosopher should not eat and should die!
---------------------------------------------------------------------------------------------------------------------------------
Actual Status : finished.
Result : 100%

This is my philosopher's project from the 42 cursus.
Have questions? Write me.
