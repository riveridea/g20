#!/bin/bash

# automatically find all the documents containing a certain 
# keyword under a perticalur path

# echo -e to print colored texts, in Unix Version 8-style
# implementation, such as Bash
echo -e "\n This is a script to find all the files \n
        contianing a certian keyword under a specified path.\n"

echo -e "\ninput the keyword:"

read key
if ["$key" == ""]; then
    echo -e "keyword cannot be null!\n"
    exit 0
fi

keyword=$key

echo -e "\ninput the path you want to search"
read dir

# decide the existence of the path, and it is directory
# otherwise, output error.

# -e for file exists
# -d for directory
# test let you to do various tests and sets its exit code to 0 (True)
# or 1 (false) wheneer such a test succeeds or not.
test ! -d  $dir && echo -e "The $dir doesnot exist in your system.\n\n" && exit 0

echo -e "\n------- Files found are:--------------\n"

# count the number of documents
file_count=0

# check all the directories iteratively, the deepest depth without showing the empty line
file_list=`ls -R $dir 2> /dev/null | grep -v '^$'`

# use file cmd to check whether file is ASCII text type
file_type='file $cur_dir/$file_name | grep "text"'
