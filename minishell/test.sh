# MINISHELL-TESTER-2020.08

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

# Compile and set executable rights
make -C ./ > /dev/null
cp ./minishell .
chmod 755 minishell


GOOD=0
TOTAL=0

pipe=/tmp/testpipe
trap "rm -f $pipe" EXIT
if [[ ! -p $pipe ]]; then
    mkfifo $pipe
fi

function exec_test()
{
  
  # execute commands, separated by ';' in minishell, using nfifo
  ./minishell < $pipe >msh_log 2>&-  &
  IFS=';' read -ra CMND <<< "$@"
  for command in "${CMND[@]}"; do
    echo $command > $pipe
  done
  echo 'exit' > $pipe
  sleep 0.05
  wait $!
  ES_1=$?
  TEST1=$(cat msh_log)

  # execute commands in bash
  TEST2=$(echo $@ | bash 2>&-)
  ES_2=$?

  # compare result
  if [ "$TEST1" == "$TEST2" ] && [ "$ES_1" == "$ES_2" ]; then
    printf "$BOLDGREEN%s$RESET" "✓ "
    ((GOOD++))
  else
    printf "\n$BOLDRED%s$RESET" "✗ "
    printf "$CYAN \"$@\" $RESET"
  fi
  if [ "$TEST1" != "$TEST2" ]; then
    echo
    printf $BOLDRED"Your output : \n%.20s\n$BOLDRED$TEST1\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
    printf $BOLDGREEN"Expected output : \n%.20s\n$BOLDGREEN$TEST2\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
    echo
  fi
  if [ "$ES_1" != "$ES_2" ]; then
    echo
    printf $BOLDRED"Your exit status : $BOLDRED$ES_1$RESET\n"
    printf $BOLDGREEN"Expected exit status : $BOLDGREEN$ES_2$RESET\n"
    echo
  fi
  ((TOTAL++))
  sleep 0.1
}

if [ "$1" == "" ] || [ "$1" == "help" ]; then
  printf "$BOLDMAGENTA\n\tAvailable arg: \n$YELLOW\tall$RESET echo cd pipe env export redirect multi syntax exit\n\
      $GREEN\tbonus$RESET quote wildcard oper\n"
fi
if [ "$1" == "all" ]; then
printf "$BOLDMAGENTA __  __ _____ _   _ _____  _____ _    _ ______ _      _      \n"
printf "|  \/  |_   _| \ | |_   _|/ ____| |  | |  ____| |    | |     \n"
printf "| \  / | | | |  \| | | | | (___ | |__| | |__  | |    | |     \n"
printf "| |\/| | | | | . \` | | |  \___ \|  __  |  __| | |    | |     \n"
printf "| |  | |_| |_| |\  |_| |_ ____) | |  | | |____| |____| |____ \n"
printf "|_|  |_|_____|_| \_|_____|_____/|_|  |_|______|______|______|\n$RESET"
fi


