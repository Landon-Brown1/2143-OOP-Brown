| Variable Description       | Value | 
|:--------------------------:|:-----:|
| Hospital capacity          | 5%    | 
| Input fatality rate        | 3%    |
| Self-quarantine rate       | 25%   |
| Self-quarantine strictness | 25%   |
| Encounters per day         | 10    |
| Travel radius              | 5     |
| Transmission rate          | 0.4   |
| Days in incubation         | 7     |
| Days with symptoms         | 8     |

| Number        | Folder                                                        | Description                          |
|:-------------:|:-------------------------------------------------------------:|:------------------------------------:|
| 02            | [P03](https://github.com/Landon-Brown1/2143-OOP-Brown/tree/master/Assignments/02-CommentedCode "COVID Stuff") | Assignment to try and map the spread of a disease |


## Program 3 - Modeling Covid19 Part 2
#### Due: 05-01-2020 (Friday @ 5:00 p.m.)

## Overview

I've posted a few python / pygame example code listings that progressively take you through ... well not a ton of gaming code, but enough to do what we need to get started with our covid19 simulation. This isn't strictly a visualization, but it will make it more interesting if we visualize our infected vs susceptible and recovered. 


### Disease Model

Not every simulation uses the same "model". We are using the SIR model (or a simple variation of) becuase it is straightforward and fits our purposes. However if we decide to use another model, we don't want our "simulation" to be tightly coupled with only a single disease model. For example the SEIR model or the SIS model. Therefore I propose a class that will allow us to load any model. 

The SIR model: 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/sir_flow_diagram_2020.png" width="500">

**State Descriptions:** 

| #    | State       | Description                                     | Exceptions                 |
| :--- | :---------- | :---------------------------------------------- | :------------------------- |
| 1    | Susceptible | Any person who can catch the disease            | Already infected or immune |
| 2    | Infectious  | A person that has the disease and is contagious | Quarantined                |
| 3    | Recovered   | A person who had the disesase and recovered     |                            |

**Additional State Info:**

| #    | State       | Color  | Image                              |
| :--- | :---------- | :----- | :--------------------------------- |
| 1    | Susceptible | Yellow | ![](./images/pac_yellow_30x30.png) |
| 2    | Infectious  | Red    | ![](./images/pac_red_30x30.png)    |
| 3    | Recovered   | Green  | ![](./images/pac_green_30x30.png)  |



<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/covid19a_uml_2020.png" height="150">




### Simulation Class



|                                          Sim Disease Variables                                          |                                     Sim Additional Variables 2                                      |
| :-----------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/covid19_sir_model_vals.png" width="350"> | <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/covid19_sim_params.png" width="200"> |

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/covid19b_uml_2020.png" width="150">


### Other Possible Classes

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/covid19_uml_2020.png" width="350">




## Project

Project explanation coming

### Deliverables

Deliverables coming




