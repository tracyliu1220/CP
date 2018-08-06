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

#### UVa 11292 - Dragon of Loowater
**AC**
- question:
	- 給dragon's heads的diameters跟knights的heights，一個knight可以打敗
一顆diameters比自己height還小的dragon head，問拿去打敗dragon heads的knights的heights的加總
- greedy
- sort input first
- problems:
	- sort裡面begin()跟end()的vector對象寫錯了

### Excercises

#### UVa 11389 - The Bus Driver Problem
**AC**
- question:
	- 有n個司機，n條morning路線，n條afternoon路線，每個司機可以安排一個morning路線跟一個afternoon路線，但是如果一個司機的總路程超過d的話就要付出（原來路線 - d) * r的代價，求最少代價
- greedy
- 大的配小的
- problems:
	- 輸入的順序看錯了

## 3.5 Dynamic Programming

### Examples

#### UVa 11450 - Wedding Shopping
**AC**
- question:
	- 對於每個case，有C件衣服，預算是M，每件衣服都有多種選擇，每件都要選一種買且不超過預算的情況下，最多能花多少錢
- bottom-up 2D dp
