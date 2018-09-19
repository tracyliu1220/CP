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

### Excercises

#### Uva 10684 - The jackpot
**AC**
- question:
	- 給n和n個數字，求連續最大和
- DP: max 1D range sum

#### Uva 00108 - Maximum Sum
**AC**
- question:
	- 求最大加權長方形
- 做前綴壓成一維再做DP

#### Uva 00481 - What Goes Up
**AC**
- LIS (nlogn)

#### Uva 11456 - Trainsorting
**AC**
- question:
	- train中每節car只能以遞減的方式排列，插入方使可(1)從車頭(2)從車尾(3)將car銷毀，問最長能排多少節
- 迴文之後LIS（可以確保每節car的權重都不同）

#### Uva 11790 - Murcia's Skyline
**AC**
- question:
	- 給建築物的高和寬，求遞增和遞減最長寬度
- 帶權重的LIS跟LDS
- 因為帶權重所以不能用單調對列優化
- O(n^2)

#### Uva 10616 - Divisible Group Sums
**AC**
- question:
	- 給N個數字Q筆詢問，問這N個數字中取M個可以組出幾組能被D整除的數字
- 背包問題
- 把數字%D
- `dp[m][j] += dp[m - 1][(j + D - num[i] % D) % D]`
	- m: 放到第幾個
	- j: 當前總和
	- num: 存那N個數字

#### Uva 10819 - Trouble of 13-Dots
**AC**
- question:
	- 給預算價錢跟喜好度，問預算內能達到最高的喜好度，注意預算有範圍變化
- 帶權的背包，最後從頭到尾跑max值

#### Uva 00357 - Let Me Count The Ways
**AC**
- question:
	- 問幣值有多少種換錢方式
- dp問累加方法數

#### Uva 10306 - e-Coins
**AC**
- question:
	- 給很多向量x跟y，求成落點在圓心(0,0)，r=S上的最少向量組合數
- dp二維取min

