#!/bin/zsh

echo -n "Test 1: "
if ./philo 4 310 200 100 | grep -q died; then
   echo "OK"
else
   echo "KO --> ./philo 3 310 200 100"
fi

echo -n "Test 2: "
if ./philo 4 410 200 200 12 | grep -q died; then
   echo "KO --> ./philo 4 410 200 200 12"
else
   echo "OK"
fi

echo -n "Test 3: "
if ./philo 10 610 200 200 10 | grep -q died; then
   echo "KO -- > ./philo 10 610 200 200 10"
else
   echo "OK"
fi

echo -n "Test 4: "
./philo 1 800 200 200 > t4;
if < t4 grep -q died; then
   if < t4 grep -q eating; then
      echo "KO --> ./philo 1 800 200 200"
   else
      echo "OK"
   fi
else
   echo "KO --> ./philo 1 800 200 200"
fi
rm t4

echo -n "Test 5: "
if ./philo 5 800 200 200 12 | grep -q died; then
   echo "KO --> ./philo 5 800 200 200 12"
else
   echo "OK"
fi

echo -n "Test 6: "
if ./philo 5 800 200 200 7 | grep -q died; then
   echo "KO -- > ./philo 5 800 200 200 7"
else
   echo "OK"
fi

echo -n "Test 7: "
if ./philo 9 510 200 200 10 | grep -q died; then
   echo "OK"
else
   echo "KO --> ./philo 9 510 200 200 10"
fi

echo -n "Test 8: "
if ./philo 10 510 200 200 8 | grep -q died; then
   echo "KO --> ./philo 10 510 200 200 8"
else
   echo "OK"
fi

echo -n "Test 9: "
if ./philo 60 610 200 200 10 | grep -q died; then
   echo "KO --> ./philo 60 610 200 200 10"
else
   echo "OK"
fi

echo -n "Test 10: "
if ./philo 120 810 200 200 8 | grep -q died; then
   echo "KO --> ./philo 120 810 200 200 8"
else
   echo "OK"
fi

echo -n "Test 11: "
if ./philo 200 810 200 200 8 | grep -q died; then
   echo "KO --> ./philo 200 810 200 200 8"
else
   echo "OK"
fi