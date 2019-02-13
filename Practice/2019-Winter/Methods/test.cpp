/*
滑動視窗
O(n) 
*/
#include <cstdio>
#include <algorithm>
int a[100010],y,p;
int main(){
  int s,e,cnt,max,ms,me,j;
  while(scanf("%d",&y)==1){
    scanf("%d",&p);
    for(int i=0;i<p;i++){
      scanf("%d",a+i);
    }
    cnt=0;
    max=-1;
    j=0;
    for(int i=0;i<p;i++){//滑動視窗i為開始，j為結束 
      s=a[i];
      e=a[i]+y;//多出了1 
      while((j<p)&&(a[j++]<e)){//找尋大於等於e的最小j，lower_bound 
        cnt++;
      }
      j--;//a[j++]<e，多加了1，減回來 
      if (max<cnt){//是不是個數更多 
        max=cnt;
        ms=s;
        me=a[j-1];
      }
      while(a[i]==a[i+1]) {//將相同的a[i]刪去 
        i++;
        cnt--;
      }
      cnt--;//最後一個a[i]的數值，要刪除 
      if (j>=p) break;//滑動視窗的尾端的j超過p就結束 
    }
    printf("%d %d %d\n",max,ms,me);
  }
}
