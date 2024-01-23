#!/bin/bash
if [ $(pwd) != "/Users/robber/Documents/DHBW/Programmieren/c-projekt" ]; then
echo "Wrong directory man"
exit 1
fi
git add -A
echo "What should the commit message be:"
read a
git commit -m "${a}"
git push

