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

## Example
