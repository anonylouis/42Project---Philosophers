# 42Project---Philosophers

## The dinning philosophers problem

The subject is inspired from the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). Briefly, the problem follows a few rules :
- There are n philosophers around a circular table.
- There is a large dish in the center of the table.
- There are n forks on the table, each fork located between two philosophers.
- To eat a philosopher must take the fork on his right and the fork on his left.
- After eating a philosopher needs to sleep.
- If the philosopher is not eating nor sleeping, he is thinking.
- If the philosopher has not eaten for a certain time, he dies.

This problem can highlight certain issues such as :
- how to avoid blocking situations (if each philosopher takes a fork, no one can eat and they all die)
- some issues of optimization.

The goal of the subject is to find an algorithm that best avoids the death of philosophers!

*[en.subject.pdf](https://github.com/anonylouis/42Project---Philosophers/blob/main/en.subject.pdf) is the orginal subject from 42 Paris.*

## Description

The program takes 4 or 5 arguments :  
```./philo n Tdeath Teat Tsleep [nb_meal]```  
- n : the number of philosophers
- Tdeath : if a phlosopher has not eaten for Tdeath milliseconds, he dies.
- Teat : the time (in milliseconds) needed by a philosopher to eat
- Tsleep : the time (in milliseconds) needed by a philosopher to sleep
- nb_meal **[optional]** : if all philosophers eat nb_meal times, the simulation stops.

## My algorithm

My algorithm is different depending on the number of philosophers :
- If the number of philosophers is even, the solution is quite easy.  
The even-ranked philosophers will start eating. When they're done, they will drop their forks and the odd-ranked philosophers will start eating as well. The even-ranked philosophers will sleep and then wait for the odd-ranked philosphers etc.. They are all just waiting the forks being avalaibale alternnately.  
![philo_even](https://github.com/anonylouis/42Project---Philosophers/blob/main/philo_even.png)
- If the number of philosophers is odd, the solution is much more complicated. But to make it simple we can notice that if the simulation starts well I will just have to force each philosopher to think *Teat milliseconds* each time he eats+sleeps (n-1)/2 times. To get the simulation off to a good start, all you have to do is desynchronize the philosophers.  
For example, with n=5 philosophers, (n-1)/2 = 2 : I will force them to think each time they eat+sleep 2 times.  
![philo_odd](https://github.com/anonylouis/42Project---Philosophers/blob/main/philo_odd2.png)

## Example

Some commands to test the program :
- `./philo 4 410 200 200` : No philospher must die (even number case).
- `./philo 3 610 200 200` : No philospher must die (odd number case).
- `./philo 4 310 200 200` : A philosopher must die (even number case).
- `./philo 3 510 200 200` : No philospher must die (odd number case).

## Bonus

 - *philo* is using one thread per philosophers and one mutex per forks.
 - *philo_bonus* is using one process per philosphers and a semaphore for all the forks.
