
# Teaching material

## Html

The material will be made available, progressively, on [this public project](https://github.com/chavid/ModernScientificCpp.git). There, one can download a `zip` file with anything included : lessons, videos, notebooks, exercises.

## Git

Also, one can clone the project with the command `git clone https://github.com/chavid/ModernScientificCpp.git`. If you want to get the videos, previously install `git-lfs` on top of `git`.

## About the problem: `server certificate verification failed. CAfile: none CRLfile: none`

This problem is rather common. It means your machine is probably not up to date for the package ca-certificates, and lack the recent letsencrypt certificates. Can be solved with something like `apt upgrade ca-certificates` (to be investigated).

