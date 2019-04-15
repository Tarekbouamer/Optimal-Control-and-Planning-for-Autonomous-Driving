# Optimal-Control-and-Planning-for-Autonomous-Driving

# Abstract
   Safety is an emerging tasks in the field of Self-driving Cars that includes Perception, Planning and Decision Making fields to improve the autonomy in all driving conditions especially in the urban driving where the cars shares the environment with other vehicles and pedestrians. Several research activities has been done and some promising results were achieved.

   In this project, we have focused on Trajectory planning and Execution task that enables our Amesim Car to overtake safely around predefined environment attempting to reduce the error between the planning and execution. A kinodynamic motion planner like-driver was developed to mimic the human driver actions and to provide us with an executable path.

  In addition, An optimal trajectory controller was designed to stabilize the vehicle and track perfectly the reference under system constraints. A simple and complete model of Amesim car was identified to be used in both path planning and controller design.

  Finally, a co-simulation is carried for different scenarios: double lane change test and racing track with different control schemes
  
  # Path planner like driver
  
   The solution to this problem is to find a set of input 𝑢(𝜏): [0,𝑇]∈𝒰 which results a free collision trajectory sample 𝑥(𝜏):[0,𝑇] ∈𝒳𝑓𝑟𝑒𝑒 in driving the car from 𝑥𝑖𝑛𝑡 toward goal state 𝑥𝑔𝑜𝑎𝑙 in bounded sample time 𝑇. Using a high fidelity model; motion planner and an iterative simulation technique will be performed to sample over 𝒳𝑓𝑟𝑒𝑒 .the following Algorithm describe the proposed Kinodynamic motion planner over specific scenario:

<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg1.png?raw=true" align="center" width="600"/>
   
   Lane change, lane following, overtaking and others are referred in Kinodynamic Motion planner algorithm as scenarios, for each scenario we have parametrized logically the control actions {Steer, Brake, Throttle} that should be taken to perform the task set by the decision making process. A randomized sampling process is used to set numerically the logical control action, for example; the logical action in overtaking the front car is to steer to the left and the numerical value that defines how much should I steer is set randomly following a distribution function 𝑆𝑡𝑒𝑒𝑟𝑙𝑒𝑓𝑡(𝑧)=𝐹(𝑍 ≤ 𝑧).
   
   Therefore, Rapidly Exploring Random Trees (RRT) is used to handle the randomized sampling process within Kinodynamic Motion Planner as quick as possible and uniform structure.
   
 <img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg2.png?raw=true" align="center" width="600"/>  
   
   As any RRT; a graph 𝐺 is created of nodes denoted 𝑉 (𝑣𝑒𝑟𝑡𝑖𝑐𝑒𝑠) that stores the final states of the car where the control inputs sequence to travel from initial node (parent) to current node (child) is stored in the edges 𝐸. 𝐷 denotes the Deleted nodes set that contains all nodes that are in collision to avoid repetition. The Extend function enables the tree to grow where each time we select a random node as parent to branch by applying random actions, we add the resulting node to 𝑉 and applied actions to 𝐸 if it is in the free collision set. In the case of the resulting node is in collision, we discard the applied action and we save the node in delete set. 𝑅𝑎𝑛𝑑𝑜𝑚_𝑆𝑎𝑚𝑝𝑙𝑒 function choose randomly a node from 𝑉 and try to explore wide range area.
   
<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg3.png?raw=true" align="center" width="600"/> 

the planning diagram:

<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg4.png?raw=true" align="center" width="600"/> 


# NMPC Trajectory Control

<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg5.png?raw=true" align="center" width="600"/> 

<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg6.png?raw=true" align="center" width="600"/> 

# Feedback + Feedforward Trajectory Control

<img src="https://github.com/Tarekbouamer/Optimal-Control-and-Planning-for-Autonomous-Driving/blob/master/me/Alg7.png?raw=true" align="center" width="600"/> 



