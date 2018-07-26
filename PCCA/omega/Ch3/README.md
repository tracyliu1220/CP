# Omegabook Ch3

## 3.2 Complete Search

### 3.2.1 Iterative Comeplete Search

#### UVa 725 - Division
**AC**
- 2 nested loops
- bits mask

#### UVa 441 - Lotto
**AC**
- many nested loops

#### UVa 11565 - Simple Equation
**AC**
- loop

#### UVa 11742 - Social Constraints
**AC**
- permutations
- struct

#### UVa 12455 - Bars
**AC**
- subsets
- DP

### 3.2.2 Recursive Complete Search

#### Uva 00750 - 8 Queens Chess Problem
**AC**
- backtracking

### Excercises

#### UVa 00193 - Graph Coloring
**AC**
- DFS
- backtracking
- can use init func.

## 3.3 Divide & Conquer

### Excercises

#### UVa 11057 - Exact Sum
**AC**
- binary search

#### UVa 10341 - Solve It
**AC**
- binary search through double
- define min as 1e-9
- cout `setprecision(4)` -> 0.09763
	- use `fixed` to fix

#### UVa 11413 - Fill the Containers
**AC**
- binary search
- greedy

## 3.4 Greedy

### Examples

#### UVa 00410 - Station Balance
**AC**
- greedy
- 大的配小的，必要時補0

#### UVa 10382 - Watering Grass
**AC**
- problems
	- x, r要用double(取畢氏會overflow)
- greedy 取當下條件下end最靠右的