# ECHO TESTS
if [ "$1" == "echo" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tECHO TESTS\n"$RESET
  exec_test 'echo test tout'
  exec_test 'echo test tout'
  exec_test 'echo -n test tout'
  exec_test 'echo "-n" test tout'
  exec_test '"echo" -n test tout'
  exec_test 'echo -n -nnnnnnn -n test tout'
  exec_test 'echo -nnnnn+nnn -n test tout'
  exec_test 'echo -nnnnnnnnm -n test tout'
  exec_test 'echo '
  exec_test 'echo'
  exec_test '"echo " test tout'
  exec_test "'echo ' test tout"
fi

# CD TESTS
if [ "$1" == "cd" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tCD TESTS\n"$RESET
  exec_test 'cd .. ; pwd'
  exec_test 'cd /Users ; pwd'
  exec_test 'cd ; pwd'
  exec_test 'cd . ; pwd'
  exec_test 'mkdir test_dir ; cd test_dir ; rm -rf ../test_dir ; cd . ; cd .. ; pwd'
fi



# PIPE TESTS
if [ "$1" == "pipe" ] || [ "$1" == "all" ]; then
	printf $BOLDMAGENTA"\n\tPIPE TESTS\n"$RESET
	exec_test '/bin/ls'
	exec_test 'echo test | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e'
	exec_test 'echo test | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e'
	exec_test 'cat /dev/random | head -c 100 | wc -c'
	exec_test 'ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls'
	exec_test 'ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls'
	head -c 2000000 /dev/zero > big_file
	exec_test ' cat big_file | ls'
	exec_test ' cat big_file | echo lol'
fi


# ENV EXPANSIONS
if [ "$1" == "env" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tENV EXPANSIONS TESTS\n"$RESET
	exec_test 'echo test test'
	exec_test 'echo test'
	exec_test 'echo $TEST'
	exec_test 'echo "$TEST"'
	exec_test 'echo "$?"'
	exec_test 'echo $?'
	exec_test "echo '$TEST'"
	exec_test 'echo "$TEST$TEST$TEST"'
	exec_test 'echo "$TEST$TEST=lol$TEST"'
	exec_test 'echo $TEST$TEST$TEST'
	exec_test 'echo test "$TEST" test "$TEST " test'
	exec_test 'echo "$=TEST"'
	exec_test 'echo "$"'
	exec_test 'echo "$?TEST"'
	exec_test 'echo "$1TEST"'
	exec_test 'echo "$T1TEST"'
	exec_test 'echo " $TEST lol $TEST"'
	exec_test 'echo $TEST$TEST=lol$TEST""lol'
	exec_test 'echo $TEST $TEST'
	exec_test 'echo $TEST lol $TEST'
fi

# EXPORT
if [ "$1" == "export" ] || [ "$1" == "all" ]; then
	printf $BOLDMAGENTA"\n\tEXPORT TESTS\n"$RESET
	ENV_SHOW="env | sort | grep -v SHLVL | grep -v _= "
	EXPORT_SHOW="export | sort | grep -v SHLVL | grep -v _= | grep -v OLDPWD"
	exec_test 'export TES=T="" ; ' $ENV_SHOW
	exec_test $ENV_SHOW
	exec_test $EXPORT_SHOW
	exec_test 'export TEST=LOL ; echo $TEST$TEST$TEST=lol$TEST'
	exec_test 'export TEST=LOL ; echo $TEST ; ' $ENV_SHOW
	exec_test 'export TEST=LOL ; export TEST+=LOL ; echo $TEST ; ' $ENV_SHOW
	exec_test 'export TEST="ls -l - a" ; echo $TEST ; ' $ENV_SHOW
	exec_test 'export TEST ;' $EXPORT_SHOW
	exec_test 'asd=123 ; export asd ; ' $ENV_SHOW
	exec_test 'asd=123 ; export asd ; unset asd ; ' $EXPORT_SHOW
fi


# REDIRECTIONS
if [ "$1" == "redirect" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tREDIRECTION TESTS\n"$RESET
  exec_test '>lol echo > test>lol>test>>lol>test mdr >lol test >test ; cat test'
  exec_test 'echo test > ls ; cat ls'
  exec_test 'echo test > ls >> ls >> ls ; echo test >> ls ; cat ls'
  exec_test 'cat < ls'
  exec_test 'rm -f ls; cat > ls < ls; rm -f ls'
  exec_test 'ls > ls'
  exec_test 'cat <ls'
  exec_test 'cat <test.sh <ls'
  exec_test '> lol echo test lol ; cat lol'
  exec_test 'rm -f ls >ls'
#   exec_test 'cat << stop \n1\nstop\n'
#   exec_test 'cat << stop\n1\EOF\nstopa\nstop'
#   exec_test 'cat <test.sh <<stop \n1\nstop'
#   exec_test 'cat <<stop<ls  \n1\nstop'
#   exec_test 'cat <test.sh << stop1 <<stop2 \na\n \nb \nc \nstop1\n run2 \nstop2'
fi


# MULTI TESTS
if [ "$1" == "multi" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tMULTI TESTS\n"$RESET
	exec_test 'echo testing multi >lol ; echo <lol <lola ; echo "test 1  | and 2" >>lol ; cat <lol ; cat ./Makefile <lol | grep minishell'
	exec_test "ls -la | wtf"
	exec_test 'expr $? + $? > 1 ; expr $? + $? >> 1 ; expr $? + $? >> 1 ; cat 1'
	exec_test "mkdir asd ; cd asd ; rm -rf ../asd ; pwd"
fi

# SYNTAX 
if [ "$1" == "syntax" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tSYNTAX\n"$RESET
  exec_test ''
  exec_test 'echo "||"'
  exec_test "ls'| 'wc -l"
  exec_test '/bin/lsa'
  exec_test './Makefile'
  exec_test '| test'
  exec_test 'echo > <'
  exec_test 'echo | |'
  exec_test '<'
  exec_test 'rm -f ls; cat < ls > ls'
fi

# EXIT
if [ "$1" == "exit" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tEXIT\n"$RESET
  exec_test "exit 42"
  exec_test "exit 259"
  exec_test "exit 9223372036854775807"
  exec_test "exit 9223372036854775808"
  exec_test "exit -9223372036854775810"
  exec_test "exit 99999999999999999999999"
  exec_test "exit -99999999999999999999999"
  exec_test "exit wrong"
  exec_test "gdagadgag"
  exec_test "exit -9223372036854775808"
  exec_test "exit -4"
fi

# ERRORS
if [ "$1" == "error" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tERROR TESTS\n"$RESET
	exec_test 'cat asdasdasd'
	exec_test 'cd asdasdasdas ; pwd'
	exec_test "ls -Z"
	exec_test "ls -l > 1 ; 'cat ' 1"
	exec_test "cd gdhahahad"
	exec_test "exit 42 53 68"
	exec_test "exit  2 wrong_command"
	exec_test 'export ='
	exec_test 'export 1TEST= ;' $ENV_SHOW
	exec_test 'export ""="" ; ' $ENV_SHOW
	exec_test 'export TE+S=T="" ; ' $ENV_SHOW
	# exec_test "grep -z"
	# exec_test 'cat asdasdasd | grep arcu | cat -e'
fi

# BONUS QUOTES
if [ "$1" == "bonus" ] || [ "$1" == "all" ]; then
  printf $BOLDMAGENTA"\n\tBONUS QUOTE\n"$RESET
  exec_test "echo '"$USER"'"
  exec_test "echo "'$USER'""
fi


# BONUS WILDCARD
if [ "$1" == "bonus" ] || [ "$1" == "wildcard" ]; then
  Compile and set executable rights
  make bonus -C ./ > /dev/null
  cp ./minishell .
  chmod 755 minishell

  printf $BOLDMAGENTA"\n\tBONUS WILDCARD\n"$RESET
  exec_test "echo * | wc"
  exec_test "cd .. ; echo * | wc"
  exec_test "echo .* | wc"
  exec_test "echo M*e"
  exec_test "echo *a*e"
  exec_test "echo *.mp3"
  exec_test "mkdir empty; cd empty; pwd; echo *; cd ..; rm -rf empty"
fi

# BONUS OPERATOR && || ()
if [ "$1" == "bonus" ] || [ "$1" == "oper" ]; then
  Compile and set executable rights
  make bonus -C ./ > /dev/null
  cp ./minishell .
  chmod 755 minishell

  printf $BOLDMAGENTA"\n\tBONUS OPERATOR \$\$ || () \n"$RESET
  exec_test "true && ls"
  exec_test "false&&ls"
  exec_test "true||ls"
  exec_test "false || ls"
  exec_test "true || echo 1 && echo 2"
  exec_test "false || echo 1 && echo 2"
  exec_test "true || (echo 1 && echo 2)"
  exec_test "true || echo 1 && echo 2 || echo 3"
  exec_test "(ls)"
  exec_test "( ls )"

  exec_test "true || (echo 1 && echo 2) || echo 3"
  exec_test "true || (echo 1 && echo 2) && echo 3"
  exec_test "(true || (echo 1 && echo 2) && echo 3)"
  exec_test "true || ((echo 1 && echo 2) && echo 3)"
  
  exec_test "( )"
  exec_test " ls )"
  exec_test "( ls " 
  exec_test "ls && (touch 1 && pwd) && "
fi


if [[ "$1" != "" ]] && (( $TOTAL > 0)); then
  PROCENT=$(( $GOOD * 100  / $TOTAL ))
  if (( $PROCENT > 90)); then
    printf $GREEN
  elif (( $PROCENT <= 90 )) && (( $PROCENT > 60 )); then
    printf $YELLOW
  else  
    printf $RED
  fi
  printf "\nPASS: $GOOD / $TOTAL ($PROCENT%%)$RESET\n"
fi

rm -f $pipe lol ls 1 test big_file msh_log
