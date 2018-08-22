# Assignment 4

This assignment is again about **reservoir/quarry** mass balance: it is a simple and intuitive problem, relevant to all of us to an extent, and is easy to code. Be sure to use CLion instead of a text editor — this will make it easier to compile your code and will make a huge difference specially now that we are working with Object Oriented Programming. 

## The problem
Your job is to write an **OBJECT ORIENTED** code in C++ to simulate a system with **2 reservoirs and 1 quarry** with capacity of 100 MG each connected in series. Quarries are offline storage, meaning water is pumped from the stream into them at at a rate no higher than the pump capacity, meaning that the **amount of water added to the quarry at any given time step is capped either at the pumping capacity or at the difference between inflow and minimum environmental outflow, whichever is lower.**

All reservoirs and quarries are supposed to have a minimum environmental flow of 5 MGW.

## Structure of the code

Your code must have the main.cpp file in the root directory, and a folder for infrastructure-related classes. 

Your code must also have an abstract class to be inherited by any supply infrastructure you may want to implement in the future with the following methods:
    - A constructor
    - A virtual performMassBalance updating the stored volume and returning the release;
    - A destructor

Mass balance will be performed in a reservoir and a quarry classes that inherits your abstract infrastructure class. The reservoir and quarry classes must (by C++ definitions) implement the performanceMassBalance method from its parent generic infrastructure class.

Lastly, the mass balance loop is to be performed in the main.cpp by **storing the sources in a vector of water infrastructure and looping through it (remember polymorphism)**.

## Inflows and evaporations
Each reservoir will have its own time series of inflows and evaporations, which should be generated any distribution you like best that is implemented in the random library (#import <random>) — now Julie and Jared can happily implement their preferred distribution.

## Some finesse
Keep in mind that if the reservoir is full the release will be the minimum environmental flow plus any extra spillage. Conversely, if the reservoir is empty or close to empty the release will be smaller than the minimum environmental flow but never negative. Also, no stored volumes higher than capacity or smaller than 0 are allowed.


## Last considerations
Be sure to get memory management right using **Valgrind**, and the final numbers will be later checked with unit testing, yet to be taught. Be sure to add print statements that will let you see what is going on with your numbers. Lastly, keep in mind the good coding practices! They feel like a pain in the beginning but make a huge difference later.

Be sure to stop by or send me an e-mail if you are stuck.
