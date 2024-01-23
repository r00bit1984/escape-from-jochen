#! /bin/bash
git add -A
echo "What should the commit message be:"
read a
git commit -m "${a}"
git push --force

