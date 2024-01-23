#!/bin/bash
if [ $(pwd) != "/path/to/your/local/repo" ]; then
echo "Wrong directory man"
exit 1
fi
git add -A
echo "What should the commit message be:"
read message
git commit -m "${message}"
git push

