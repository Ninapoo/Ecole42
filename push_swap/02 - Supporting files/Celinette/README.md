# Ecole42_Push_swap

Run this to give it a random arrangement of numbers from a to b by changing the numbers below. (a..b)

ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`; ./a.out $ARG  

## To run the program with random numbers: 

ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG

## Using celinette_checker.sh

Copy celinette_checker.sh and checker_Mac in your push_swap folder. 
Run the follwing:

bash celinette_checker.sh


## Using celinette_counter.sh

Copy celinette_count.sh in your push_swap folder. 


Run the follwing:

bash celinette_count.sh

### You can change the number of runs that you're testing for corrections. 
NUM_RUNS=40;
### You can change the limits that you're testing for corrections. 
LIMIT5NUM=12;
LIMIT100NUM=700;
LIMIT500NUM=5500;
