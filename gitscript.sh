#!/bin/bash

git init && git remote add origin "$1" && git add * && git commit -m "first commit" && git push origin master
