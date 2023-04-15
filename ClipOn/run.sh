#!/bin/bash
#SBATCH -N 5
#SBATCH -C 1
#SBATCH --mem 10gb
#SBATCH --time 02:00:00

./a.out
