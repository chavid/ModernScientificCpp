
# Pedagogic material

## Html

The material will be made available, progressively, on [this public project](https://gitlab.in2p3.fr/chamont/modernscientificcpp) of the IN2P3 gitlab server. There, one cam download a `zip` or `tar`file with anything included : lessons, videos, notebooks, exercises.

## Git

Also, on can clone the project with the command `git clone https://gitlab.in2p3.fr/chamont/modernscientificcpp.git`. If you want to get the videos, previously install `git-lfs` on top of `git`.

## Problem: `server certificate verification failed. CAfile: none CRLfile: none`

This problem is rather common. It means your machine is probably not up to date for the package ca-certificates, and lack the recent letsencrypt certficates. Can be solved with something like `apt upgrade ca-certificates` (to be investiogated).

