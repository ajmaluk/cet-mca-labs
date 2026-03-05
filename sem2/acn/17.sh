#!/bin/bash
echo "--- System Information ---"
echo "i) Count of users logged in:"
who | wc -l

echo -e "\nii) Column list of files in home directory (subset of ls -l):"
ls -l ~ | cut -c 17-24,39-50,56-

echo -e "\niii) List of jobs with below normal priority:"
ps -al | cut -c 16-19,70-
