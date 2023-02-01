#include<bits/stdc++.h>
using namespace std;using x=int;x k[4]={1,-1,0,0},m[4]={0,0,1,-1},i,j,a,u,b,y,p,z;int main(){x 
w=0;for(i=0;i<3;i++){for(j=0;j<3;j++){cin>>a;if(a==0)a=9;w=w*10+a;}}map<x,x>d;d[w]=0;queue<int>q;q.push(w);while(!q.empty()){x t=q.front();q.pop();string 
r=to_string(t);u=r.find('9');b=u/3;y=u%3;for(i=0;i<4;i++){p=b+k[i];z=y+m[i];if(p>=0&&p<3&&z>=0&&z<3){string c=r;swap(c[b*3+y],c[p*3+z]);int 
v=stoi(c);if(d.count(v)==0){d[v]=d[t]+1;q.push(v);}}}}if(d.count(123456789)==0)cout<<-1;else cout<<d[123456789];}
