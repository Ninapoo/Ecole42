# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

LRED='\033[1;31m'
BLUE='\033[1;34m'
LP='\033[1;35m'
LG='\033[1;32m'
NC='\033[0m' # No Color

# This checker requires that you use the checker provided for this project.
# This checker will run your program NUM_RUNS number of times, count the number of OK's, and return this number.
# This is useful to quickly check that your program is still working for several different combination of numbers.
# The numbers x and y in (x..y) is the range of numbers from which the random combination of numbers is created. You can change the numbers x and y in (x..y).

NUM_RUNS=30;
CHECKER_PATH=./celinette_checker

#PUSH_SWAP MAKEFILE ============================================================
printf "${LP}\n*** Running makefile\n${NC}"
#make re -s
make re -s | wc -l

#TESTING WITH ARGC = 2
printf "${LG}Testing with argc = 2${NC}"
#PUSH_SWAP FOR Duplicates ============================================================
printf "${LP}\n*** Running pushswap with ${LG}\"1 3 6 4 9 5 3 6\" ${LP}to check duplicates\n It Should say ${LG} Error ${NC}:"
	./push_swap "1 3 6 4 9 5 3 6"
printf "${LP}\n*** Running pushswap with ${LG}\"1 1 2\" ${LP}to check duplicates\n It Should say ${LG} Error ${NC}:"
	./push_swap "1 1 2"

#PUSH_SWAP FOR Non-Integers ============================================================
printf "${LP}\n*** Running pushswap with ${LG}\"1 3 6 k4 9 5 3 6\" ${LP}to check non-integer\n It Should say ${LG} Error ${NC}:"
	./push_swap "1 3 6 k4 9 5 3 6"

#PUSH_SWAP FOR Greater than INT_MAX ============================================================
printf "${LP}\n*** Running pushswap with ${LG}\"1 3 6 2147483648 9 5 3 6\" ${LP}to check greater than INT_MAX\n It Should say ${LG} Error ${NC}:"
	./push_swap "1 3 6 2147483648 9 5 3 6"

#PUSH_SWAP FOR Less than INT_MIN ============================================================
printf "${LP}\n*** Running pushswap with ${LG}\"1 3 6 -2147483649 9 5 3 6\" ${LP}to check less than INT_MIN\n It Should say ${LG} Error ${NC}:"
	./push_swap "1 3 6 -2147483649 9 5 3 6"

#PUSH_SWAP FOR INT_MIN and INT_MAX ============================================================
printf "${LP}\n*** Running pushswap with ${LG}\"1 6 -2147483648 9 5 2147483647 3\" ${LP}to check INT_MIN & INT_MAX\n It Should say ${LG} OK ${NC}:"
	./push_swap "1 6 -2147483648 9 5 2147483647 3" | ./checker_Mac 1 "6 -2147483648 9 5 2147483647 3"

#TESTING WITH MANY_ARGS
printf "${LG}Testing with argc > 2${NC}"
#PUSH_SWAP FOR Duplicates ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 3 6 4 9 5 3 6 ${LP}to check duplicates\n It Should say ${LG} Error ${NC}:"
	./push_swap 1 3 6 4 9 5 3 6
printf "${LP}\n*** Running pushswap with ${LG}1 1 2 ${LP}to check duplicates\n It Should say ${LG} Error ${NC}:"
	./push_swap 1 1 2

#PUSH_SWAP FOR Non-Integers ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 3 6 k4 9 5 3 6${LP} to check non-integer\n It Should say ${LG} Error ${NC}:"
	./push_swap 1 3 6 k4 9 5 3 6

#PUSH_SWAP FOR Greater than INT_MAX ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 3 6 2147483648 9 5 3 6 ${LP}to check greater than INT_MAX\n It Should say ${LG} Error ${NC}:"
	./push_swap 1 3 6 2147483648 9 5 3 6

#PUSH_SWAP FOR Less than INT_MIN ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 3 6 -2147483649 9 5 3 6${LP} to check less than INT_MIN\n It Should say ${LG} Error ${NC}:"
	./push_swap 1 3 6 -2147483649 9 5 3 6

#PUSH_SWAP FOR INT_MIN and INT_MAX ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 6 -2147483648 9 5 2147483647 3 ${LP}to check INT_MIN & INT_MAX\n It Should say ${LG} OK ${NC}:"
	./push_swap 1 6 -2147483648 9 5 2147483647 3 | ./checker_Mac 1 6 -2147483648 9 5 2147483647 3

#PUSH_SWAP FOR more than 1000 numbers ============================================================
printf "${LP}\n*** Running pushswap with ${LG} -500 to 500 ${LP}to check that it works with more than 1000 numbers\n It Should say ${LG} OK ${NC}:"
		ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG

printf "${LG}==============\nTesting the Algo now :) ${NC}"
#============================================================
printf "${LP}\nNumber of runs: ${LG}"
echo $NUM_RUNS

#PUSH_SWAP FOR 5 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for -2 to 2\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG >> $CHECKER_PATH
	i=$[$i+1]
done
printf "${BLUE}*** Number of OK = \t ${NC}"
grep -o "OK" $CHECKER_PATH | wc -l
rm $CHECKER_PATH

#PUSH_SWAP FOR 5 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 0 to 11\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (0..11).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG >> $CHECKER_PATH
	i=$[$i+1]
done
printf "${BLUE}*** Number of OK = \t ${NC}"
grep -o "OK" $CHECKER_PATH | wc -l
#cat /dev/null > $CHECKER_PATH
rm $CHECKER_PATH

#PUSH_SWAP FOR 100 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 0 to 100\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG >> $CHECKER_PATH
	i=$[$i+1]
done
printf "${BLUE}*** Number of OK = \t ${NC}"
grep -o "OK" $CHECKER_PATH | wc -l
#cat /dev/null > $CHECKER_PATH
rm $CHECKER_PATH

#PUSH_SWAP FOR -100 to 100 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for -100 to 100\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (-100..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG >> $CHECKER_PATH
	i=$[$i+1]
done
printf "${BLUE}*** Number of OK = \t ${NC}"
grep -o "OK" $CHECKER_PATH | wc -l
#cat /dev/null > $CHECKER_PATH
rm $CHECKER_PATH

#TESTING WITH Already sorted numbers
printf "${LG}\nTesting with Already sorted numbers ${NC}"
#PUSH_SWAP FOR Duplicates ============================================================
printf "${LP}\n*** Running pushswap with ${LG}1 2 3 4 5 6 7 ${LP}\n It Should return nothing: ${NC}"
	./push_swap 1 2 3 4 5 6 7
printf "\n"

#TESTING WITH no numbers given
printf "${LG}Testing with no arguments ${NC}"
#PUSH_SWAP FOR Duplicates ============================================================
printf "${LP}\n*** Running pushswap with ${LP}\n It Should return nothing: ${NC}"
	./push_swap
#printf "\n"

printf "${LP}\n*** Running pushswap with ${LG}\"\"${LP}\n It Should return nothing: ${NC}"
	./push_swap ""
#printf "\n"

printf "${LP}\n*** Running pushswap with ${LG}\" \"${LP}\n It Should return nothing: ${NC}"
	./push_swap " "
#printf "\n"
